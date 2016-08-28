#include "fillit.h"

void	ft_usage(void)
{
	ft_putendl("error");
}

t_tetrim	*ft_get_tetrims(char *filename)
{
	int			fd;
	char		buf[BUF_SIZE + 1];
	int			ret;
	int			i;
	int			j;
	int			k;
	int			l;
	int			ref[2];
	char		letter = 'A';
	t_tetrim	*tetrims;

	tetrims = (t_tetrim *)ft_memalloc(sizeof(t_tetrim) * 27);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	k = -1;
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
				if (k == -1)
				{
					tetrims[l].id = letter++;
					ref[0] = j / 5;
					ref[1] = j % 5;
				}
				else if (k >= 0 && k <= 2)
				{
					tetrims[l].pos[k][0] = j / 5 - ref[0];
					tetrims[l].pos[k][1] = j % 5 - ref[1];
				}
				else
					return (0);
				k++;
			}
			else if (buf[i] == '\n')
			{
				if (i > 0 && buf[i - 1] == '\n')
				{
					if (k != 3 || j != 20)
						return (0);
					l++;
					j = -1;
					k = -1;
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
	if (k != 3 || j != 20)
		return (0);
	tetrims[l + 1].id = '\0';
	return (tetrims);
}

int		main(int ac, char **av)
{
	t_tetrim	*tetrims;
	int		i;
	int		l;

	if (ac != 2 || !(tetrims = ft_get_tetrims(av[1])))
	{
		ft_usage();
		return (1);
	}
	l = -1;
	while (tetrims[++l].id)
	{
		printf("%c\n",tetrims[l].id);
		for (i=0; i < 3; i++)
			printf("%i,%i\n", tetrims[l].pos[i][0], tetrims[l].pos[i][1]);
		ft_putendl("");
	}
	return (0);
}
