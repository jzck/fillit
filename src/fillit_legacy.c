/* void	ft_grow_board(char **board) */
/* { */
/* 	int	i; */
/* 	int	size; */

/* 	size = ft_strlen(*board); */
/* 	i = 0; */
/* 	while (++i <= size) */
/* 	{ */
/* 		board[i][size] = '.'; */
/* 		board[size][i] = '.'; */
/* 	} */
/* } */

/* void	ft_shrink_board(char **board) */
/* { */
/* 	int	i; */
/* 	int	size; */

/* 	size = ft_strlen(*board); */
/* 	i = -1; */
/* 	while (++i < size) */
/* 	{ */
/* 		board[i][size - 1] = '\0'; */
/* 		board[size - 1][i] = '\0'; */
/* 	} */
/* } */

/* int		ft_test_fit(char **board, t_ttmn block, int i, int j) */
/* { */
/* 	size_t	k; */
/* 	int		new_size; */
/* 	int		size; */
/* 	int		x; */
/* 	int		y; */

/* 	size = ft_strlen(*board); */
/* 	new_size = size; */
/* 	k = -1; */
/* 	while (++k < 4) */
/* 	{ */
/* 		x = (int)j + block.pos[k][1]; */
/* 		y = (int)i + block.pos[k][0]; */
/* 		if (x < 0 || x < 0) */
/* 			return (0); */
/* 		if (x > size - 1 || y > size - 1) */
/* 		{ */
/* 			new_size = MAX(new_size, MAX(x + 1, y + 1)); */
/* 			continue ; */
/* 		} */
/* 		if (board[y][x] != '.' && board[y][x] != '*') */
/* 			return (0); */
/* 	} */
/* 	return (0); */
/* } */
