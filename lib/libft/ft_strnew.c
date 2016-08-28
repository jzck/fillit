#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*addr;
	size_t	i;

	addr = (char *)malloc(size + 1);
	if (addr == NULL)
		return (NULL);
	i = -1;
	while (++i <= size)
		addr[i] = '\0';
	return (addr);
}
