/*
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
*/
