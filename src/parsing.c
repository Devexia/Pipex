/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:36:30 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/27 05:02:46 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_data *data)
{
		data[0].fd = -1;
		data[0].fd = -1;
		data[0].cmd = 0;
		data[1].fd = -1;
		data[1].fd = -1;
		data[1].cmd = 0;
}

void	free_chartab(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	path = 0;
}

int	open_file(const char *path, int flags, int rights)
{
	int	fd;

	fd = open(path, flags, rights);
	if (fd < 0)
		perror(path);
	if (read(fd, NULL, 0) < 0)
	{
		perror(path);
		close(fd);
		fd = -1;
	}
	return (fd);
}

char	**pipex_parser(t_data *data, int argc, char **argv, char **envp)
{
	char	**path;

	if (argc != 5)
	{
		write(1, "usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 46);
		return (NULL);
	}
	path = NULL;
	while (envp++)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = ft_split((*envp + 5), ':');
			break ;
		}
	}
	data[0].fd = open_file(argv[1], O_RDONLY, 0);
	data[1].fd = open_file(argv[4], O_RDWR | O_CREAT | O_TRUNC, 420);
	data[0].cmd = ft_split(argv[2], ' ');
	data[1].cmd = ft_split(argv[3], ' ');
	if (data[0].fd < 0 || data[1].fd < 0 || !data[0].cmd[0] || !data[1].cmd[0])
	{
		pipex_cleanup(data, path);
		return(NULL);
	}
	return (path);
}