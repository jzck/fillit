#include "fillit.h"

t_list	*ft_empty_here(char **board, int size, int i)
{
	t_list	*blob;

	blob = NULL;
	if (board[i / size][i % size] == '.')
	{
		board[i / size][i % size] = '*';
		blob = ft_empty_around(board, size, i);
		ft_lstadd(&blob, ft_lstnew(&i, sizeof(int)));
	}
	/* printf("list at %i: ", i); */
	/* fflush(stdout); */
	/* ft_lst_print(blob, &ft_putnbr); */
	return (blob);
}

t_list	*ft_empty_around(char **board, int size, int i)
{
	t_list	*add;

	add = NULL;
	i % size < size - 1 ? ft_lsteadd(&add, ft_empty_here(board, size, i + 1)) : 0;
	i / size > 0 ? ft_lsteadd(&add, ft_empty_here(board, size, i - size)) : 0;
	i % size > 0 ? ft_lsteadd(&add, ft_empty_here(board, size, i - 1)) : 0;
	i / size < size - 1 ? ft_lsteadd(&add, ft_empty_here(board, size, i + size)) : 0;
	/* ft_lst_print(add, &ft_putnbr); */
	return (add);
}

int		ft_empty_here2(char **board, int size, int i)
{
	int		n;

	n = 0;
	if (board[i / size][i % size] == '.')
	{
		board[i / size][i % size] = '*';
		n++;
		n += ft_empty_around2(board, size, i);
	}
	/* printf("list at %i: ", i); */
	/* fflush(stdout); */
	/* ft_lst_print(blob, &ft_putnbr); */
	return (n);
}

int		ft_empty_around2(char **board, int size, int i)
{
	int		n;

	n = 0;
	n += i % size < size - 1 ? ft_empty_here2(board, size, i + 1) : 0;
	n += i / size > 0 ? ft_empty_here2(board, size, i - size) : 0;
	n += i % size > 0 ? ft_empty_here2(board, size, i - 1) : 0;
	n += i / size < size - 1 ? ft_empty_here2(board, size, i + size) : 0;
	/* ft_lst_print(add, &ft_putnbr); */
	return (n);
}
