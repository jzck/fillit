#include "libft.h"

char	*strrchr(const char *s, int c)
{
	char	*a;
	size_t	i;
	size_t	len;

	a = (char *)s;
	len = ft_strlen(a);
	i = 0;
	while (i <= len)
	{
		if (a[len - i] == (char)c)
			return (a);
		i++;
	}
	return (NULL);
}
