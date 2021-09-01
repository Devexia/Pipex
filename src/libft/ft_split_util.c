/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 04:48:24 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/27 04:48:25 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_fill_norm(char const *s, char **split, size_t wordlen)
{
	if (wordlen)
	{
		*split = ft_strndup(s - wordlen, wordlen, split);
		if (!(*split))
			return (0);
	}
	return (1);
}
