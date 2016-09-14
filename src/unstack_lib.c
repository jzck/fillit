#include "fillit.h"

void	ft_unstack_char(t_list **amap, t_list **astack, char c)
{
	t_list	*link;
	t_stack	*stack;

	link = *astack;
	stack = link->content;
	while (stack->id == c)
	{

		stack->id = '.';
		*astack = (*astack)->next;
		ft_lst_sorted_insert(amap, link, &ft_stack_cmp_num2);
		link = *astack;
		if (!link)
			break ;
		stack = link->content;
	}
}

void	ft_unstack_ttmn(t_list **amap, t_list **astack, char c)
{
	ft_unstack_char(amap, astack, '.');
	ft_unstack_char(amap, astack, c);
}
