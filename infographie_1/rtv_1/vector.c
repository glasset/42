/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:56:30 by glasset           #+#    #+#             */
/*   Updated: 2014/02/05 18:05:27 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "rtv.h"

#include <stdio.h>
void			norme(t_ray *l)
{
	l->vec.x = l->dir.x - l->ori.x;
	l->vec.y = l->dir.y - l->ori.y;
	l->vec.z = l->dir.z - l->ori.z;
	l->len = sqrt(pow(l->vec.x, 2.0) + pow(l->vec.y, 2.0) + pow(l->vec.z, 2.0));
	l->vec.x = l->vec.x / l->len;
	l->vec.y = l->vec.y / l->len;
	l->vec.z = l->vec.z / l->len;
	l->dir = l->vec;
}

int				sphere(t_ray *l)
{
	double		a;
	double		b;
	double		c;
	double		x;
	double		y;
	double		z;
	double		s;

	s = RAY_S;
	x = l->ori.x - START_X;
	y = l->ori.y - START_Y;
	z = l->ori.z - START_Z;
	a = pow(l->dir.x, 2.0) + pow(l->dir.y, 2.0) + pow(l->dir.z, 2.0);
	b = 2.0 * (l->dir.x * x + l->dir.y * y + l->dir.z * z);
	c = pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) - pow(s, 2.0);
	x = pow(b, 2) - 4 * a *c;
	if (x < 0)
		return (-1);
	y = (-b + sqrt(x)) / 2 * a;
	z = (-b - sqrt(x)) / 2 * a;
	if (y > z)
		return (z);
	else
		return (y);
}

int				trace(void *img, double p_x, double p_y)
{
	t_ray		ray;
	double		x;
	double		y;
	ray.ori.x = POV_X;
	ray.ori.y = POV_Y;
	ray.ori.z = POV_Z;

	y = 0.0;
	while (y < WIN_Y)
	{
		x = 0.0;
		while (x < WIN_X)
		{
		ray.dir.x = XLEFT + 0.5 * p_x + x * p_x;
		ray.dir.y = YTOP - 0.5 * p_y - y * p_y;
		ray.dir.z = 0.0;
		norme(&ray);
		if (sphere(&ray) == -1)
			put_px_to_img(img, x, y, 255, 0, 0);
		else
			put_px_to_img(img, x, y, 0, 0, 200);
		x++;
		}
		y++;
	}
	return (0);
}
