#include "fillit.h"

int		ft_fit_blob(char **board, t_list **amap, t_list *blob, t_list *lttmn, int space)
{
	t_list	*list;
	t_list	*new_map;
	t_ttmn	*ttmn;
	int		size;
	int		i;

	size = ft_strlen(*board);
	while (blob)
	{
		i = *(int*)blob->content;
		list = lttmn;
		while (list)
		{
			ttmn = (t_ttmn *)list->content;
			if (ttmn->placed)
			{
				list = list->next;
				continue ;
			}
			if (ft_board_add(board, *ttmn, i))
			{
				list = list->next;
				continue ;
			}
			ttmn->placed = 1;
			new_map = ft_lstmap(*amap, &ft_id);
			if (ft_solver(board, &new_map, lttmn, space))
				return (1);
			ttmn->placed = 0;
			ft_board_remove(board, ttmn->id);
			list = list->next;
		}
		blob = blob->next;
	}
	return (0);
}

int		ft_get_blobs(char **board, t_list **amap, t_list *lttmn, int space)
{
	t_list	*blob;
	t_list	*new_map;
	int		sup_space = 0;
	int		size;
	int		blob_size;
	int		i;

	if (!lttmn)
		return (ft_solved(board));
	size = ft_strlen(*board);
	/* new_map = ft_lstmap(*amap, &ft_id); */
	new_map = *amap;
	while (new_map)
	{
		i = *(int *)(new_map)->content;
		/* ft_show_board(board); */
		/* ft_lst_print(new_map, &ft_putnbr); */

		blob = ft_empty_here(board, size, i);
		if (!blob)
		{
			new_map = new_map->next;
			continue ;
		}
		new_map = new_map->next;
		blob_size = ft_lstsize(blob);
		if (blob_size / 4 == 0)
		{
			space -= blob_size % 4;
			/* ft_putendl("delsub"); */
			/* ft_lst_print(*amap, &ft_putnbr); */
			ft_lst_delsub(amap, blob, &ft_diff, &ft_lst_cfree);
			/* ft_lst_print(blob, &ft_putnbr); */
			/* ft_lst_print(*amap, &ft_putnbr); */
			new_map = *amap;
			/* ft_debug(); */
			if (space + sup_space < 0)
			{
				ft_board_remove(board, '*');
				return (0);
			}
		}
		else if (blob_size / 4 == 1)
		{
			space -= blob_size % 4;
			ft_lst_delsub(amap, blob, &ft_diff, &ft_lst_cfree);
			new_map = *amap;
			if (ft_fit_blob(board, amap, blob, lttmn, space))
			{
				ft_board_remove(board, '*');
				return (1);
			}
			else
				space -= 4;
		}
		else
			sup_space -= blob_size % 4;
		if (space + sup_space < 0)
		{
			ft_board_remove(board, '*');
			return (0);
		}
	}
	ft_board_remove(board, '*');
	return (ft_solver(board, amap, lttmn, space));
}
