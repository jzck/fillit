#include "fillit.h"
int	g_target = 0;
int	g_ttmn = 0;

int		ft_parse_line(char *line, int linenumber, t_list **list)
{
	static t_ttmn	ttmn;
	static int		j = 0;
	static int		k = 0;
	int				i;

	if ((linenumber + 1) % 5 == 0)
	{
		if (ft_strlen(line) != 0)
			return (1);
		if (ft_parse_addttmn(&j, &k, ttmn, list))
			return (1);
		return (0);
	}
	if (ft_strlen(line) != 4)
		return (1);
	i = -1;
	while (line[++i])
	{
		/* ft_printf("%i,%i,%i: %c\n", i, j, k, line[i]); */
		if (!ft_strchr(".#", line[i]))
			return (1);
		else if (line[i] == '#' && ft_parse_sharp(&j, &k, &ttmn))
			return (1);
		j++;
	}
	return (0);
}

int		ft_parse_sharp(int *j, int *k, t_ttmn *ttmn)
{
	static int		ref[2];

	if (*k == 0)
	{
		ref[0] = *j / 4;
		ref[1] = *j % 4;
		/* ft_printf("refs: %i,%i\n", ref[0], ref[1]); */
		ttmn->pos[0][0] = 0;
		ttmn->pos[0][1] = 0;
	}
	else if (*k <= 3)
	{
		ttmn->pos[*k][0] = (*j) / 4 - ref[0];
		ttmn->pos[*k][1] = (*j) % 4 - ref[1];
		/* ft_printf("pos: %i,%i\n", ttmn->pos[*k][0], ttmn->pos[*k][1]); */
	}
	else
		return (1);
	*k += 1;
	return (0);
}

int		ft_parse_addttmn(int *j, int *k, t_ttmn ttmn, t_list **list)
{
	static char		id = 'A';
	t_list			*tmp;

	ttmn.id = id++;
	/* ft_printf("%i,%i\n", *j, *k); */
	if (*j != 16 || *k != 4)
		return (1);
	if (ft_ttmn_validate(ttmn))
		return (1);
	tmp = ft_lstnew(&ttmn , sizeof(t_ttmn));
	ft_lsteadd(list, tmp);
	*j = 0;
	*k = 0;
	return (0);
}

t_list	*ft_parse(char *filename)
{
	int			fd;
	int			ret;
	char		*line;
	int			linenumber;
	t_list		*list;

	list = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	linenumber = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		/* ft_printf("parsing line:%s\n", line); */
		if (ft_parse_line(line, linenumber++, &list))
			return (0);
	}
	if (ft_parse_line("", linenumber, &list))
		return (0);
	g_target = 4;
	g_ttmn = ft_lstsize(list);
	while ((g_ttmn * 4) > (g_target) * (g_target))
		g_target++;
	return (list);
}
