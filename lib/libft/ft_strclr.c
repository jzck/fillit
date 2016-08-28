#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = -1;
	while (++i < size)
		s[i] = 0;
}
