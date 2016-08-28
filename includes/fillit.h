#ifndef FILLIT_H
# include "libft.h"
# define FILLIT_H
# define BUF_SIZE 32


typedef struct	s_tetrim
{
	char	id;
	int		pos[3][2];
	int		placed;
}				t_tetrim;

#endif
