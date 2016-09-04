#include "fillit.h"

int		ft_solved(char **board)
{
	printf("new solution : size %i\n", ft_strlen(*board));
	fflush(stdout);
	g_sol = ft_copy_board(board);
	ft_show_board(g_sol);
	return (1);
}

int		ft_solver(char **board, t_list *map, t_ttmn *ttmn)
{
	int		j;
	int		size;

	if (ttmn->id == '0')
		return (ft_solver(board, ttmn + 1));
	if (!ttmn->id)
		return (ft_solved(board));
	/* ft_show_board(board); */
	size = ft_strlen(*board);
	while (map)
	{
		/* ft_show_board(board); */
		if (ft_board_add(board, *ttmn, map->content))
			continue ;
		ft_map_remove(map, i, *ttmn);
		if (ft_validate_waste(board, map, ttmn + 1))
			return (1);
		ft_map_add(map, i, *ttmn);
		ft_board_remove_ttmn(&map, ttmn->id);
		map = map->next;
	}
	return (0);
}
