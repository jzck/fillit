#include "fillit.h"

int		ft_waste_here(char **board, int size, int i)
{
	int		n;

	n = 0;
	if (board[i / size][i % size] == '.')
	{
		board[i / size][i % size] = '*';
		n++;
		n += ft_waste_around(board, size, i);
	}
	return (n);
}

int		ft_waste_around(char **board, int size, int i)
{
	int		n;

	n = 0;
	n += i / size > 0 ? ft_waste_here(board, size, i - size) : 0;
	n += i % size > 0 ? ft_waste_here(board, size, i - 1) : 0;
	n += i / size < size - 1 ? ft_waste_here(board, size, i + size) : 0;
	n += i % size < size - 1 ? ft_waste_here(board, size, i + 1) : 0;
	return (n);
}

int		ft_fit_any(char **board, t_ttmn *ttmn, int i, int blob)
{
	int		y;
	int		l;
	int		size;
	char	tmp;
	int		n;

	/* printf("going to fit any at %i,%i\n", i, j); */
	/* fflush(stdout); */
	/* ft_show_board(board); */
	y = i;
	n = blob;
	size = ft_strlen(*board);
	while (y < size * size)
	{
		if (board[y / size][y % size] == '*')
		{
			n--;
			l = -1;
			/* printf("0 trying all at %i\n", y); */
			/* fflush(stdout); */
			while (ttmn[++l].id)
			{
				/* printf("1 trying %c at %i\n", ttmn[l].id, y); */
				/* fflush(stdout); */
				if (ttmn[l].id == '0')
					continue ;
				if (ft_board_add(board, ttmn[l], y))
					continue ;
				/* printf("passed board add\n"); */
				/* fflush(stdout); */
				/* ft_show_board(board); */
				ft_board_remove(board, '*');
				ft_board_remove(board, '^');
				if (!ttmn[1].id)
					return(ft_solved(board));
				tmp = ttmn[l].id;
				ttmn[l].id = '0';
				if (ft_solver(board, ttmn))
					return (1);
				ttmn[l].id = tmp;
				ft_board_remove(board, ttmn[l].id);
				ft_waste_here(board, size, y);
				/* ft_show_board(board); */
			}
			/* printf("failed at %i\n", y); */
			/* fflush(stdout); */
		}
		y++;
	}
	return (0);
}

int		ft_validate_waste(char **board, t_list *map, t_ttmn *ttmn)
{
	t_list	*blob;
	int		waste;
	int		size;

	if (ttmn->id == '0')
		return (ft_solver(board, ttmn + 1));
	if (!ttmn->id)
		return (ft_solved(board));
	blob = NULL;
	waste = 0;
	size = ft_strlen(*board);
	/* ft_show_board(board); */
	while (map)
	{
		ft_board_remove(board, '*');
		if (board[map->content / size][map->content % size] != '.')
		{
			map = map->next;
			continue ;
		}
		ft_lstadd(&blob, ft_waste_here(board, size, map->content));
		waste += ft_lstsize(blob) % 4;;
		ft_map_remove_blob(&map, blob);
		if (waste > size * size - 4 * g_ttmn)
			return (0);
		map = map->next;
	}
	while (blob)
	{
		if (ft_lstsize(blob->content) / 4 == 1)
		{
			if (ft_fit_any(board, blob->content, ttmn, y, blob))
				return (1);
			else
			{
				waste += (ft_lstsize(blob->content) / 4 == 1) ? 4 : 0;
				if (waste > size * size - 4 * g_ttmn)
					return (0);
			}
		}
		blob = blob->next;
	}
	return (ft_solver(board, ttmn));
}
