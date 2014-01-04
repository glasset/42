/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:32:56 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 22:49:40 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "hotrace.h"

void			*ft_memchr(const void *s, int c, size_t n);

char				*ft_strcsub(char *s, char c)
{
	char			*tmp;
	int				i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	tmp[i] = '\0';
	while (i-- > 0)
		tmp[i] = s[i];
	return (tmp);
}

int					create_line(char **buf, char **line)
{
	char			*tmp;
	int				i;

	i = 0;
	tmp = ft_strcsub(*buf, '\n');
	if (*line)
		*line = ft_strjoin(*line, tmp);
	else
		*line = ft_strdup(tmp);
	ft_memdel((void **)(&tmp));
	if (ft_memchr(*buf, '\n', ft_strlen(*buf)))
	{
		while ((*buf)[i] != '\n')
			i++;
		*buf = ft_strsub(*buf, (i + 1), ft_strlen(*buf) - i);
		return (1);
	}
	return (0);
}

int					get_next_line(char **line, int fd)
{
	static char		*buf = NULL;
	int				ret;

	if (!line)
		return (-1);
	if (buf)
	{
		if (*line)
			ft_strclr(*line);
		if (create_line(&buf, line))
			return (1);
		else
			ft_strclr(buf);
	}
	else if ((*line = ft_strnew(0)))
		buf = (char *)malloc(sizeof(char) * (100));
	while ((ret = read(fd, buf, 1)))
	{
		buf[ret] = '\0';
		if (create_line(&buf, line))
			return (1);
	}
	ft_memdel((void **)(&buf));
	return ((ret = **line ? 1 : 0));
}

