#include "libft.h"

int		ft_isalnum(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if ((a >= 'a' && a <= 'z')
			|| (a >= 'A' && a <= 'Z')
			|| (a >= '0' && a <= '9'))
		return (a);
	return (0);
}
