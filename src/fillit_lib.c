#include "fillit.h"

char	**ft_copy_board(char **board)
{
	size_t	size;
	char	**copy;

	size = ft_strlen(*board);
	copy = ft_empty_board(size);
	ft_fill_board(copy, board);
	return (copy);
}

void	ft_fill_board(char **dst, char **src)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

char	**ft_empty_board(size_t size)
{
	char	**board;
	int		i;
	int		j;

	board = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < (int)size)
	{
		board[i] = ft_strnew(size);
		j = -1;
		while (++j < (int)size)
			board[i][j] = '.';
	}
	board[i] = NULL;
	return (board);
}

void	ft_free_board(char ***board)
{
	int		i;

	i = 0;
	while ((*board)[i])
	{
		free((*board)[i]);
		i++;
	}
	free(*board);
	*board = NULL;
}

void	ft_grow_board(char **board)
{
	int	i;
	int	size;

	size = ft_strlen(*board);
	i = 0;
	while (++i <= size)
	{
		board[i][size] = '.';
		board[size][i] = '.';
	}
}

void	ft_shrink_board(char **board)
{
	int	i;
	int	size;

	size = ft_strlen(*board);
	i = -1;
	while (++i < size)
	{
		board[i][size - 1] = '\0';
		board[size - 1][i] = '\0';
	}
}

void	ft_takeoff_board(char **board, char c)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if (board[i][j] == c)
				board[i][j] = '.';
		}
	}
}

int		ft_addto_board(char **board, t_ttmn block, size_t i, size_t j)
{
	int		x;
	int		y;
	size_t	k;
	int		size;

	size = ft_strlen(*board);
	k = 0;
	if (block.id)
		while (k < 4)
		{
			x = (int)j + block.pos[k][1];
			y = (int)i + block.pos[k][0];
			/* printf("adding %c to %i,%i\n", block.id, y, x); */
			/* fflush(stdout); */
			if (x > size - 1 || y > size - 1 || x < 0 || y < 0)
				return (1);
			if (board[y][x] != '.')
				return (1);
			board[y][x] = block.id;
			/* ft_show_board(board); */
			k++;
		}
	return (0);
}
