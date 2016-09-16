#include "fillit.h"

int		ft_floodfill_recursive(char **board, int size, int i, char c)
{
	int		n;

	n = 0;
	if (board[i / size][i % size] == '.')
	{
		board[i / size][i % size] = c;
		n++;
		n += i % size < size - 1 ?  ft_floodfill_recursive(board, size, i + 1, c) : 0;
		n += i / size > 0 ? ft_floodfill_recursive(board, size, i - size, c) : 0;
		n += i % size > 0 ? ft_floodfill_recursive(board, size, i - 1, c) : 0;
		n += i / size < size - 1 ? ft_floodfill_recursive(board, size, i + size, c) : 0;
	}
	/* printf("list at %i: ", i); */
	/* fflush(stdout); */
	/* ft_lst_print(blob, &ft_putnbr); */
	return (n);
}

int		ft_floodfill_stack(char **board, int size, int i, char c)
{
	static const int dx[4] = {1, -1, 0, 0};
	static const int dy[4] = {0, 0, 1, -1};
	int		x;
	int		y;
	int		nx;
	int		ny;
	int		n;
	t_list	*top;
	t_list	*stack;
	t_list	*stack2;

	stack = NULL;
	stack2 = NULL;
	n = 0;
	ft_lstadd(&stack, ft_lstnew(&i, sizeof(int)));
	while (stack || stack2)
	{
		if (stack2)
			stack = stack2;
		stack2 = NULL;
		/* ft_board_print(board); */
		while((top = ft_lstpop(&stack)))
		{
			i = *(int *)top->content;
			x = i % size;
			y = i / size;
			board[y][x] = c;
			for(int j = 0; j < 4; j++) {
				nx = x + dx[j];
				ny = y + dy[j];
				i = nx + size * ny;
				if(nx >= 0 && nx < size && ny >= 0 && ny < size
						&& board[ny][nx] == '.')
				{
					ft_lstadd(&stack2, ft_lstnew(&i, sizeof(int)));
					n++;
				}
			}
		}
	}
	return (n);
}
