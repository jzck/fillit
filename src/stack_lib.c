#include "fillit.h"

void	ft_put_stack_id(t_list *list)
{
	t_stack	*stack;

	stack = list->content;
	ft_putchar(stack->id);
}

void	ft_stack_as_board(t_list **astack, int size)
{
	int		i;
	t_list	*list;

	list = *astack;
	i = 1;
	while (list)
	{
		ft_put_stack_id(list);
		list = list->next;
		if (i++ % size == 0)
			ft_putendl("");
	}
}


void	ft_put_stack(t_stack *content)
{
	ft_putnbr(content->num);
	ft_putchar(',');
	ft_putchar(content->id);
}

t_list	*ft_stack_new_range(int a, int b)
{
	t_list	*lst;
	t_stack stack;

	if (a >= b)
		return (NULL);
	lst = NULL;
	while (a < b)
	{
		b--;
		stack.num = b;
		stack.id = '.';
		ft_lstadd(&lst, ft_lstnew(&stack, sizeof(t_stack)));
	}
	return (lst);
}

int		ft_stack_cmp_num(t_stack *a, int *b)
{
	return (a->num - *b);
}

int		ft_stack_cmp_num2(t_stack *a, t_stack *b)
{
	return (a->num - b->num);
}

int		ft_stack_cmp_id(t_stack *a, char *b)
{
	char	id;

	id = a->id;
	/* printf("id:%c, ref:%c, cmp:%i\n", id, *b, strncmp(&id, b, 1)); */
	/* fflush(stdout); */
	return (strncmp(&id, b, 1));
}

void	ft_map_clean(t_list *list)
{
	t_stack *stack;

	stack = (t_stack *)list->content;
	if (stack->id == '^')
		stack->id = '.';
}

void	ft_map_switch(t_list *list)
{
	t_stack *stack;

	stack = (t_stack *)list->content;
	if (stack->id == '*')
		stack->id = '^';
}

void	ft_map_stack_stars(t_list **amap, t_list **astack, char c)
{
	t_list	*link;
	t_stack	*content;
	char	star;

	star = '*';
	while ((link = ft_lst_removeif(amap, &star, &ft_stack_cmp_id)))
	{
		content = (t_stack *)link->content;
		content->id = c;
		ft_lstadd(astack, link);
	}
}

int		ft_check_ttmnfit(t_list **amap, int anchor, int pos[4][2], int size)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	while (++i < 4)
	{
		x = anchor % size + pos[i][1];
		y = anchor / size + pos[i][0];
		j = anchor + size * pos[i][0] + pos[i][1];
		if (x > size - 1 || y > size - 1 || x < 0 || y < 0)
			return (1);
		if (!ft_lst_find(*amap, &j, &ft_stack_cmp_num))
			return (1);
	}
	return (0);
}

void	ft_stack_ttmn(t_list **amap, t_list **astack, int anchor, int pos[4][2], int size, char id)
{
	int		i;
	int		j;
	t_stack	*stack;
	t_list	*link;

	i = -1;
	while (++i < 4)
	{
		j = anchor + size * pos[i][0] + pos[i][1];
		link = ft_lst_removeif(amap, &j, &ft_stack_cmp_num);
		stack = (t_stack *)link->content;
		stack->id = id;
		ft_lstadd(astack, link);
	}
}
