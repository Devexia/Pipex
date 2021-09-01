/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:37:29 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/27 05:02:46 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**cmd;
	int		fd;
	int		i_of_shame;
}			t_data;

typedef struct s_pipe
{
	char	**path;
	int		pipe[2];
}			t_pipe;

char	**pipex_parser(t_data *data, int argc, char **argv, char **envp);
void	init_data(t_data *data);
void	free_chartab(char **path);
int	pipex_cleanup(t_data *data, char **path);

#endif
