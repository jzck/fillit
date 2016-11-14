/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:31:13 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 10:46:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (ac != 2 || !(lttmn = ft_parse(av[1])))
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
		ft_sstrfree(board);
		size--;
	}
	ft_lstdel(&lttmn, &ft_lst_cfree);
	ft_board_print(g_sol);
	ft_sstrfree(g_sol);
	return (0);
}
