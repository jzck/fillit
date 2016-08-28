#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && (dst + i < src || dst + i > src + len))
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
