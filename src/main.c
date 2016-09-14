#include "fillit.h"

char	**g_sol = NULL;

void	ft_usage(void)
{
	ft_putendl("error");
}

int		main(int ac, char **av)
{
	t_list	*lttmn;
	char	**board;
	int		size;

	if (ac != 2 || !(lttmn = ft_parse_ttmn(av[1])))
	{
		ft_usage();
		return (1);
	}
	size = g_target + 2;
	while (size >= g_target)
	{
		board = ft_board_init(size);
		ft_lstiter(lttmn, &ft_ttmn_reset);
		ft_solver(board, lttmn, size * size - 4 * g_ttmn, size);
		size--;
	}
	return (0);
}
