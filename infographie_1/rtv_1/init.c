/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:38:29 by glasset           #+#    #+#             */
/*   Updated: 2014/02/06 18:20:23 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "rtv.h"

void		init_ori_obj(t_vec *c, t_ray *l, t_obj *obj)
{
	c->x = l->ori.x - obj->o_x;
	c->y = l->ori.y - obj->o_y;
	c->z = l->ori.z - obj->o_z;
}

void		init_obj(t_ray *ray, char *str)
{
	int		fd;
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	ray->obj = (t_obj *)malloc(sizeof(t_obj));
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(0);
	get_next_line(fd, &line);
	ray->size_obj = atoi(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, '|');
		ray->obj[i].o_x = atoi(tmp[0]) + 0.0;
		ray->obj[i].o_y = atoi(tmp[1]) + 0.0;
		ray->obj[i].o_z = atoi(tmp[2]) + 0.0;
		ray->obj[i++].o_r = atoi(tmp[3]) + 0.0;
		free(line);
	}
}


