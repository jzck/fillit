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

int		ft_empty_here2(t_list *map, int size, int i)
{
	int		n;
	char	c;
	t_list	*list;

	n = 0;
	list = ft_lst_find(map, &i, &ft_stack_cmp_num);
	if (list)
	{
		c = ((t_stack *)list->content)->id;
		if (c == '.')
		{
			/* board[i / size][i % size] = '*'; */
			((t_stack *)list->content)->id = '*';
			n++;
			n += ft_empty_around2(map, size, i);
		}
	}
	/* printf("list at %i: ", i); */
	/* fflush(stdout); */
	/* ft_lst_print(blob, &ft_putnbr); */
	return (n);
}

int		ft_empty_around2(t_list *map, int size, int i)
{
	int		n;

	n = 0;
	/* n += i % size < size - 1 ? ft_empty_here2(board, size, i + 1) : 0; */
	/* n += i / size > 0 ? ft_empty_here2(board, size, i - size) : 0; */
	/* n += i % size > 0 ? ft_empty_here2(board, size, i - 1) : 0; */
	/* n += i / size < size - 1 ? ft_empty_here2(board, size, i + size) : 0; */
	n += i % size < size - 1 ?  ft_empty_here2(map, size, i + 1) : 0;
	n += i / size > 0 ? ft_empty_here2(map, size, i - size) : 0;
	n += i % size > 0 ? ft_empty_here2(map, size, i - 1) : 0;
	n += i / size < size - 1 ? ft_empty_here2(map, size, i + size) : 0;
	/* ft_lst_print(add, &ft_putnbr); */
	return (n);
}
