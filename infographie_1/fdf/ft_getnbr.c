/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 18:32:20 by glasset           #+#    #+#             */
/*   Updated: 2013/12/13 18:43:16 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

int			ft_count(char *str)
{
	char	*buf;
	int		q;
	int		ret;
	int		fd;

	q = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printperror(str);
		return (-1);
	}
	buf = (char *)malloc(sizeof(char) * 1);
	while ((ret = read(fd, buf, 1)))
	{
		if (ret == -1)
			return (-1);
		if (buf[0] == '\n')
				q++;
	}
	close (fd);
	free(buf);
	if (q == 0)
		ft_printempty(str);
	return (q);
}

int			ft_open(char *str, t_point ***t)
{
	int		fd;
	char	*line;
	int		q;
	int		count;

	count = ft_count(str);
	if (count == -1 || count == 0)
		return (-1);
	line = NULL;
	(*t) = (t_point **)malloc(sizeof(t_point *) * count);
	q = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		(*t)[q] = ft_getnbr(line, q);
		q++;
	}
	(*t)[0][0].y = count;
	return (0);
}

t_point		*ft_getnbr(char *str, int q)
{
	int			i;
	t_point		*xy;
	char		**tmp;

	i = 0;
	tmp = ft_strsplit(str, ' ');
	while (tmp[i])
		i++;
	xy = (t_point *)malloc(sizeof(t_point) * (i + 1));
	i = 0;
	while (tmp[i])
	{
		xy[i + 1] = ft_iso(i, q, ft_atoi(tmp[i]));
		i++;
	}
	xy[0].x = i;
	if (tmp)
		free(tmp);
	return (xy);
}

