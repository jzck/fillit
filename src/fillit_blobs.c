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
	int		i;

	if (!lttmn)
		return (ft_solved(board));
	size = ft_strlen(*board);
	new_map = ft_lstmap(*amap, &ft_id);
	while (new_map)
	{
		i = *(int *)(new_map)->content;
		blob = ft_empty_here(board, &new_map, size, i);
		ft_board_remove(board, '*');
		if (ft_lstsize(blob) / 4 <= 1)
		{
			space -= ft_lstsize(blob) % 4;
			ft_lst_delsub(amap, blob, &ft_diff, &ft_lst_cfree);
		}
		else
			sup_space -= ft_lstsize(blob) % 4;
		if (ft_lstsize(blob) / 4 == 1)
		{
			if (ft_fit_blob(board, amap, blob, lttmn, space))
				return (1);
			else
				space -= 4;
		}
		if (space + sup_space < 0)
		{
			ft_board_remove(board, '*');
			return (0);
		}
	}
	ft_board_remove(board, '*');
	return (ft_solver(board, amap, lttmn, space));
}
