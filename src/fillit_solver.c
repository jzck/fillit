#include "fillit.h"

int		ft_solver(char **board, t_ttmn *ttmn)
{
	int		i;
	int		j;
	int		size;
	int		max_waste;

	/* ft_show_board(board); */
	size = ft_strlen(*board);
	max_waste = size * size - 4 * g_ttmn;
	if (!(*ttmn).id)
	{
		printf("new solution : size %i\n", size);
		g_sol = ft_copy_board(board);
		return (1);
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (ft_board_add(board, *ttmn, i, j))
				continue ;
			if (!ft_validate_waste(board, ttmn + 1, max_waste))
				;
			else if (ft_solver(board, ttmn + 1))
				return (1);
			ft_board_remove(board, ttmn->id);
		}
	}
	return (0);
}
