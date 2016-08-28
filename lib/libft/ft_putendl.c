#include "libft.h"

void	ft_putendl(char const *s)
{
	char	nl;

	nl = '\n';
	write(1, s, ft_strlen(s));
	write(1, &nl, 1);
}
