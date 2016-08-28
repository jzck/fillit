#include "libft.h"

static char		*ft_strrev(char *str)
{
	int		len;
	char	tmp;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		tmp = str[len - (i + 1)];
		str[len - (i + 1)] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}

static size_t	ft_size(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(ft_size(n) + 1);
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (n)
	{
		str[i++] = ABS(n % 10) + '0';
		n /= 10;
	}
	if (NEG(n))
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
