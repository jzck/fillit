#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*a;
	size_t	i;

	i = -1;
	a = (unsigned char *)s;
	while (++i < n)
	{
		if (*(unsigned char *)a == (unsigned char)c)
			return (a);
		a++;
	}
	return (NULL);
}
