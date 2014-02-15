/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:01:43 by glasset           #+#    #+#             */
/*   Updated: 2014/02/15 18:14:07 by glasset          ###   ########.fr       */
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

void		init_ori_obj(t_vec *c, t_vec *ori, t_vec *point)
{
	c->x = ori->x - point->x;
	c->y = ori->y - point->y;
	c->z = ori->z - point->z;
}

void		find_dot(t_vec *c, double dist, t_vec *ori, t_vec *dir)
{
	c->x = ori->x + dir->x * dist;
	c->y = ori->y + dir->y * dist;
	c->z = ori->z + dir->z * dist;
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

int			shor_dist(double a, double b, t_vec  *shor, double i)
{
	if (i == 0.0)
	{
		shor->x = 0.0;
		return (1);
	}
	if (a >= 0 && b >= 0)
	{
		if (a > b)
			a = b;
	}
	else if (a < 0 && b < 0)
		return (0);
	else if (a < 0)
		a = b;
	if (shor->x == -1.0)
		shor->x = a;
	else if (a < shor->x)
		shor->x = a;
	return (1);
}
