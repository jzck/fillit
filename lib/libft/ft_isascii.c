#include "libft.h"

int		ft_isascii(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if (a >= 0 && a <= 127)
		return (a);
	return (0);
}
