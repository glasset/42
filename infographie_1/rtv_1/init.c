/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:38:29 by glasset           #+#    #+#             */
/*   Updated: 2014/02/07 18:22:02 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "rtv.h"
#include <stdio.h>
void		check_obj(t_ray *ray, void *img, t_vec *index)
{
	t_vec	spheres;
	t_vec	plans;
	spheres = sphere(ray);
	plans = plan(ray);
	double	a;

	if (plans.x > -1.0  && spheres.z != -1.0 && plans.x <= spheres.x)
		a = plans.x;
	else
		a = spheres.x + 1.0;
	if (spheres.z == -1.0 && plans.x == -1.0)
		put_px_to_img(img, index->x, index->y, 200, 0, 0);
	else if (spheres.x < a && spheres.z != -1.0 )
		put_px_to_img(img, index->x, index->y, 0, spheres.y * 100, 200);
	else
		put_px_to_img(img, index->x, index->y, plans.x * 100, 0, 0);
}

void		shor_dist(double a, double b, t_vec  *shor, double i)
{
	if (shor->x == -1.0)
	{
		if (a >= 0.0 && b >= 0)
		{
			if (a < b)
				shor->x = a;
			else
				shor->x = b;
		}
		else if (b < 0)
			shor->x = a;
		else if (a < 0)
			shor->y = b;
		shor->y = i;
	}
	else if (a >= 0.0 && b >= 0)
	{
		if (a < shor->x && a < b)
		{
			shor->y = i;
			shor->x = a;
		}
		else if (b < shor->x && b < a)
		{
			shor->y = i;
			shor->x = a;
		}
	}
	else if (a < 0 && b >= 0)
	{
		if (b < shor->x)
		{
			shor->x = b;
			shor->y = i;
		}
	}
	else if (a >= 0 && b < 0)
	{
		if (a < shor->x)
		{
			shor->x = a;
			shor->y = i;
		}
	}
}

void		norme(t_vec *l)
{
	double	len;

	len = sqrt(pow(l->x, 2.0) + pow(l->y, 2.0) + pow(l->z, 2.0));
	l->x = l->x / len;
	l->y = l->y / len;
	l->z = l->z / len;
}

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
	close(fd);
}


