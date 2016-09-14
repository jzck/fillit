#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 32
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

extern int		g_target;
extern int		g_ttmn;
extern char		**g_sol;

typedef struct	s_stack
{
	char	id;
	int		num;
}				t_stack;

typedef struct	s_ttmn
{
	char	id;
	int		placed;
	int		pos[4][2];
}				t_ttmn;

t_list	*ft_parse_ttmn(char *filename);

int		ft_solver(char **board, t_list *lttmn, int space, int size);
int		ft_solved(char **board);

int		ft_check_waste(char **board, t_list *lttmn, int space, int size);
int		ft_flood_fill(char **board, int size, int i, char c);

int		ft_blobs(char **board, t_list *lttmn, int space, int size);
int		ft_fit_blob(char **board, t_list *lttmn, int space, int size, int blob_size, int i);

void	ft_board_print(char **board);
char	**ft_board_init(size_t size);
char	**ft_board_copy(char **board);
void	ft_board_fill(char **dst, char **src);
void	ft_board_free(char ***board);
void	ft_board_replace(char **board, char a, char b);
void	ft_board_remove(char **board, char c);
int		ft_board_add(char **board, t_ttmn ttmn, int i, int size);

void	ft_show_ttmn(t_ttmn ttmn);
void	ft_ttmn_reset(t_list *ttmn);
#endif
