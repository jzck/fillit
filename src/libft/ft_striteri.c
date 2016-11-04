/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 19:29:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	size;
	size_t	i;

	if (!s || !f || !*f)
		return ;
	size = ft_strlen(s);
	i = -1;
	while (++i < size && *(s + i))
		(*f)(i, s + i);
}
