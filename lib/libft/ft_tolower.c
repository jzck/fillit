#include "libft.h"

int		ft_toupper(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if (a >= 'A' && a <= 'Z')
		return (a + 32);
	return (a);
}
