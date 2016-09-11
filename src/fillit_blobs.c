#include "fillit.h"

int		ft_fit_blob(char **board, t_list **amap, t_list **astack, t_list *lttmn, int i, int blob_size, int space)
{
	t_ttmn	*ttmn;
	t_list	*list;
	t_list	*blob;
	t_stack	*stack;
	int		size;
	int		n;

	n = blob_size;
	size = ft_strlen(*board);
	blob = *astack;

	/* ft_putendl("fitting blob:"); */
	/* ft_show_board(board); */
	/* ft_lst_print(blob, &ft_put_stack); */

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
			if (ttmn->placed || ft_board_add(board, *ttmn, i))
			{
				list = list->next;
				continue ;
			}
			/* printf("fitted %c in blob\n", ttmn->id); */
			/* fflush(stdout); */
			ttmn->placed = 1;
			/* ft_map_stack_ttmn(amap, astack, i, ttmn->pos, ttmn->id, size); */

			if (ft_solver(board, amap, astack, lttmn, space))
				return (1);

			/* ft_map_unstack(amap, astack, 4); */
			ttmn->placed = 0;
			ft_board_remove(board, ttmn->id);

			list = list->next;
		}
	}
	/* ft_lst_print(*astack, &ft_put_stack); */
	return (0);
}

int		ft_solve_blobs(char **board, t_list **amap, t_list **astack, t_list *lttmn, int space)
{
	t_list	*map;
	int		sup_space = 0;
	int		size;
	int		blob_size;
	int		i;

	if (!lttmn)
		return (ft_solved(board));
	size = ft_strlen(*board);
	map = *amap;
	/* ft_board_remove(board, '*'); */
	/* ft_board_remove(board, '^'); */
	ft_lstiter(*amap, &ft_map_clean);

	/* ft_show_board(board); */
	while (map)
	{
		i = ((t_stack *)map->content)->num;
		ft_board_replace(board, '*', '^');
		ft_lstiter(*amap, &ft_map_switch);
		blob_size = ft_empty_here2(map, size, i);
		map = map->next;
		if (blob_size == 0)
			continue ;

		/* printf("found blob_size=%i\n", blob_size); */
		/* fflush(stdout); */
		/* ft_lst_print(*amap, &ft_put_stack); */
		/* ft_lst_print(*astack, &ft_put_stack); */

		fflush(stdout);
		if (blob_size / 4 == 0)
		{
			space -= blob_size % 4;
			if (space + sup_space < 0)
			{
				ft_board_remove(board, '*');
				return (0);
			}
			/* ft_putendl("stacking stars:"); */
			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */
			ft_map_stack_stars(amap, astack, '.');
			map = *amap;
			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */
		}
		else if (blob_size / 4 == 1)
		{
			space -= blob_size % 4;
			if (space + sup_space < 0)
			{
				ft_board_remove(board, '*');
				return (0);
			}
			/* ft_putendl("stacking stars:"); */
			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */

			ft_map_stack_stars(amap, astack, '*');
			map = *amap;

			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */
			if (ft_fit_blob(board, amap, astack, lttmn, i, blob_size, space))
			{
				ft_board_remove(board, '*');
				return (1);
			}
			else
			{
				space -= 4;
				if (space + sup_space < 0)
				{
					/* ft_board_remove(board, '*'); */
					return (0);
				}
			}
		}
		else
		{
			sup_space -= blob_size % 4;
			if (space + sup_space < 0)
			{
				ft_board_remove(board, '*');
				return (0);
			}
		}
	}
	/* ft_board_remove(board, '*'); */
	/* ft_board_remove(board, '^'); */
	return (ft_solver(board, amap, astack, lttmn, space));
}
