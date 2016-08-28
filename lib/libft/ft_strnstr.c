#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*a;

	a = (char *)big;
	i = 0;
	while (a[i] != '\0' && i < len)
	{
		j = 0;
		while (a[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return (a + i);
		}
		i++;
	}
	return (NULL);
}
