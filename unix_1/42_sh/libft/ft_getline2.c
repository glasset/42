/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:20:42 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:49:48 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static char		*ft_extract(char *str, char *ptr, int *line)
{
	int			i;

	i = -1;
	while (ptr[++i])
	{
		if (ptr[i] == '\n')
		{
			ptr[i] = '\0';
			(*line)++;
		}
	}
	str = ft_strjoin_free(str, ptr);
	return (str);
}

static char		*ft_readbuf(int fd, int line, int *cur_line)
{
	int			i;
	int			ret;
	char		*str;
	char		buf[512 + 1];

	ret = 0;
	str = ft_strnew(0);
	while (*cur_line < line && (ret = read(fd, buf, 512)) > 0)
	{
		i = -1;
		buf[ret] = 0;
		while (buf[++i] && *cur_line < (line - 1))
		{
			if (buf[i] == '\n')
				(*cur_line)++;
		}
		if (*cur_line == (line - 1))
			str = ft_extract(str, &((char *)buf)[i], cur_line);
	}
	if ((ret <= 0 && str[0] == '\0') || *cur_line <= 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char			*ft_getline(char *filename, int line)
{
	int			fd;
	char		*str;
	int			cur_line;

	cur_line = 0;
	fd = 0;
	if (filename && filename[0])
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = ft_readbuf(fd, line, &cur_line);
	close(fd);
	return (str);
}
