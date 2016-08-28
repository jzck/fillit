#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	dup = (char*)malloc(sizeof(*dup) * (size + 1));
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
