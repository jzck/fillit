#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = -1;
	while (++i < size)
		(*f)(s + i);
}
