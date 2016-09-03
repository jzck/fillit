#include "fillit.h"

char	**g_sol = NULL;

void	ft_usage(void)
{
	ft_putendl("error");
}

int		main(int ac, char **av)
{
	t_ttmn	*ttmn;
	char	**board;
	int		size;

	if (ac != 2 || !(ttmn = ft_get_ttmn(av[1])))
	{
		ft_usage();
		return (1);
	}
	size = g_target + 2;
	while (size >= (int)g_target)
	{
		board = ft_empty_board(size);
		ft_solver(board, ttmn);
		ft_free_board(&board);
		size--;
	}
	ft_show_board(g_sol);
	return (0);
}
