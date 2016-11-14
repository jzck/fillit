/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:01:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 10:38:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sstrfree(char **sstr)
{
	int		i;

	i = 0;
	if (sstr)
	{
		while (sstr[i])
		{
			ft_strdel(sstr + i);
			i++;
		}
		ft_strdel(sstr + i);
	}
	free(sstr);
}
