#include "fillit.h"

int		ft_fit_blob(char **board, t_list **amap, t_list *blob, t_list *lttmn, int space)
{
	t_list	*list;
	t_list	*new_map;
	t_ttmn	*ttmn;
	int		size;
	int		i;

	size = ft_strlen(*board);
	/* blob = *(t_list **)lblob->content; */

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
			if (ft_solver(board, &new_map, lttmn, space))
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
	t_list	*blob;
	t_list	*new_map;
	int		sup_space = 0;
	int		size;
	int		i;

	if (!lttmn)
		return (ft_solved(board));
	size = ft_strlen(*board);
	/* ft_putendl("getting blobs for"); */
	/* ft_lst_print(*amap, &ft_putnbr); */
	/* ft_show_board(board); */
	new_map = ft_lstmap(*amap, &ft_id);
	while (new_map)
	{
		i = *(int *)(new_map)->content;
		blob = ft_empty_here(board, &new_map, size, i);
		ft_board_remove(board, '*');
		/* ft_putendl("found blob:"); */
		/* ft_lst_print(blob, &ft_putnbr); */
		/* if (ft_lstsize(blob) / 4 > 0) */
		/* 	ft_lsteadd(&lblob, ft_lstnew(&blob, sizeof(t_list *))); */
		if (ft_lstsize(blob) / 4 <= 1)
		{
			space -= ft_lstsize(blob) % 4;
			/* ft_putendl("delsub:"); */
			/* ft_lst_print(*amap, &ft_putnbr); */
			ft_lst_delsub(amap, blob, &ft_diff, &ft_lst_cfree);
			/* ft_lst_print(blob, &ft_putnbr); */
			/* ft_lst_print(*amap, &ft_putnbr); */
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
		/* ft_lst_print(*(t_list **)ft_lstlast(lblob), &ft_putnbr); */
		/* printf("took off %i, waste=%i\n", ft_lstsize(blob) % 4, size*size - 4*g_ttmn - space); */
		/* ft_show_board(board); */
		/* ft_lst_print(blob, &ft_putnbr); */
		/* fflush(stdout); */
		if (space + sup_space < 0)
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
	return (ft_solver(board, amap, lttmn, space));
}

/* int		ft_check_blobs(char **board, t_list **amap, t_list *lblob, t_list *lttmn, int space) */
/* { */
/* 	t_list	*blob; */
/* 	t_list	*new_map; */
/* 	int		size; */

/* 	/1* ft_putendl("at start of check_blobs"); *1/ */
/* 	if (!lttmn) */
/* 		return (ft_solved(board)); */
/* 	if (((t_ttmn *)lttmn->content)->placed) */
/* 		return (ft_check_blobs(board, amap, lblob, lttmn->next, space)); */
/* 	fflush(stdout); */
/* 	if (!lblob) */
/* 	{ */
/* 		/1* printf("calling solver, no more blobs\n"); *1/ */
/* 		/1* fflush(stdout); *1/ */
/* 		/1* new_map = ft_lstmap(*amap, &ft_id); *1/ */
/* 		return (ft_solver(board, amap, lttmn, space)); */
/* 	} */
/* 	size = ft_strlen(*board); */
/* 	blob = *(t_list **)lblob->content; */

/* 	/1* ft_show_board(board); *1/ */
/* 	/1* ft_lst_print(*amap, &ft_putnbr); *1/ */
/* 	/1* ft_lst_print2(lblob, &ft_putnbr); *1/ */
/* 	if (ft_lstsize(blob) / 4 == 1) */
/* 	{ */
/* 		/1* new_map = ft_lstmap(*amap, &ft_id); *1/ */
/* 		if (ft_fit_blob(board, amap, lblob, lttmn, space)) */
/* 		{ */
/* 			lblob = lblob->next; */
/* 			return (1); */
/* 		} */
/* 		else */
/* 		{ */
/* 			space -= 4; */
/* 			/1* printf("took off 4 from space : %i (fit)\n", space); *1/ */
/* 			/1* fflush(stdout); *1/ */
/* 			if (space < 0) */
/* 			{ */
/* 				/1* ft_show_board(board); *1/ */
/* 				/1* ft_putendl("not enough space"); *1/ */
/* 				return (0); */
/* 			} */
/* 		} */
/* 	} */
/* 	else */
/* 	{ */
/* 		/1* ft_lst_print(*amap, &ft_putnbr); *1/ */
/* 		/1* printf("blob too big, adding to map\n"); *1/ */
/* 		/1* fflush(stdout); *1/ */
/* 		/1* ft_lst_print(*amap, &ft_putnbr); *1/ */

/* 		ft_lst_sorted_merge(amap, blob, &ft_diff); */
/* 	} */
/* 	new_map = ft_lstmap(*amap, &ft_id); */
/* 	return(ft_check_blobs(board, &new_map, lblob->next, lttmn, space)); */
/* } */
