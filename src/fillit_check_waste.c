#include "fillit.h"

int		ft_check_waste(t_list **amap, t_list **astack, t_list *lttmn, int space, int size)
{
	t_stack	*stack;
	t_ttmn	*ttmn;
	t_list	*map;
	int		i;
	int		blob_size;

	if (!lttmn)
		return (ft_solved(amap, astack, size));
	ttmn = (t_ttmn *)lttmn->content;
	if (ttmn->placed)
		return (ft_solver(amap, astack, lttmn->next, space, size));
	space = 0;
	i = -1;
	map = *amap;
	while (map)
	{
		stack = (t_stack *)map->content;
		map = map->next;
		i = stack->num;
		if (stack->id != '.')
			continue ;
		ft_lstiter(*amap, &ft_map_switch);
		blob_size = ft_flood_fill(map, size, i, '*');
		space -= blob_size % 4;
		if (space > size * size - 4 * g_ttmn)
			return (0);
		/* if (blob_size / 4 == 1) */
		/* { */
		/* 	ft_board_remove(board, '*'); */
		/* 	blob = ft_empty_here(board, size, i); */
		/* 	if (ft_fit_blob2(board, amap, lttmn, i, blob_size, space)) */
		/* 		return (1); */
		/* 	space -= 4; */
		/* 	if (space > size * size - 4 * g_ttmn) */
		/* 		return (0); */
		/* } */
	}
	return (ft_solver(amap, astack, lttmn, space, size));
}
