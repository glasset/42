/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:30:30 by glasset           #+#    #+#             */
/*   Updated: 2014/03/26 18:51:04 by glasset          ###   ########.fr       */
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

static int	check_line(char *str)
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

static int	check_fd(int fd)
{
	if (fd < 0)
	{
		write(1, "\033[31m[ERROR]\033[0m Wrong file.\n", 28);
		return (-1);
	}
	return (0);
}

int			parse(t_env *e, char *path)
{
	char	*line;
	int		fd;
	int		current_m;
	int		error;
	f		*ft;

	ft = funct();
	current_m = 1;
	fd = open(path, O_RDONLY);
	if (check_fd(fd) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		error = ft[check_line(line)](e, current_m, fd, line);
		if (error == -1)
		{
			close(fd);
			return (-1);
		}
		current_m += error + 1;
		free(line);
	}
//	close(fd);
	return (0);
}
