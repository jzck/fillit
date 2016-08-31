#include "fillit.h"

int		ft_check_pos(char **board, t_ttmn block, int i, int j)
{
	size_t	k;
	int		new_size;
	int		size;
	int		x;
	int		y;

	size = ft_strlen(*board);
	new_size = size;
	k = -1;
	while (++k < 4)
	{
		x = (int)j + block.pos[k][1];
		y = (int)i + block.pos[k][0];
		/* if (block.id == 'L') */
		/* 	printf("trying %i, %i\n", y, x); */
		if (x < 0 || x < 0)
			return (100);
		if (x > size - 1 || y > size - 1)
		{
			new_size = MAX(new_size, MAX(x + 1, y + 1));
			continue ;
		}
		if (board[y][x] != '.' && board[y][x] != '*')
			return (100);
	}
	return (new_size);
}

int		ft_solver(char **board, t_ttmn *ttmn)
{
	int		i;
	int		j;
	int		size;

	/* ft_show_board(board); */
	size = ft_strlen(*board);
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
			if (size == (int)g_target && !ft_validate_waste(board, ttmn + 1))
				;
			else if (ft_solver(board, ttmn + 1))
				return (1);
			ft_board_remove(board, ttmn->id);
		}
	}
	return (0);
}
