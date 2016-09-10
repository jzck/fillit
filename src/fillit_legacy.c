/*
void	ft_grow_board(char **board)
{
	int	i;
	int	size;

	size = ft_strlen(*board);
	i = 0;
	while (++i <= size)
	{
		board[i][size] = '.';
		board[size][i] = '.';
	}
}

void	ft_shrink_board(char **board)
{
	int	i;
	int	size;

	size = ft_strlen(*board);
	i = -1;
	while (++i < size)
	{
		board[i][size - 1] = '\0';
		board[size - 1][i] = '\0';
	}
}

int		ft_test_fit(char **board, t_ttmn block, int i, int j)
{
	size_t	k;
	int		new_size;
	int		size;
	int		x;
	int		y;

	size = ft_strlen(*board);
	new_size = size;
	k = -1;
	while (++k < 4)
	{
		x = (int)j + block.pos[k][1];
		y = (int)i + block.pos[k][0];
		if (x < 0 || x < 0)
			return (0);
		if (x > size - 1 || y > size - 1)
		{
			new_size = MAX(new_size, MAX(x + 1, y + 1));
			continue ;
		}
		if (board[y][x] != '.' && board[y][x] != '*')
			return (0);
	}
	return (0);
}

*/

/* int		ft_check_blobs(char **board, t_list **amap, t_list *lblob, t_list *lttmn, int space) */
/* { */
/* 	t_list	*blob; */
/* 	t_list	*new_map; */
/* 	int		size; */

/* 	if (!lttmn) */
/* 		return (ft_solved(board)); */
/* 	if (((t_ttmn *)lttmn->content)->placed) */
/* 		return (ft_check_blobs(board, amap, lblob, lttmn->next, space)); */
/* 	fflush(stdout); */
/* 	if (!lblob) */
/* 	{ */
/* 		return (ft_solver(board, amap, lttmn, space)); */
/* 	} */
/* 	size = ft_strlen(*board); */
/* 	blob = *(t_list **)lblob->content; */

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
