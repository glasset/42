/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:01:43 by glasset           #+#    #+#             */
/*   Updated: 2014/02/11 15:48:08 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "rtv.h"

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
	c->x = l->ori.x - obj->point.x;
	c->y = l->ori.y - obj->point.y;
	c->z = l->ori.z - obj->point.z;
}

void		shor_plans(t_vec *shor, double a, double i)
{
	if (a < 0)
		return ;
	if (shor->x == -1.0)
	{
		shor->y = i;
		shor->x = a;
	}
	else if (a < shor->x)
	{
		shor->x = a;
		shor->y = i;
	}
}

void		shor_dist(double a, double b, t_vec  *shor, double i)
{
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			a = b;
	}
	else if (a < 0 && b < 0)
		return ;
	else if (a < 0)
		a = b;
	if (shor->x == -1.0)
	{
		shor->x = a;
		shor->y = i;
	}
	else if (a < shor->x)
	{
			shor->y = i;
			shor->x = a;
	}
}
