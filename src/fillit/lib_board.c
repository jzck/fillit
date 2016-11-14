/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:34:39 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 10:17:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_board_print(char **board)
{
	while (*board)
		ft_putendl(*board++);
	ft_putendl("");
}

char	**ft_board_init(size_t size)
{
	char	**board;
	int		i;
	int		j;

	board = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < (int)size)
	{
		board[i] = ft_strnew(size);
		j = -1;
		while (++j < (int)size)
			board[i][j] = '.';
	}
	board[i] = NULL;
	return (board);
}

char	**ft_board_copy(char **board)
{
	size_t	size;
	char	**copy;

	size = ft_strlen(*board);
	copy = ft_board_init(size);
	ft_board_fill(copy, board);
	return (copy);
}

void	ft_board_fill(char **dst, char **src)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}
