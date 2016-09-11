#include "fillit.h"

/* int		ft_fit_blob2(char **board, t_list **amap, t_list *lttmn, int i, int blob_size, int space) */
/* { */
/* 	t_ttmn	*ttmn; */
/* 	t_list	*list; */
/* 	int		y; */
/* 	int		l; */
/* 	int		size; */
/* 	int		n; */

/* 	/1* printf("going to fit any at %i,%i\n", i, j); *1/ */
/* 	/1* fflush(stdout); *1/ */
/* 	/1* ft_show_board(board); *1/ */
/* 	y = i; */
/* 	n = blob_size; */
/* 	size = ft_strlen(*board); */
/* 	while (y < size * size) */
/* 	{ */
/* 		if (board[y / size][y % size] == '*') */
/* 		{ */
/* 			n--; */
/* 			l = -1; */
/* 			/1* printf("0 trying all at %i\n", y); *1/ */
/* 			/1* fflush(stdout); *1/ */
/* 			list = lttmn; */
/* 			while (list) */
/* 			{ */
/* 				ttmn = (t_ttmn *)list->content; */
/* 				if (ttmn->placed) */
/* 				{ */
/* 					list = list->next; */
/* 					continue ; */
/* 				} */
/* 				if (ft_board_add(board, *ttmn, i)) */
/* 				{ */
/* 					list = list->next; */
/* 					continue ; */
/* 				} */
/* 				ttmn->placed = 1; */
/* 				if (ft_solver(board, amap, lttmn, space)) */
/* 					return (1); */
/* 				ttmn->placed = 0; */
/* 				ft_board_remove(board, ttmn->id); */
/* 				list = list->next; */
/* 			} */
/* 			/1* printf("failed at %i\n", y); *1/ */
/* 			/1* fflush(stdout); *1/ */
/* 		} */
/* 		y++; */
/* 	} */
/* 	return (0); */
/* } */



/* int		ft_validate_waste(char **board, t_list **amap, t_list *lttmn, int space) */
/* { */
/* 	t_ttmn	*ttmn; */
/* 	int	waste; */
/* 	int	y; */
/* 	t_list *blob; */
/* 	int	blob_size; */
/* 	int	size; */

/* 	if (!lttmn) */
/* 		return (ft_solved(board)); */
/* 	ttmn = (t_ttmn *)lttmn->content; */
/* 	if (ttmn->placed) */
/* 		return (ft_solver(board, amap, lttmn->next, space)); */
/* 	waste = 0; */
/* 	size = ft_strlen(*board); */
/* 	y = -1; */
/* 	/1* ft_show_board(board); *1/ */
/* 	while (++y < size * size) */
/* 	{ */
/* 		if (board[y / size][y % size] != '.') */
/* 			continue ; */
/* 		/1* blob = ft_empty_here(board, size, y); *1/ */
/* 		/1* blob_size = ft_lstsize(blob); *1/ */
/* 		blob_size = ft_empty_here2(board, size, y); */
/* 		/1* ft_board_replace(board, '*', '^') *1/ */
/* 		/1* printf("found blob=%i at %i\n", blob_size, y); *1/ */
/* 		/1* fflush(stdout); *1/ */
/* 		/1* ft_show_board(board); *1/ */
/* 		waste += blob_size % 4; */
/* 		if (waste > size * size - 4 * g_ttmn) */
/* 		{ */
/* 			ft_board_remove(board, '*'); */
/* 			return (0); */
/* 		} */
/* 		if (blob_size / 4 == 1) */
/* 		{ */
/* 			ft_board_remove(board, '*'); */
/* 			blob = ft_empty_here(board, size, y); */
/* 			if (ft_fit_blob2(board, amap, lttmn, y, blob_size, space)) */
/* 				return (1); */
/* 		} */
/* 		waste += (blob_size / 4 == 1) ? 4 : 0; */
/* 		if (waste > size * size - 4 * g_ttmn) */
/* 		{ */
/* 			ft_board_remove(board, '*'); */
/* 			return (0); */
/* 		} */
/* 	} */
/* 	ft_board_remove(board, '*'); */
/* 	return (ft_solver(board, amap, lttmn, space)); */
/* } */
