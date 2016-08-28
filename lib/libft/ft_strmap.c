#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*out;

	size = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (size + 1));
	if (out == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		out[i] = (*f)(s[i]);
	return (out);
}
