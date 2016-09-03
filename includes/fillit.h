#ifndef FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# define FILLIT_H
# define BUF_SIZE 32

extern size_t	g_target;
extern size_t	g_ttmn;
extern char		**g_sol;

typedef struct	s_ttmn
{
	char	id;
	int		pos[4][2];
}				t_ttmn;

t_ttmn	*ft_get_ttmn(char *filename);

char	**ft_empty_board(size_t size);
char	**ft_copy_board(char **board);
void	ft_free_board(char ***board);
void	ft_fill_board(char **dst, char **src);

void	ft_show_ttmn(t_ttmn ttmn);
void	ft_show_board(char **board);

int		ft_board_add(char **board, t_ttmn block, int i);
void	ft_board_remove(char **board, char c);

int		ft_solver(char **board, t_ttmn *ttmn);

int		ft_validate_waste(char **board, t_ttmn *ttmn);
int		ft_waste_around(char **board, int size, int i);
int		ft_waste_here(char **board, int size, int i);

#endif
