#include "libft.h"

int		ft_isdigit(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if (a >= '0' && a <= '9')
		return (a);
	return (0);
}
