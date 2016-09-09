#include "fillit.h"

t_list	*ft_empty_here(char **board, t_list **amap, int size, int i)
{
	t_list	*blob;

	blob = NULL;
	if (board[i / size][i % size] == '.')
	{
		board[i / size][i % size] = '*';
		/* ft_lst_print(*amap, &ft_putnbr); */
		/* printf("removing %i from map\n", i); */
		/* ft_lst_print(*amap, &ft_putnbr); */
		ft_lst_remove_if(amap, &i, &ft_diff);
		blob = ft_empty_around(board, amap, size, i);
		ft_lst_sorted_insert(&blob, ft_lstnew(&i, sizeof(int)), &ft_diff);
	}
	/* printf("list at %i: ", i); */
	/* fflush(stdout); */
	/* ft_lst_print(blob, &ft_putnbr); */
	return (blob);
}

t_list	*ft_empty_around(char **board, t_list **amap, int size, int i)
{
	t_list	*add;

	add = NULL;
	i % size < size - 1 ? ft_lst_sorted_merge(&add, ft_empty_here(board, amap, size, i + 1), &ft_diff) : 0;
	i / size > 0 ? ft_lst_sorted_merge(&add, ft_empty_here(board, amap, size, i - size), &ft_diff) : 0;
	i % size > 0 ? ft_lst_sorted_merge(&add, ft_empty_here(board, amap, size, i - 1), &ft_diff) : 0;
	i / size < size - 1 ? ft_lst_sorted_merge(&add, ft_empty_here(board, amap, size, i + size), &ft_diff) : 0;
	/* ft_lst_print(add, &ft_putnbr); */
	return (add);
}
