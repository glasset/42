/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:56:30 by glasset           #+#    #+#             */
/*   Updated: 2014/02/15 16:19:45 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "rtv.h"

static void			view(t_ray *l, t_cam *c)
{
	l->dir.x = 0.0 - l->ori.x;
	l->dir.y = 0.0 - l->ori.y;
	l->dir.z = 1.0 - l->ori.z;
	c->up.x = 0.0;
	c->up.y = 1.0;
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

static void			indent(t_ray *l, t_cam *c, double x, double y)
{
	double			x_i;
	double			y_i;

	x_i = VPW / WIN_X;
	y_i = VPH / WIN_Y;
	l->dir.x = c->view.x + c->right.x * x_i * x - c->up.x * y_i * y;
	l->dir.y = c->view.y + c->right.y * x_i * x - c->up.y * y_i * y;
	l->dir.z = c->view.z + c->right.z * x_i * x - c->up.z * y_i * y;
}

int					trace(t_mlx *t, char *str)
{
	t_ray			ray;
	t_cam			cam;
	t_vec			index;

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
			print_px(&ray, t, &index);
			index.x++;
		}
		index.y++;
	}
	return (0);
}
