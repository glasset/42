/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 20:07:01 by fcorbel           #+#    #+#             */
/*   Updated: 2014/01/07 16:36:14 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "header_wolf3d.h"

typedef struct	t_int
{
	int			fd;
	int			i;
	int			j;
	int			ret;
}				s_int;

int				get_map(int ***map, char *path)
{
	s_int		nb;
	char		*line;
	
	line = NULL;
	if ((nb.fd = open(path, O_RDONLY)) == -1)
		error("Error : open()");
	(*map) = (int **)malloc(sizeof(int *) * 7);
	line = (char *)malloc(sizeof(char) * 2);
	line[1] = 0;
	nb.i = 0;
	nb.j = 0;
	(*map)[nb.j] = (int *)malloc(sizeof(int) * 11);
	while ((nb.ret = read(nb.fd, line, 1)))
	{
		if (line[0] == '\n')
		{
			(*map)[++nb.j] = (int *)malloc(sizeof(int) * 11);
			nb.i = 0;
		}
		else
		{
			(*map)[nb.j][nb.i++] = ft_char_int(line[0]);
		}
	}
	close(nb.fd);
	return (0);
}

int				init_cos_tan(t_env *e)
{
	int			i;

	i = 1;
	e->cos = (int *)malloc(sizeof(int) * 360);
	e->tan = (int *)malloc(sizeof(int) * 360);
	while (i <= 360)
	{
		e->cos[i] = round(cos(i));
		e->tan[i] = round(tan(i));
		i++;
	}
	return (0);
}

int				init_p(t_env *e)
{
	t_dot		i;
	int			z;

	i.x = 0;
	i.y = 0;
	z = 0;
	while (e->map[i.x][i.y] != 0)
	{
		if (z == 0)
		{
			i.x++;
			z = 1;
		}
		else if (z == 1)
		{
			i.y++;
			z = 0;
		}
	}
	e->p = i;
	return (0);
}

int				init_e(t_env *e, char *path)
{
	init_cos_tan(e);
	get_map(&e->map, path);
	return (0);
}
