/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:36:27 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 10:54:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solved(char **board)
{
	ft_board_remove(board, "^*");
	ft_sstrfree(g_sol);
	g_sol = ft_board_copy(board);
	return (1);
}

int		ft_solver(char **board, t_list *lttmn, int space, int size)
{
	int		i;
	t_ttmn	*ttmn;

	if (!lttmn)
		return (ft_solved(board));
	ttmn = (t_ttmn *)lttmn->content;
	if (ttmn->placed)
		return (ft_solver(board, lttmn->next, space, size));
	i = -1;
	while (++i < size * size)
	{
		if (ft_board_add(board, *ttmn, i, size))
			continue ;
		if (ft_check_waste(board, lttmn->next, space, size))
			return (1);
		ft_board_remove(board, &ttmn->id);
	}
	return (0);
}
