#include "fillit.h"

void	ft_usage(void)
{
	ft_putendl("error");
}

t_list	*ft_get_tetrims(char *filename)
{
	int			fd;
	char		buf[BUF_SIZE + 1];
	int			i;
	int			j;
	int			k;
	int			ref[2];
	char		letter = 'A';
	t_tetrim	tetrim;
	t_list		*tetrims;

	fd = open(filename);
	if (fd == -1)
		return (0);
	j = -1;
	k = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		ret[BUF_SIZE] = '\0';
		i = 0;
		while (ret[i])
		{
			if (ret[i] == '.')
				;
			else if (ret[i] == '#')
			{
				if (j == -1)
				{
					tetrim.id = letter++;
					ref[0] = k / 5;
					ref[1] = k % 5;
				}
				else if (j >= 0 && j <= 2)
				{
					(tetrim.pos)[j][0] = i / 5 - ref[0];
					(tetrim.pos)[j][1] = i % 5 - ref[1];
				}
				else
					return (0);
				j++;
			}
			else if (i > 0 && ret[i] == '\n' && ret[i - 1] == '\n')
			{
				if (j != 3 || k != 20)
					return (0);
				ft_lstadd(&tetrims, ft_lstnew(tetrim, sizeof(tetrim)));
				j = -1;
				k = -1;
			}
			else if (ret[i] == '\n')
			{
				if ((k + 1) % 5 != 0)
					return (0);
			}
			else
				return (0);
			i++;
			k++;
		}
	}
	if (j != 3 || k != 20)
		return (0);
	ft_lstadd(&tetrims, ft_lstnew(tetrim, sizeof(tetrim)));
	return (tetrims);
}

int		main(int ac, char **av)
{
	t_list	*tetrims;
	int		i;

	if (ac != 2 || !(tetrims = ft_get_tetrims(av[1])))
	{
		ft_usage();
		return (1);
	}
	while (tetrims)
	{
		printf("%c", tetrims->content.id);
		for (i=0; i<=3; i++)
			printf("\t%i,%i\n", tetrims->content.pos[i][0], tetrims->content.pos[i][1]);
		ft_putendl("");
		tetrims = tetrims->next;
	}
	return (0);
}
