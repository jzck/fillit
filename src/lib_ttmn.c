#include "fillit.h"

int		ft_ttmn_validate(t_ttmn ttmn)
{
	size_t	i;
	size_t	j;
	int		touch;

	if (!(ttmn.id >= 'A' && ttmn.id <= 'Z'))
		return(1);
	i = -1;
	touch = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i != j
				&& ((FT_DIST(ttmn.pos[i][0], ttmn.pos[j][0]) == 0
				&& FT_DIST(ttmn.pos[i][1], ttmn.pos[j][1]) == 1)
				|| (FT_DIST(ttmn.pos[i][0], ttmn.pos[j][0]) == 1
				&& FT_DIST(ttmn.pos[i][1], ttmn.pos[j][1]) == 0)))
				touch++;
		}
	}
	if (touch == 6 || touch == 8)
		return (0);
	return (1);
}

void	ft_ttmn_print(t_ttmn ttmn)
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
