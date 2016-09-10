#include "fillit.h"

int		ft_solved(char **board)
{
	ft_board_remove(board, '*');
	g_sol = ft_copy_board(board);
	return (1);
}

int		ft_solver(char **board, t_list **amap, t_list *lttmn, int space)
{
	int		size;
	int		i;
	t_ttmn	*ttmn;
	t_list	*map;

	if (!lttmn)
		return (ft_solved(board));
	ttmn = (t_ttmn *)lttmn->content;
	if (ttmn->placed)
		return (ft_solver(board, amap, lttmn->next, space));
	size = ft_strlen(*board);
	map = *amap;
	/* ft_show_board(board); */
	/* ft_lst_print(*amap, &ft_putnbr); */
	while (map)
	{
		i = *(int *)map->content;
		if (ft_board_add(board, *ttmn, i))
		{
			map = map->next;
			continue ;
		}

		t_list	*n_map = ft_lstmap(*amap, &ft_id);
		ft_map_delttmn(&n_map, i, ttmn->pos, size);
		if (ft_get_blobs(board, &n_map, lttmn->next, space))
			return (1);

		/* ft_map_delttmn(amap, i, ttmn->pos, size); */
		/* if (ft_validate_waste(board, &n_map, lttmn->next, space)) */
		/* 	return (1); */
		if (ft_solver(board, amap, lttmn->next, space))
			return (1);
		/* ft_map_addttmn(amap, i, ttmn->pos, size); */
		/* map = *amap; */

		ft_board_remove(board, ttmn->id);
		map = map->next;
	}
	return (0);
}
