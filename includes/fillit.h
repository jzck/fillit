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

void	ft_map_clean(t_list *list);
void	ft_map_switch(t_list *list);
t_list	*ft_stack_new_range(int a, int b);
void	ft_map_stack_stars(t_list **amap, t_list **astack, char c);
void	ft_put_stack(t_stack *content);
int		ft_stack_cmp_num(t_stack *a, int *b);
int		ft_stack_cmp_num2(t_stack *a, t_stack *b);
void	ft_stack_as_board(t_list **stack, int size);
void	ft_unstack_char(t_list **amap, t_list **astack, char c);
void	ft_unstack_ttmn(t_list **amap, t_list **astack, char c);

int		ft_check_ttmnfit(t_list **amap, int anchor, int pos[4][2], int size);
void	ft_stack_ttmn(t_list **amap, t_list **astack, int anchor, int pos[4][2], int size, char id);


int		ft_check_waste(t_list **amap, t_list **astack, t_list *lttmn, int space, int size);

void	ft_show_ttmn(t_ttmn ttmn);
void	ft_ttmn_reset(t_list *ttmn);

int		ft_solver(t_list **amap, t_list **astack, t_list *lttmn, int space, int size);
int		ft_solved(t_list **astack, t_list **amap, int size);

int		ft_fit_blob(t_list **amap, t_list **astack, t_list *lttmn, int blob_size, int space, int size);
int		ft_blobs(t_list **amap, t_list **astack, t_list *lttmn, int space, int size);

int		ft_flood_fill(t_list *map, int size, int i, char c);
#endif
