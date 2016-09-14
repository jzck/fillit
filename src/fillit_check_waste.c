#include "fillit.h"

int		ft_check_waste(char **board, t_list *lttmn, int space, int size)
{
	t_ttmn	*ttmn;
	int		i;
	int		blob_size;

	if (!lttmn)
		return (ft_solved(board));
	ttmn = (t_ttmn *)lttmn->content;
	if (ttmn->placed)
		return (ft_solver(board, lttmn->next, space, size));
	space = size * size - 4 * g_ttmn;
	i = -1;
	while (++i < size * size)
	{
		if (board[i / size][i % size] != '.')
			continue ;
		ft_board_replace(board, '*', '^');
		blob_size = ft_flood_fill(board, size, i, '*');
		space -= blob_size % 4;

		if (space < 0)
		{
			ft_board_remove(board, '^');
			ft_board_remove(board, '*');
			return (0);
		}
		if (blob_size / 4 == 1)
		{
			if (ft_fit_blob(board, lttmn, space, size, blob_size, i))
				return (1);
			space -= 4;
			if (space < 0)
			{
				ft_board_remove(board, '^');
				ft_board_remove(board, '*');
				return (0);
			}
		}
	}
	ft_board_remove(board, '^');
	ft_board_remove(board, '*');
	return (ft_solver(board, lttmn, space, size));
}
