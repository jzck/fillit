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
		ft_lstiter(lttmn, &ft_ttmn_reset);
		ft_solver(&map, &stack, lttmn, size * size - 4 * g_ttmn, size);
		size--;
	}
	return (0);
}
