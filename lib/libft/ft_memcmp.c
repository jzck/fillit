#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	while (++i < n)
	{
		cmp = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (cmp)
			return (cmp);
	}
	return (cmp);
}
