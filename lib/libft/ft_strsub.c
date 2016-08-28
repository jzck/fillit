#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len)
		out[i] = s[i + start];
	out[i] = '\0';
	return (out);
}
