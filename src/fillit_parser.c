#include "fillit.h"

size_t	g_target = 0;
size_t	g_ttmn = 0;

int		ft_validate_ttmn(t_ttmn block)
{
	size_t	i;
	size_t	j;
	int		touch;

	if (!(block.id >= 'A' && block.id <= 'Z'))
		return(0);

	i = -1;
	touch = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i != j
				&& ((DIST(block.pos[i][0], block.pos[j][0]) == 0
				&& DIST(block.pos[i][1], block.pos[j][1]) == 1)
				|| (DIST(block.pos[i][0], block.pos[j][0]) == 1
				&& DIST(block.pos[i][1], block.pos[j][1]) == 0)))
				touch++;
		}
	}
	if (touch == 6 || touch == 8)
		return (1);
	return (0);
}

t_ttmn	*ft_get_ttmn(char *filename)
{
	int			fd;
	char		buf[BUF_SIZE + 1];
	int			ret;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		l;
	int			ref[2];
	t_ttmn		*ttmn;

	ttmn = (t_ttmn *)ft_memalloc(sizeof(*ttmn) * 27);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	k = 0;
	j = 0;
	l = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		i = 0;
		while (buf[i])
		{
			/* printf("%i, %i, %i: '%c'\n", i, j, k, buf[i]); */
			if (buf[i] == '.')
				;
			else if (buf[i] == '#')
			{
				if (k == 0)
				{
					ref[0] = j / 5;
					ref[1] = j % 5;
					ttmn[l].pos[0][0] = 0;
					ttmn[l].pos[0][1] = 0;
					ttmn[l].id = 'A' + l;
				}
				else if (k <= 3)
				{
					ttmn[l].pos[k][0] = j / 5 - ref[0];
					ttmn[l].pos[k][1] = j % 5 - ref[1];
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
					if (!ft_validate_ttmn(ttmn[l]))
						return (0);
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
			{
				return (0);
			}
			i++;
			j++;
		}
	}
	if (j != 20)
		return (0);
	if (!ft_validate_ttmn(ttmn[l]))
		return (0);
	l++;
	g_target = 2;
	g_ttmn = l;
	while ((l * 4) > (g_target) * (g_target))
		g_target++;
	printf("n_ttmn=%zu, target=%zu\n", l, g_target);
	ttmn[l].id = '\0';
	return (ttmn);
}
