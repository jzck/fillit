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

t_list	*ft_get_ttmn(char *filename);

void ft_map_clean(t_list *list);
void ft_map_switch(t_list *list);
t_list	*ft_stack_new_range(int a, int b);
void	ft_map_stack_stars(t_list **amap, t_list **astack, char c);
void	ft_map_stack_ttmn(t_list **amap, t_list **astack, int anchor, int pos[4][2], char id, int size);
void	ft_put_stack(t_stack *content);
int		ft_stack_cmp_num(t_stack *a, int *b);
int		ft_stack_cmp_num2(t_stack *a, t_stack *b);

void	ft_map_unstack_char(t_list **amap, t_list **astack, char c);
void	ft_map_unstack_ttmn(t_list **amap, t_list **astack, char c);

char	**ft_empty_board(size_t size);
char	**ft_copy_board(char **board);
void	ft_free_board(char ***board);
void	ft_fill_board(char **dst, char **src);

void	ft_show_ttmn(t_ttmn ttmn);
void	ft_show_board(char **board);
void	ft_ttmn_reset(t_list *ttmn);

int		ft_board_add(char **board, t_ttmn block, int i);
void	ft_board_remove(char **board, char c);

int		ft_solver(char **board, t_list **amap, t_list **astack, t_list *lttmn, int space);
int		ft_solved(char **board);

int		ft_fit_blob(char **board, t_list **amap, t_list **astack, t_list *lttmn, int i, int blob_size, int space);
int		ft_solve_blobs(char **board, t_list **amap, t_list **astack, t_list *lttmn, int space);

t_list	*ft_empty_around(char **board, int size, int i);
t_list	*ft_empty_here(char **board, int size, int i);
int		ft_empty_around2(t_list *map, int size, int i);
int		ft_empty_here2(t_list *map, int size, int i);

void	ft_map_delttmn(t_list **amap, int anchor, int pos[4][2], int size);
void	ft_map_addttmn(t_list **amap, int anchor, int pos[4][2], int size);

void	ft_board_replace(char **board, char a, char b);
int		ft_validate_waste(char **board, t_list **amap, t_list *lttmn, int space);
#endif
