#include "fillit.h"

int		ft_solved(char **board)
{
	ft_putendl("found solution:");

	ft_board_remove(board, '^');
	ft_board_remove(board, '*');
	g_sol = ft_board_copy(board);
	ft_board_print(board);
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
	/* ft_board_print(board); */
	i = -1;
	while (++i < size * size)
	{
		if (ft_board_add(board, *ttmn, i, size))
			continue ;
		/* if (ft_solver(board, lttmn->next, space, size)) */
		/* 	return (1); */
		if (ft_check_waste(board, lttmn->next, space, size))
			return (1);

		ft_board_remove(board, ttmn->id);
	}
	return (0);
}
