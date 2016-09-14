#include "fillit.h"

int		ft_flood_fill(char **board, int size, int i, char c)
{
	int		n;

	n = 0;
	if (board[i / size][i % size] == '.')
	{
		board[i / size][i % size] = c;
		n++;
		n += i % size < size - 1 ?  ft_flood_fill(board, size, i + 1, c) : 0;
		n += i / size > 0 ? ft_flood_fill(board, size, i - size, c) : 0;
		n += i % size > 0 ? ft_flood_fill(board, size, i - 1, c) : 0;
		n += i / size < size - 1 ? ft_flood_fill(board, size, i + size, c) : 0;
	}
	/* printf("list at %i: ", i); */
	/* fflush(stdout); */
	/* ft_lst_print(blob, &ft_putnbr); */
	return (n);
}
