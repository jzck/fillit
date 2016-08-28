#include "libft.h"

int		ft_isprint(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if (a >= 32 && a <= 126)
		return (a);
	return (0);
}
