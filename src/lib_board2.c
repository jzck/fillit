/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_board2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:31:46 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 17:31:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_board_add(char **board, t_ttmn ttmn, int i, int size)
{
	int		x;
	int		y;
	int		k;

	k = 0;
	while (k < 4)
	{
		x = i % size + ttmn.pos[k][1];
		y = i / size + ttmn.pos[k][0];
		if (x > size - 1 || y > size - 1 || x < 0 || y < 0)
			return (1);
		if (board[y][x] != '.' && board[y][x] != '*')
			return (1);
		k++;
	}
	k = 0;
	while (k < 4)
	{
		x = i % size + ttmn.pos[k][1];
		y = i / size + ttmn.pos[k][0];
		board[y][x] = ttmn.id;
		k++;
	}
	return (0);
}

void	ft_board_free(char ***board)
{
	int		i;

	i = 0;
	while ((*board)[i])
	{
		free((*board)[i]);
		i++;
	}
	free(*board);
	*board = NULL;
}

void	ft_board_replace(char **board, char a, char b)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if (board[i][j] == a)
				board[i][j] = b;
		}
	}
}

void	ft_board_remove(char **board, char c)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if (board[i][j] == c)
				board[i][j] = '.';
		}
	}
}
