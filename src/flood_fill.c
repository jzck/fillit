#include "fillit.h"

int		ft_flood_fill(t_list *map, int size, int i, char c)
{
	int		n;
	char	id;
	t_list	*list;

	n = 0;
	list = ft_lst_find(map, &i, &ft_stack_cmp_num);
	if (list)
	{
		id = ((t_stack *)list->content)->id;
		if (id != c)
		{
			((t_stack *)list->content)->id = c;
			n++;
			n += i % size < size - 1 ?  ft_flood_fill(map, size, i + 1, c) : 0;
			n += i / size > 0 ? ft_flood_fill(map, size, i - size, c) : 0;
			n += i % size > 0 ? ft_flood_fill(map, size, i - 1, c) : 0;
			n += i / size < size - 1 ? ft_flood_fill(map, size, i + size, c) : 0;
		}
	}
	/* printf("list at %i: ", i); */
	/* fflush(stdout); */
	/* ft_lst_print(blob, &ft_putnbr); */
	return (n);
}
