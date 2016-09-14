#include "fillit.h"

int		ft_fit_blob(char **board, t_list *lttmn, int space, int size, int blob_size, int y)
{
	t_ttmn	*ttmn;
	t_list	*list;
	int		i;
	int		n;

	n = blob_size;
	i = y - 1;
	while (++i < size * size)
	{
		if (board[i / size][i % size] == '*')
		{
			n--;
			list = lttmn;
			while (list)
			{
				ttmn = (t_ttmn *)list->content;
				list = list->next;
				if (ttmn->placed || ft_board_add(board, *ttmn, i, size))
					continue ;
				ttmn->placed = 1;
				/* ft_board_print(board); */
				if (ft_solver(board, lttmn, space, size))
					return (1);
				ft_board_replace(board, ttmn->id, '*');
				ttmn->placed = 0;
			}
		}
		if (n < 4)
			return (0);
	}
	return (0);
}
