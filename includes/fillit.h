#ifndef FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# define FILLIT_H
# define BUF_SIZE 32

extern size_t g_size;

typedef struct	s_ttmn
{
	char	id;
	int		pos[4][2];
}				t_ttmn;

t_ttmn	*ft_get_ttmn(char *filename);
void	ft_show_ttmn(t_ttmn ttmn);
void	ft_show_board(char **board);

#endif
