#include "fillit.h"

int		ft_fit_blob(char **board, t_list **amap, t_list *lblob, t_list *lttmn, int space)
{
	t_list	*list;
	t_list	*new_map;
	t_list	*blob;
	t_ttmn	*ttmn;
	int		size;
	int		i;

	size = ft_strlen(*board);
	blob = *(t_list **)lblob->content;
	/* ft_putendl("fitting blob :"); */
	/* ft_show_board(board); */
	/* ft_lst_print2(lblob, &ft_putnbr); */
	while (blob)
	{
		i = *(int*)blob->content;
		/* printf("at i=%i\n", i); */
		/* fflush(stdout); */
		list = lttmn;
		while (list)
		{
			ttmn = (t_ttmn *)list->content;
			/* ft_show_ttmn(*ttmn); */
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
			/* printf("just fitted ttmn %c\n", ttmn->id); */
			/* ft_show_ttmn(*ttmn); */
			if (ft_check_blobs(board, &new_map, lblob->next, lttmn, space))
				return (1);
			ttmn->placed = 0;
			ft_board_remove(board, ttmn->id);
			list = list->next;
		}
		blob = blob->next;
	}
	/* ft_putendl("failed to fit blob"); */
	return (0);
}

int		ft_get_blobs(char **board, t_list **amap, t_list *lttmn, int space)
{
	t_list	*lblob;
	t_list	*blob;
	t_list	*map;
	int		size;
	int		i;

	if (!lttmn)
		return (ft_solved(board));
	lblob = NULL;
	size = ft_strlen(*board);
	map = *amap;
	/* ft_putendl("getting blobs for"); */
	/* ft_lst_print(map, &ft_putnbr); */
	/* ft_show_board(board); */
	while (map)
	{
		i = *(int *)map->content;
		blob = ft_empty_here(board, amap, size, i);
		map = *amap;
		if (ft_lstsize(blob) / 4 > 0)
			ft_lsteadd(&lblob, ft_lstnew(&blob, sizeof(t_list *)));
		if (ft_lstsize(blob) / 4 <= 1)
			space -= ft_lstsize(blob) % 4;
		/* ft_lst_print(*(t_list **)ft_lstlast(lblob), &ft_putnbr); */
		/* printf("took off %i, waste=%i\n", ft_lstsize(blob) % 4, size*size - 4*g_ttmn - space); */
		/* ft_show_board(board); */
		/* ft_lst_print(blob, &ft_putnbr); */
		/* fflush(stdout); */
		if (space < 0)
		{
			ft_board_remove(board, '*');
			/* ft_show_board(board); */
			/* printf("lack of space=%i\n", space); */
			/* fflush(stdout); */
			return (0);
		}
	}
	ft_board_remove(board, '*');

	/* ft_putendl("found blobs in map:"); */
	/* ft_show_board(board); */
	/* ft_lst_print2(lblob, &ft_putnbr); */
	return (ft_check_blobs(board, amap, lblob, lttmn, space));
}

int		ft_check_blobs(char **board, t_list **amap, t_list *lblob, t_list *lttmn, int space)
{
	t_list	*blob;
	t_list	*new_map;
	int		size;

	/* ft_putendl("at start of check_blobs"); */
	if (!lttmn)
		return (ft_solved(board));
	if (((t_ttmn *)lttmn->content)->placed)
		return (ft_check_blobs(board, amap, lblob, lttmn->next, space));
	fflush(stdout);
	if (!lblob)
	{
		/* printf("calling solver, no more blobs\n"); */
		/* fflush(stdout); */
		/* new_map = ft_lstmap(*amap, &ft_id); */
		return (ft_solver(board, amap, lttmn, space));
	}
	size = ft_strlen(*board);
	blob = *(t_list **)lblob->content;

	/* ft_show_board(board); */
	/* ft_lst_print(*amap, &ft_putnbr); */
	/* ft_lst_print2(lblob, &ft_putnbr); */
	if (ft_lstsize(blob) / 4 == 1)
	{
		/* new_map = ft_lstmap(*amap, &ft_id); */
		if (ft_fit_blob(board, amap, lblob, lttmn, space))
		{
			lblob = lblob->next;
			return (1);
		}
		else
		{
			space -= 4;
			/* printf("took off 4 from space : %i (fit)\n", space); */
			/* fflush(stdout); */
			if (space < 0)
			{
				/* ft_show_board(board); */
				/* ft_putendl("not enough space"); */
				return (0);
			}
		}
	}
	else
	{
		/* ft_lst_print(*amap, &ft_putnbr); */
		/* printf("blob too big, adding to map\n"); */
		/* fflush(stdout); */
		/* ft_lst_print(*amap, &ft_putnbr); */

		ft_lst_sorted_merge(amap, blob, &ft_diff);
	}
	new_map = ft_lstmap(*amap, &ft_id);
	return(ft_check_blobs(board, &new_map, lblob->next, lttmn, space));
}
