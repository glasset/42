/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:56:30 by glasset           #+#    #+#             */
/*   Updated: 2014/02/07 18:21:56 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "rtv.h"

void			view(t_ray *l, t_cam *c)
{
	l->dir.x = 0.0 - l->ori.x;
	l->dir.y = 0.0 - l->ori.y;
	l->dir.z = 1.0 - l->ori.z;
	c->up.x = 0.0;
	c->up.y = -1.0;
	c->up.z = 0.0;
	c->right.x = (c->up.y * l->dir.z - c->up.z * l->dir.y);
	c->right.y = (c->up.z * l->dir.x - c->up.x * l->dir.z);
	c->right.z = (c->up.x * l->dir.y - c->up.y * l->dir.x);
	norme(&c->right);
	c->view.x = POV_X + ((l->dir.x * VPD) + (c->up.x * (VPH / 2.0))) -
		(c->right.x * (VPW / 2.0));
	c->view.y = POV_Y + ((l->dir.y * VPD) + (c->up.y * (VPH / 2.0))) -
		(c->right.y * (VPW / 2.0));
	c->view.z = POV_Z + ((l->dir.z * VPD) + (c->up.z * (VPH / 2.0))) -
		(c->right.z * (VPW / 2.0));
}

t_vec			sphere(t_ray *l)
{
	t_vec		c;
	t_vec		res;
	t_vec		shor;
	double		s;
	int			i;
	shor.z = 42.0;
	shor.x = -1.0;
	i = 0;
	while (i < l->size_obj)
	{
		init_ori_obj(&c, l, &l->obj[i]);
		s = l->obj[i].o_r;
		res.x = pow(l->dir.x, 2.0) + pow(l->dir.y, 2.0) + pow(l->dir.z, 2.0);
		res.y = 2.0 * (l->dir.x * c.x + l->dir.y * c.y + l->dir.z * c.z);
		res.z = pow(c.x, 2.0) + pow(c.y, 2.0) + pow(c.z, 2.0) - pow(s, 2.0);
		c.x = pow(res.y, 2.0) - 4.0 * res.x * res.z;
		if (c.x < 0.0 && shor.z == 42.0)
			shor.z = -1.0;
		if (c.x > -1.0)
		{
			shor_dist(((-res.y + sqrt(c.x)) / 2 * res.x),
					((-res.y - sqrt(c.x)) / 2 * res.x), &shor, (double)i);
			shor.z = 0.0;
		}
		i++;
	}
	return (shor);
}

t_vec			plan(t_ray *l)
{
	t_vec		shor;
	t_vec		c;
	t_vec		t;
	double		res;

	shor.x = -1.0;
	shor.y = 1.0;
	c.x = l->ori.x - 0.0;
	c.y = l->ori.y - 0.0;
	c.z = l->ori.z - 25.0;
	t.x = 0.0;
	t.y = 0.0;
	t.z = -1.0;
	norme(&t);
	res = -((t.x * c.x + t.y * c.y + t.z * c.z + 1) /
				(t.x * l->dir.x  + t.y * l->dir.y + t.z * l->dir.z));
	if (res >= 0.0)
		shor.x = res;
	return (shor);
}

void			indent(t_ray *l, t_cam *c, double x, double y)
{
	double		x_i;
	double		y_i;

	x_i = VPW / WIN_X;
	y_i = VPH / WIN_Y;
	l->dir.x = c->view.x + c->right.x * x_i * x - c->up.x * y_i * y;
	l->dir.y = c->view.y + c->right.y * x_i * x - c->up.y * y_i * y;
	l->dir.z = c->view.z + c->right.z * x_i * x - c->up.z * y_i * y;
}

int				trace(void *img, char *str)
{
	t_ray		ray;
	t_cam		cam;
	t_vec		index;

	ray.ori.x = POV_X;
	ray.ori.y = POV_Y;
	ray.ori.z = POV_Z;
	init_obj(&ray, str);
	view(&ray, &cam);
	index.y = 0.0;
	while (index.y <= WIN_Y)
	{
		index.x = 0.0;
		while (index.x <= WIN_X)
		{
			indent(&ray, &cam, index.x, index.y);
			norme(&ray.dir);
			check_obj(&ray, img, &index);
			index.x++;
		}
		index.y++;
	}
	return (0);
}
