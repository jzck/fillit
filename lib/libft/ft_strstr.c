/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:48:35 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/09 13:53:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	char	*a;

	a = (char *)big;
	i = 0;
	while (a[i] != '\0')
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
	return (0);
}
