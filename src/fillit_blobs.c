#include "fillit.h"

int		ft_blobs(t_list **amap, t_list **astack, t_list *lttmn, int space, int size)
{
	t_list	*map;
	/* static int	id = 0;; */
	int		sup_space = 0;
	int		blob_size;
	int		i;

	if (!lttmn)
		return (ft_solved(amap, astack, size));
	map = *amap;
	ft_lstiter(*amap, &ft_map_clean);
	while (map)
	{
		i = ((t_stack *)map->content)->num;
		ft_lstiter(*amap, &ft_map_switch);
		blob_size = ft_flood_fill(map, size, i, '*');
		map = map->next;
		if (blob_size == 0)
			continue ;

		/* printf("found blob_size=%i\n", blob_size); */
		/* fflush(stdout); */
		/* ft_lst_print(*amap, &ft_put_stack); */
		/* ft_lst_print(*astack, &ft_put_stack); */
		/* fflush(stdout); */

		if (blob_size / 4 == 0)
		{
			space -= blob_size % 4;
			if (space + sup_space < 0)
				return (0);
			/* ft_putendl("stacking stars:"); */
			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */
			ft_map_stack_stars(amap, astack, '.');
			map = *amap;
			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */
		}
		else if (blob_size / 4 == 1)
		{
			space -= blob_size % 4;
			if (space + sup_space < 0)
				return (0);
			/* ft_putendl("stacking stars:"); */
			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */

			ft_map_stack_stars(amap, astack, '*');
			map = *amap;

			/* ft_lst_print(*amap, &ft_put_stack); */
			/* ft_lst_print(*astack, &ft_put_stack); */
			if (ft_fit_blob(amap, astack, lttmn, blob_size, space, size))
				return (1);
			else
			{
				space -= 4;
				if (space + sup_space < 0)
					return (0);
			}
		}
		else
		{
			sup_space -= blob_size % 4;
			if (space + sup_space < 0)
				return (0);
		}
	}
	return (ft_solver(amap, astack, lttmn, space, size));
}
