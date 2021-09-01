/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:49:55 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/27 04:49:56 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define BUFFER_SIZE 42

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

char			**ft_split(char const *s, char c);
char			**ft_free_split(char **str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_bzero(void *s, size_t n);
unsigned int	ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strndup(char *src, size_t size);

#endif
