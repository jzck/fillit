#include "fillit.h"

int		ft_solved(char **board)
{
	ft_board_remove(board, '*');
	g_sol = ft_copy_board(board);
	ft_putendl("found solution:");
	ft_show_board(board);
	return (1);
}

int		ft_solver(char **board, t_list **amap, t_list **astack, t_list *lttmn, int space)
{
	int		i;
	int		size;
	t_ttmn	*ttmn;
	t_list	*map;

	if (!lttmn)
		return (ft_solved(board));
	ttmn = (t_ttmn *)lttmn->content;
	if (ttmn->placed)
		return (ft_solver(board, amap, astack, lttmn->next, space));
	size = ft_strlen(*board);
	map = *amap;

	/* ft_show_board(board); */
	/* ft_lst_print(*amap, &ft_put_stack); */
	/* ft_lst_print(*astack, &ft_put_stack); */
	while (map)
	{
		i = ((t_stack *)map->content)->num;
		if (ft_board_add(board, *ttmn, i))
		{
			map = map->next;
			continue ;
		}
		ft_map_stack_ttmn(amap, astack, i, ttmn->pos, ttmn->id, size);
		/* ft_show_board(board); */
		/* ft_lst_print(*amap, &ft_put_stack); */
		/* ft_lst_print(*astack, &ft_put_stack); */

		if (ft_solve_blobs(board, amap, astack, lttmn->next, space))
			return (1);
		/* ft_putendl("p2"); */
		/* ft_show_board(board); */
		/* ft_lst_print(*amap, &ft_put_stack); */
		/* ft_lst_print(*astack, &ft_put_stack); */

		ft_map_unstack_ttmn(amap, astack, ttmn->id);
		ft_lstiter(*amap, &ft_map_clean);
		ft_board_remove(board, ttmn->id);
		map = map->next;

		/* ft_lst_print(*amap, &ft_put_stack); */
		/* ft_lst_print(*astack, &ft_put_stack); */
	}
	return (0);
}
