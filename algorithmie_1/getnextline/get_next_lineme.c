/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 10:49:20 by glasset           #+#    #+#             */
/*   Updated: 2013/12/10 18:06:26 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static int		ft_split(char **buf, char **line)
{
	int		i;

	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			*line = ft_strsub(*buf, 0, i);
			*buf = ft_strsub(*buf, (i + 1), (BUFF_SIZE - i));
			return (1);
		}
		i++;
	}
	return (0);
}

static int		ft_read_write(int fd, char **buf, char **line)
{
	int		i;
	int		ret;

	while ((ret = read(fd, *buf , BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		i = 0;
		while (buf[0][i] != '\n' && buf[0][i] != '\0')
			i++;
		*line = ft_strjoin(*line, ft_strsub(*buf, 0, i));
		if (buf[0][i] == '\n')
		{
			*buf = ft_strsub(*buf, (i + 1), (BUFF_SIZE - i));
			return (1);
		}
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buf;

	if (fd >= 0 && (BUFF_SIZE > 0 && BUFF_SIZE < 2147483647))
	{
		if (*line == NULL)
			*line = ft_strnew(0);
		else if (BUFF_SIZE > 1 && ft_split(&buf, line))
			return (1);
		else
			*line = ft_strdup(buf);
		buf = ft_strnew(BUFF_SIZE);
		if (ft_read_write(fd, &buf, line) == 1)
			return (1);
		free(buf);
		return (ret = *line ? 1 : 0);
	}
	return (-1);
}
