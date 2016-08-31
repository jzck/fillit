#include "fillit.h"

int		ft_waste_here(char ***board_ptr, int i, int j)
{
	int		n;

	n = 0;
	if (board_ptr[0][i][j] == '.')
	{
		board_ptr[0][i][j] = '*';
		n++;
		n += ft_waste_around(board_ptr, i, j);
	}
	return (n);
}

int		ft_waste_around(char ***board_ptr, int i, int j)
{
	size_t	size;
	size_t	n;

	size = ft_strlen(**board_ptr);
	n = 0;
	n += i > 0 ? ft_waste_here(board_ptr, i - 1, j) : 0;
	n += j > 0 ? ft_waste_here(board_ptr, i, j - 1) : 0;
	n += i < (int)size - 1 ? ft_waste_here(board_ptr, i + 1, j) : 0;
	n += j < (int)size - 1 ? ft_waste_here(board_ptr, i, j + 1) : 0;
	/* printf("waste around %i,%i = %zu\n", i, j, n); */
	return (n);
}

int		ft_validate_waste(char **board, t_ttmn *ttmn)
{
	int		max_waste;
	int		waste;
	int		i;
	int		j;
	int		l;
	int		blob;
	size_t	size;

	max_waste = g_target * g_target - g_ttmn * 4;
	waste = 0;
	size = ft_strlen(*board);
	i = -1;
	/* ft_show_board(board); */
	while (++i < (int)size)
	{
		j = -1;
		while (++j < (int)size)
		{
			blob = ft_waste_here(&board, i, j);
			if (blob / 4 == 1)
			{
				waste += 4;
				l = -1;
				/* ft_show_board(board); */
				while (ttmn[++l].id)
				{
					/* ft_show_ttmn(ttmn[l]); */
					/* printf("checking at %i,%i = %i vs %i\n", i, j, ft_check_pos(board, ttmn[l], i, j), (int)size); */
					fflush(stdout);
					if (ft_check_pos(board, ttmn[l], i, j) == (int)size)
					{
						waste -= 4;
						break ;
					}
				}
			}
			waste += blob % 4;
			if (waste > max_waste)
			{
				/* printf("waste = %i (failed: max = %i)\n", waste, max_waste); */
				/* fflush(stdout); */
				return (0);
			}
		}
	}
	/* printf("waste = %i (passed: max = %i)\n", waste, max_waste); */
	/* fflush(stdout); */
	return(1);
}
