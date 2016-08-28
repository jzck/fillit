#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}
