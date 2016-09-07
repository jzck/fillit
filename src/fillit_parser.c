#include "fillit.h"

int	g_target = 0;
int	g_ttmn = 0;

int		ft_validate_ttmn(t_ttmn ttmn)
{
	size_t	i;
	size_t	j;
	int		touch;

	if (!(ttmn.id >= 'A' && ttmn.id <= 'Z'))
		return(0);

	i = -1;
	touch = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i != j
				&& ((DIST(ttmn.pos[i][0], ttmn.pos[j][0]) == 0
				&& DIST(ttmn.pos[i][1], ttmn.pos[j][1]) == 1)
				|| (DIST(ttmn.pos[i][0], ttmn.pos[j][0]) == 1
				&& DIST(ttmn.pos[i][1], ttmn.pos[j][1]) == 0)))
				touch++;
		}
	}
	if (touch == 6 || touch == 8)
		return (1);
	return (0);
}

t_list	*ft_get_ttmn(char *filename)
{
	int			fd;
	char		buf[BUF_SIZE + 1];
	int			ret;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		l;
	int			ref[2];
	t_ttmn		ttmn;
	t_list		*list;
	t_list		*tmp;

	list = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	k = 0;
	j = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		i = 0;
		while (buf[i])
		{
			/* printf("%i, %i, %i: '%c'\n", i, j, k, buf[i]); */
			/* fflush(stdout); */
			if (buf[i] == '.')
				;
			else if (buf[i] == '#')
			{
				if (k == 0)
				{
					ref[0] = j / 5;
					ref[1] = j % 5;
					ttmn.pos[0][0] = 0;
					ttmn.pos[0][1] = 0;
					ttmn.id = 'A' + ft_lstsize(list);
				}
				else if (k <= 3)
				{
					ttmn.pos[k][0] = j / 5 - ref[0];
					ttmn.pos[k][1] = j % 5 - ref[1];
				}
				else
					return (0);
				k++;
			}
			else if (buf[i] == '\n')
			{
				if (i > 0 && buf[i - 1] == '\n')
				{
					if (j != 20)
						return (0);
					if (!ft_validate_ttmn(ttmn))
						return (0);
					tmp = ft_lstnew(&ttmn , sizeof(t_ttmn));
					/* printf("list: %p\n", list); */
					/* printf("new: %p\n", tmp); */
					/* printf("new->next: %p\n", tmp->next); */
					/* fflush(stdout); */
					ft_lsteadd(&list, tmp);
					/* printf("list: %p\n", list); */
					/* printf("list->next: %p\n", list->next); */
					/* fflush(stdout); */
					/* ft_show_ttmn(*(t_ttmn*)list->content); */
					/* ft_show_ttmn(*(t_ttmn*)ft_lstlast(list)->content); */
					l++;
					j = -1;
					k = 0;
				}
				else
				{
					if ((j + 1) % 5 != 0)
						return (0);
				}
			}
			else
				return (0);
			i++;
			j++;
		}
	}
	if (j != 20)
		return (0);
	if (!ft_validate_ttmn(ttmn))
		return (0);
	ft_lsteadd(&list, ft_lstnew(&ttmn , sizeof(t_ttmn)));
	g_target = 2;
	g_ttmn = ft_lstsize(list);
	while ((g_ttmn * 4) > (g_target) * (g_target))
		g_target++;
	printf("n_ttmn=%zu, target=%zu\n", g_ttmn, g_target);
	fflush(stdout);
	return (list);
}
