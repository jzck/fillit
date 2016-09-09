#include "fillit.h"

int		cmp_ttmn(t_ttmn a, t_ttmn b)
{
	return (ft_strcmp(&a.id, &b.id));
}

void	ft_ttmn_reset(t_list *ttmn)
{
	((t_ttmn *)ttmn->content)->placed = 0;
}

void	ft_map_delttmn(t_list **amap, int anchor, int pos[4][2], int size)
{
	int		i;
	int		j;

	i = -1;
	fflush(stdout);
	while (++i < 4)
	{
		/* printf("deleting: %i\n", anchor + size * pos[i][0] + pos[i][1]); */
		/* fflush(stdout); */
		j = anchor + size * pos[i][0] + pos[i][1];
		ft_lst_remove_if(amap, &j, &ft_diff);
	}
}

void	ft_map_addttmn(t_list **amap, int anchor, int pos[4][2], int size)
{
	int		i;
	int		j;
	t_list	*link;

	i = -1;
	while (++i < 4)
	{
		j = (anchor + size * pos[i][0] + pos[i][1]);
		/* printf("adding %i to map\n", j); */
		/* fflush(stdout); */
		link = ft_lstnew(&j, sizeof(int));
		ft_lst_sorted_insert(amap, link, &ft_diff);
	}
}
