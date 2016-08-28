#include "libft.h"

int		ft_isalpha(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (a);
	return (0);
}
