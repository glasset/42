/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:30:30 by glasset           #+#    #+#             */
/*   Updated: 2014/03/25 14:54:29 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"

int			comment(t_env *e, int c_l, int fd, char *str)
{
	e = e;
	str = str;
	c_l = c_l;
	fd = fd;
	return (0);
}

f			*funct(void)
{
	f		*ft;

	ft = malloc(sizeof(ft) * 4);
	ft[0] = &comment;
	ft[1] = &information;
	ft[2] = &init_mesh;
	ft[3] = &light;
	return (ft);
}
static int			check_line(char *str)
{
	if (!ft_strcmp(str, "information"))
		return (1);
	if (!ft_strcmp(str, "Sphere"))
		return (2);
	if (!ft_strcmp(str, "Plan"))
		return (2);
	if (!ft_strcmp(str, "Cylinder"))
		return (2);
	if (!ft_strcmp(str, "Cone"))
		return (2);
	if (!ft_strcmp(str, "Hyperbole"))
		return (2);
	if (!ft_strcmp(str, "Parabole"))
		return (2);
	if (!ft_strcmp(str, "Triangle"))
		return (2);
	if (!ft_strcmp(str, "light"))
		return (3);
	return (0);
}

void		parse(t_env *e, char *path)
{
	char	*line;
	int		fd;
	int		current_m;
	f		*ft;

	ft = funct();
	e->nb_mesh = 0;
	e->nb_light = 0;
	e->nb_mesh_malloc = -1;
	e->nb_light_malloc = -1;

	current_m = 1;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		write(1, "\033[31m[ERROR]\033[0m Wrong file.\n", 28);
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		if (current_m == 4)
		{
			if (line[5] != '#')
			{
				write(1, "\033[31m[ERROR]\033[0m Wrong format file.\n", 35);
				exit(0);
			}
		}
		current_m += ft[check_line(line)](e, current_m, fd, line);
		current_m++;
		free(line);
	}
}
