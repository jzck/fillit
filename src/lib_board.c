#include "fillit.h"

void	ft_board_print(char **board)
{
	/* ft_putendl("-s-"); */
	while (*board)
		ft_putendl(*board++);
	ft_putendl("");
}

char	**ft_board_init(size_t size)
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

char	**ft_board_copy(char **board)
{
	size_t	size;
	char	**copy;

	size = ft_strlen(*board);
	copy = ft_board_init(size);
	ft_board_fill(copy, board);
	return (copy);
}

void	ft_board_fill(char **dst, char **src)
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

void	ft_board_free(char ***board)
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

void	ft_board_replace(char **board, char a, char b)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if (board[i][j] == a)
				board[i][j] = b;
		}
	}
}

void	ft_board_remove(char **board, char c)
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

int		ft_board_add(char **board, t_ttmn ttmn, int i, int size)
{
	int		x;
	int		y;
	int		k;

	k = 0;
	while (k < 4)
	{
		x = i % size + ttmn.pos[k][1];
		y = i / size + ttmn.pos[k][0];
		/* printf("adding %c to %i,%i\n", block.id, y, x); */
		/* fflush(stdout); */
		if (x > size - 1 || y > size - 1 || x < 0 || y < 0)
			return (1);
		if (board[y][x] != '.' && board[y][x] != '*')
			return (1);
		k++;
	}
	k = 0;
	while (k < 4)
	{
		x = i % size + ttmn.pos[k][1];
		y = i / size + ttmn.pos[k][0];
		board[y][x] = ttmn.id;
		/* ft_show_board(board); */
		k++;
	}
	return (0);
}
