/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:36:33 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/27 05:02:47 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_pipe(int *fd)
{
	if (pipe(fd) < 0)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	try_exec(t_data *data, t_pipe pipe, char **envp, int index)
{
	char	*buf;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	buf = ft_strdup(data[index].cmd[0]);
	while (pipe.path[i++])
	{
		tmp2 = ft_strjoin(pipe.path[i], "/");
		tmp = ft_strjoin(tmp2, buf);
		execve(tmp, &data[index].cmd[0], envp);
		free(tmp);
		free(tmp2);
	}
	free(buf);
	perror(data[index].cmd[0]);
}

void	exec_cmd(t_data *data, t_pipe pipe, char **envp, int index)
{
	if (index == 1)
	{
		dup2(pipe.pipe[0], 0);
		dup2(data[index].fd, 1);
	}
	else
	{
		dup2(data[index].fd, 0);
		dup2(pipe.pipe[1], 1);
	}
	close_fd(data, pipe);
	try_exec(data, pipe, envp, index);
}

void	pipex_exec(int pid, t_data *data, t_pipe pipe, char **envp)
{
	int	*status;

	status = NULL;
	if (pid == 0)
		exec_cmd(data, pipe, envp, 0);
	else
		exec_cmd(data, pipe, envp, 1);
	close(pipe.pipe[0]);
	close(pipe.pipe[1]);
	wait(status);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	t_pipe	pipe;
	int		pid;

	data = malloc(sizeof(t_data) * 2);
	if (!data)
		return (EXIT_FAILURE);
	init_data(data);
	pipe.path = pipex_parser(data, argc, argv, envp);
	if (pipe.path == NULL)
		return (EXIT_FAILURE);
	if (init_pipe(pipe.pipe) < 0)
		return (pipex_cleanup(data, pipe.path));
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (pipex_cleanup(data, pipe.path));
	}
	pipex_exec(pid, data, pipe, envp);
	pipex_cleanup(data, pipe.path);
	return (EXIT_FAILURE);
}
