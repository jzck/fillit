#include "fillit.h"

int		ft_fit_blob(t_list **amap, t_list **astack, t_list *lttmn, int blob_size, int space, int size)
{
	t_ttmn	*ttmn;
	t_list	*list;
	t_list	*blob;
	t_stack	*stack;
	int		n;
	int		i;

	n = blob_size;
	blob = *astack;
	while (blob)
	{
		stack = blob->content;
		/* ft_put_stack(stack); */
		if (stack->id != '*')
		{
			/* ft_putendl("iwtbf"); */
			break ;
		}
		stack->id = '.';
		/* ft_lst_print(*astack, &ft_put_stack); */
		/* ft_put_stack(stack); */
		blob = blob->next;
		i = stack->num;
		list = lttmn;
		while (list)
		{
			ttmn = (t_ttmn *)list->content;
			list = list->next;
			/* if (ttmn->placed */
				/* || ft_stack_ttmn(amap, astack, i, ttmn->pos, ttmn->id, size)) */
				/* continue ; */
			ttmn->placed = 1;
			if (ft_solver(amap, astack, lttmn, space, size))
				return (1);
			ttmn->placed = 0;
		}
	}
	/* ft_lst_print(*astack, &ft_put_stack); */
	return (0);
}
