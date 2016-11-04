/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:26:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 17:29:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_floodfill_recursive(char **board, int size, int i, char c)
{
	int		n;

	n = 0;
	if (board[i / size][i % size] == '.')
	{
		board[i / size][i % size] = c;
		n++;
		n += i % size < size - 1 ?
			ft_floodfill_recursive(board, size, i + 1, c) : 0;
		n += i / size > 0 ?
			ft_floodfill_recursive(board, size, i - size, c) : 0;
		n += i % size > 0 ?
			ft_floodfill_recursive(board, size, i - 1, c) : 0;
		n += i / size < size - 1 ?
			ft_floodfill_recursive(board, size, i + size, c) : 0;
	}
	return (n);
}
