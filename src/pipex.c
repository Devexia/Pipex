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

int	pipex_cleanup(t_data *data, char **path)
{
	int	i;

	i = 0;
	if (path)
		free_chartab(path);
	if (data[0].cmd)
		free_chartab(data[0].cmd);
	if (data[1].cmd)
		free_chartab(data[1].cmd);
	while (i++ < 2)
		if (data[i].fd > 0)
			close(data[i].fd);
	free(data);
	return (EXIT_FAILURE);
}

int	init_pipe(int *fd)
{
	if (pipe(fd) < 0)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	exec_cmd(t_data *data, t_pipe pipe, char **envp, int index)
{
	char	*buf;
	char	*tmp;

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
	close(pipe.pipe[0]);
	close(pipe.pipe[1]);
	close(data[0].fd);
	close(data[1].fd);
	buf = ft_strdup(data[index].cmd[0]);
	while (pipe.path++)
	{
		tmp = ft_strjoin(ft_strjoin(*pipe.path, "/"), buf);
		execve(tmp, &data[index].cmd[0], envp);
	}
	perror(data[index].cmd[0]);
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
	{
		printf("error");
		free(data);
		return (EXIT_FAILURE);
	}
	if (init_pipe(pipe.pipe) < 0)
		return (pipex_cleanup(data, pipe.path));
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (pipex_cleanup(data, pipe.path));
	}
	pipex_exec(pid, data, pipe, envp);
	return (EXIT_SUCCESS);
}
