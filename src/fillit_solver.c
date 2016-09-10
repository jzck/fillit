#include "fillit.h"

int		ft_solved(char **board)
{
	g_sol = ft_copy_board(board);
	return (1);
}

int		ft_solver(char **board, t_list **amap, t_list *lttmn, int space)
{
	int		size;
	int		i;
	t_ttmn	*ttmn;
	t_list	*map;
	t_list	*valmap;

	if (!lttmn)
		return (ft_solved(board));
	ttmn = (t_ttmn *)lttmn->content;
	if (ttmn->placed)
		return (ft_solver(board, amap, lttmn->next, space));
	size = ft_strlen(*board);
	map = *amap;
	while (map)
	{
		i = *(int *)map->content;
		if (ft_board_add(board, *ttmn, i))
		{
			map = map->next;
			continue ;
		}
		valmap = ft_lstmap(*amap, &ft_id);
		ft_map_delttmn(&valmap, i, ttmn->pos, size);
		if (ft_get_blobs(board, &valmap, lttmn->next, space))
			return (1);
		ft_board_remove(board, ttmn->id);
		map = map->next;
	}
	return (0);
}
