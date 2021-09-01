/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:46:14 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/27 04:46:17 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	if (s[i] != c && s[i])
		wcount++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i + 1] != '\0')
				i++;
			if (s[i] != c && s[i])
				wcount++;
			if (s[i - 1] != c && s[i] == 0)
				wcount++;
		}
		i++;
	}
	return (wcount);
}

void	*free_my_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return (NULL);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	*ft_strndup(char const *s, size_t n, char **split)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (len < n && s[len])
		len++;
	dup = ft_calloc((len + 1), sizeof(char));
	if (!dup)
	{
		free_my_split(split);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

int	ft_split_fill(char const *s, char c, char **split)
{
	size_t	wordlen;
	size_t	i;

	i = 0;
	wordlen = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (wordlen)
			{
				*split = ft_strndup(s - wordlen, wordlen, split);
				if (!(*split))
					return (0);
				split++;
			}
			wordlen = 0;
		}
		else
			wordlen++;
		s++;
	}
	if (split_fill_norm(s, split, wordlen) == 0)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	split_size;

	if (!s)
		return (NULL);
	split_size = ft_word_count(s, c);
	split = ft_calloc(split_size + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if ((ft_split_fill(s, c, split)) == 0)
		return (NULL);
	split[split_size] = NULL;
	return (split);
}
