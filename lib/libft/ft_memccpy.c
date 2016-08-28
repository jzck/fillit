#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		*(char *)dst++ = *(char *)src;
		if (*(char *)src++ == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
