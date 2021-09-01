#include "libft.h"

char	*ft_strndup(char *src, size_t size)
{
	char	*dst;
	size_t	i;

	if (!src)
		return (NULL);
	dst = (char *)ft_calloc(sizeof(char), (size + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
