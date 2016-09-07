#include "fillit.h"

char	**g_sol = NULL;

void	ft_usage(void)
{
	ft_putendl("error");
}

int		main(int ac, char **av)
{
	t_list	*lttmn;
	t_list	*map;
	char	**board;
	int		size;

	if (ac != 2 || !(lttmn = ft_get_ttmn(av[1])))
	{
		ft_usage();
		return (1);
	}
	size = g_target + 2;
	/* ft_show_ttmn(*(t_ttmn *)lttmn->content); */
	/* ft_show_ttmn(*(t_ttmn *)ft_lstlast(lttmn)->content); */
	while (size >= g_target)
	{
		map = ft_lstnew_range(0, size * size);
		board = ft_empty_board(size);
		ft_lstiter(lttmn, &ft_ttmn_reset);
		ft_solver(board, &map, lttmn, 0);
		ft_free_board(&board);
		size--;
	}
	ft_show_board(g_sol);
	return (0);
}
