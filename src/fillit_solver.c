#include "fillit.h"

int		ft_solved(t_list **amap, t_list **astack, int size)
{
	ft_putendl("found solution:");

	ft_lst_sort(astack, &ft_stack_cmp_num2);
	ft_lst_sorted_merge(astack, *amap, &ft_stack_cmp_num2);
	ft_lstiter(*astack, &ft_map_clean);
	ft_stack_as_board(astack, size);
	return (1);
}

int		ft_solver(t_list **amap, t_list **astack, t_list *lttmn, int space, int size)
{
	int		i;
	t_ttmn	*ttmn;
	t_list	*map;

	if (!lttmn)
		return (ft_solved(amap, astack, size));
	ttmn = (t_ttmn *)lttmn->content;
	if (ttmn->placed)
		return (ft_solver(amap, astack, lttmn->next, space, size));
	map = *amap;

	/* ft_lst_print(*amap, &ft_put_stack); */
	/* ft_lst_print(*astack, &ft_put_stack); */
	/* ft_stack_as_board(astack, size); */
	while (map)
	{
		i = ((t_stack *)map->content)->num;
		map = map->next;
		if (ft_check_ttmnfit(amap, i, ttmn->pos, size))
			continue ;
		ft_stack_ttmn(amap, astack, i, ttmn->pos, size, ttmn->id);

		/* if (ft_check_waste(amap, astack, lttmn->next, space, size)) */
		/* 	return (1); */
		/* if (ft_blobs(amap, astack, lttmn->next, space, size)) */
		/* 	return (1); */
		/* if (ft_solver(amap, astack, lttmn->next, space, size)) */
		/* 	return (1); */

		ft_unstack_ttmn(amap, astack, ttmn->id);
	}
	return (0);
}
