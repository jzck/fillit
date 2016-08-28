#include "fillit.h"

void	ft_usage(void)
{
	ft_putendl("error");
}

int		main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_usage();
		return (1);
	}
	return (0);
}
