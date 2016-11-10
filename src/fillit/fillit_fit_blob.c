/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_fit_blob.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:39:49 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/08 16:59:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fit_blob(
		char **board,
		t_list *lttmn,
		int space,
		int size)
{
	t_ttmn	*ttmn;
	t_list	*list;
	int		i;

	i = -1;
	while (++i < size * size)
	{
		if (board[i / size][i % size] == '*')
		{
			list = lttmn;
			while (list)
			{
				ttmn = (t_ttmn *)list->content;
				list = list->next;
				if (ttmn->placed || ft_board_add(board, *ttmn, i, size))
					continue ;
				ttmn->placed = 1;
				if (ft_solver(board, lttmn, space, size))
					return (1);
				ft_board_replace(board, ttmn->id, '*');
				ttmn->placed = 0;
			}
		}
	}
	return (0);
}
