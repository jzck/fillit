#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = -1;
	while (++i < size)
		(*f)(i, s + i);
}
