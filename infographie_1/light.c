/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:48:11 by glasset           #+#    #+#             */
/*   Updated: 2014/02/12 14:44:18 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "rtv.h"
#include <stdio.h>
void			light(t_vec *c, t_vec *shor)
{
	t_vec		light;
	double		a;
	double dist;

	light.x = -50.0;
	light.y = 10.0;
	light.z = -10.0;
	norme(c);
	dist = sqrt(pow(light.x, 2.0) + pow(light.y, 2.0) + pow(light.z, 2.0));
//	norme(&light);
	a = 0.4 * (c->x * light.x + c->y * light.y + c->z *light.z) * 0.452;
/*	if (acos(a) == 90)
		shor->y = a + 0.451 * dist + 0.574 * pow(dist, 2.0);
	else if (acos(a) > 90)
		shor->y = 0.0;
	else if (acos(a) == 0)
		shor->y = 0.0;
	else if (acos(a) < 90)*/
		shor->y = a + 0.451 * dist + 0.574 * pow(dist, 2.0);
}

