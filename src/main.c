#include "fillit.h"

size_t	g_size = 20;

void	ft_usage(void)
{
	ft_putendl("error");
}

int		ft_check_pos(char **board, t_ttmn block, size_t i, size_t j)
{
	size_t	size;
	size_t	k;

	size = 0;
	if (board)
		size = ft_strlen(*board);
	k = -1;
	while (++k < 3)
	{
		if (i + block.pos[k][0] >= size || j + block.pos[k][1] >= size)
			continue ;
		if (board[i + block.pos[k][0]][j + block.pos[k][1]] != '.')
			return (0);
	}
	return (1);
}

void	ft_grow_board(char ***board_ptr)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	**new_board;
	char	**board;

	board = *board_ptr;
	size = board ? ft_strlen(*board) : 0;
	new_board = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
	{
		new_board[i] = ft_strjoin(board[i], ".");
		free(board[i]);
	}
	j = -1;
	new_board[i] = (char *)malloc(sizeof(char) * (size + 1));
	while (++j < size + 1)
	{
		new_board[i][j] = '.';
	}
	free(*board_ptr);
	*board_ptr = new_board;
}

char	**ft_next_board(char **board, t_ttmn block, size_t i, size_t j)
{
	size_t	size;
	size_t	k;
	char	**new_board;

	size = board ? ft_strlen(*board) : 0;
	new_board = size ? (char **)malloc(sizeof(char *) * size) : NULL;
	k = -1;
	while (++k < size)
		new_board[k] = ft_strdup(board[k]);
	k = 0;
	while (k < 4)
	{
		if (i + block.pos[k][0] >= size || j + block.pos[k][1] >= size)
		{
			ft_grow_board(&new_board);
			size++;
			continue ;
		}
		new_board[i + block.pos[k][0]][j + block.pos[k][1]] = block.id;
		k++;
	}
	return (new_board);
}

int		ft_solver(char **board, t_ttmn *ttmn)
{
	size_t	i;
	size_t	j;
	char	**new_board;

	ft_show_ttmn(*ttmn);
	ft_show_board(board);
	if (!(*ttmn).id)
	{
		g_size = ft_strlen(*board);
		printf("new solution : size = %zu\n", g_size);
		return(0);
	}
	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j <= i)
		{
			printf("trying: %zu,%zu\n", i, j);
			if (ft_check_pos(board, *ttmn, i, j))
			{
				printf("pos ok : %zu,%zu\n", i, j);
				new_board = ft_next_board(board, *ttmn, i, j);
				if (ft_solver(new_board, ttmn + 1))
					return (1);
				free(new_board);
			}
			if (j != i && ft_check_pos(board, *ttmn, j, i))
			{
				printf("pos ok : %zu,%zu\n", j, i);
				new_board = ft_next_board(board, *ttmn, j, i);
				if (ft_solver(new_board, ttmn + 1))
					return (1);
				free(new_board);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_ttmn	*ttmn;

	if (ac != 2 || !(ttmn = ft_get_ttmn(av[1])))
	{
		ft_usage();
		return (1);
	}
	/* int l = -1; */
	/* while (ttmn[++l].id) */
	/* 	ft_show_ttmn(ttmn[l]); */
	ft_solver(NULL, ttmn);
	return (0);
}
