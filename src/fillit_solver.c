#include "fillit.h"

int		ft_solved(char **board)
{
	g_sol = ft_copy_board(board);
	/* printf("new solution : size %i\n", ft_strlen(*board)); */
	/* fflush(stdout); */
	/* ft_show_board(g_sol); */
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

	/* ft_putendl("before solver"); */
	/* printf("space=%i, waste=%i\n", space, size*size - 4*g_ttmn - space); */
	/* fflush(stdout); */
	/* ft_show_board(board); */
	/* ft_lst_print(map, &ft_putnbr); */
	/* ft_show_ttmn(*ttmn); */
	while (map)
	{
		i = *(int *)map->content;
		/* printf("looking at %i\n", i); */
		/* fflush(stdout); */
		if (ft_board_add(board, *ttmn, i))
		{
			map = map->next;
			/* printf("map=%p\n", map); */
			/* fflush(stdout); */
			continue ;
		}
		/* printf("placed ttmn %c at %i\n", ttmn->id, i); */
		/* fflush(stdout); */

		ft_map_delttmn(amap, i, ttmn->pos, size);
		valmap = ft_lstmap(*amap, &ft_id);
		if (ft_get_blobs(board, &valmap, lttmn->next, space))
			return (1);

		/* printf("after blob fail\n"); */
		/* fflush(stdout); */

		ft_map_addttmn(amap, i, ttmn->pos, size);
		ft_lst_remove_if(amap, &i, &ft_diff);
		map = *amap;
		ft_board_remove(board, ttmn->id);

		/* ft_lst_print(*amap, &ft_putnbr); */
		/* ft_show_board(board); */
	}
	/* ft_putendl("failed solver"); */
	return (0);
}
