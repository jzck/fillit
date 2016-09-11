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
	t_list	*stack;
	char	**board;
	int		size;

	if (ac != 2 || !(lttmn = ft_get_ttmn(av[1])))
	{
		ft_usage();
		return (1);
	}
	size = g_target + 2;
	while (size >= g_target)
	{
		map = ft_stack_new_range(0, size * size);
		stack = NULL;
		board = ft_empty_board(size);
		ft_lstiter(lttmn, &ft_ttmn_reset);
		ft_solver(board, &map, &stack, lttmn, size * size - 4 * g_ttmn);
		ft_free_board(&board);
		size--;
	}
	ft_show_board(g_sol);
	return (0);
}
