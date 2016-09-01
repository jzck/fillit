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
	return (n);
}

int		ft_additional_waste(char **board, t_ttmn *ttmn, int i, int j)
{
	int	y;
	int	x;
	int	l;
	int	size;

	/* ft_show_board(board); */
	y = i - 1;
	x = j - 1;
	size = ft_strlen(*board);
	while (++y < size)
	{
		x = (x == size ? -1 : x);
		while (++x < size);
		{
			l = -1;
			while (ttmn[++l].id)
				if (!ft_board_add(board, ttmn[l], i, j))
					return (0);
		}
	}
	return (1);
}

int		ft_validate_waste(char **board, t_ttmn *ttmn, int max_waste)
{
	int	waste;
	int	i;
	int	j;
	int	blob;
	int	size;

	board = ft_copy_board(board);
	waste = 0;
	size = ft_strlen(*board);
	i = -1;
	/* ft_show_board(board); */
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			blob = ft_waste_here(&board, i, j);
			/* if (blob / 4 == 1) */
			/* 	waste += ft_additional_waste(board, ttmn, i, j); */
			waste += blob % 4;
			if (waste > max_waste)
			{
				return (0);
			}
		}
	}
	return(1);
}
