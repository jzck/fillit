#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	size_t	size;

	out = ft_strdup(s);
	while (*out && SEP(*out))
		out++;
	size = ft_strlen(out);
	while (size - 1 && SEP(out[size - 1]))
	{
		size--;
		out[size] = '\0';
	}
	return (out);
}
