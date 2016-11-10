/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_check_waste.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:24:35 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 17:27:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_waste_loop(char **board, t_list *lttmn, int space, int size)
{
	int		blob_size;
	int		i;

	i = -1;
	while (++i < size * size)
	{
		if (board[i / size][i % size] != '.')
			continue ;
		ft_board_replace(board, '*', '^');
		blob_size = ft_floodfill_recursive(board, size, i, '*');
		space -= blob_size % 4;
		if (space < 0)
			return (0);
		if (blob_size / 4 == 1)
		{
			if (ft_fit_blob(board, lttmn, space, size))
				return (1);
			space -= 4;
			if (space < 0)
				return (0);
		}
	}
	return (2);
}

int			ft_check_waste(char **board, t_list *lttmn, int space, int size)
{
	int		loop_ret;

	if (!lttmn)
		return (ft_solved(board));
	if (((t_ttmn*)lttmn->content)->placed)
		return (ft_solver(board, lttmn->next, space, size));
	if ((loop_ret = ft_waste_loop(board, lttmn, space, size)) < 2)
	{
		if (loop_ret == 0)
			ft_board_remove(board, "^*");
		return (loop_ret);
	}
	ft_board_remove(board, "^*");
	return (ft_solver(board, lttmn, space, size));
}
