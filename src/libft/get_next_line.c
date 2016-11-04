/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:45:02 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 13:43:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 32

static char		*ft_realloc(char *line, int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + size + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, line);
	free(line);
	return (str);
}

static int		ft_loop_read(int fd, char **line, char (*save)[])
{
	char		buf[BUFF_SIZE + 1];
	char		*pos;
	int			ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((pos = ft_strchr(buf, '\n')))
		{
			ft_strcpy(*save, pos + 1);
			*pos = '\0';
			ft_strcat(*line, buf);
			return (1);
		}
		if ((*line = ft_realloc(*line, ret)) == NULL)
			return (-1);
		ft_strcat(*line, buf);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	save[BUFF_SIZE] = "";
	char		*pos;

	*line = (char *)malloc(sizeof(char *) * (BUFF_SIZE + ft_strlen(save) + 1));
	*line = ft_strcpy(*line, save);
	if ((pos = ft_strchr(*line, '\n')))
	{
		ft_strcpy(save, pos + 1);
		*pos = '\0';
		return (1);
	}
	return (ft_loop_read(fd, line, &save));
}
