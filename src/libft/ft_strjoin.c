/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:46:47 by mleonars          #+#    #+#             */
/*   Updated: 2021/08/27 02:46:57 by mleonars         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*joined;

	i = -1;
	n = -1;
	if (!s1 || !s2)
		return (NULL);
	joined = ft_calloc((ft_strlen(s1) \
		+ ft_strlen(s2) + 1), sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[++n])
	{
		joined[i] = s2[n];
		i++;
	}
	return (joined);
}
