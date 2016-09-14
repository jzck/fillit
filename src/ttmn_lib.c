#include "fillit.h"

void	ft_show_ttmn(t_ttmn ttmn)
{
	int		i;

	if (!ttmn.id)
	{
		ft_putendl("end of ttmn\n");
		return ;
	}
	printf("%c,%i", ttmn.id, ttmn.placed);
	for (i=1; i < 4; i++)
		printf("\t%d,%d\n", ttmn.pos[i][0], ttmn.pos[i][1]);
	fflush(stdout);
	ft_putendl("");
}

void	ft_ttmn_reset(t_list *ttmn)
{
	((t_ttmn *)ttmn->content)->placed = 0;
}
