/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:48:11 by glasset           #+#    #+#             */
/*   Updated: 2014/02/12 18:20:38 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "rtv.h"
#include <stdio.h>
void			light(t_vec *c, t_vec *shor)
{
	t_vec		light;
	double		dist;
	double		angle;

	light.x = 0.0;
	light.y = 0.0;
	light.z = -10.0;
	c->x -= 0;
	c->y -= 0;
	c->z -= 5;
	norme(c);
	dist = sqrt(pow((light.x - c->x), 2.0) + pow((light.y - c->y), 2.0) +
			pow((light.z - c->z), 2.0));
	angle = acos((c->x * light.x + c->y * light.y + c->z * light.z) /
			(sqrt(pow(c->x, 2.0) + pow(c->y, 2.0) + pow(c->z, 2.0)) *
			 sqrt(pow(light.x, 2.0) + pow(light.y, 2.0) + pow(light.z, 2.0))));
	if (angle > 1.5707)
		shor->y = 0.0;
	else
		shor->y = 1 / (0.9 + angle * dist + pow(angle, 2.0) * pow(dist, 2.0));
	shor->y *= 255;
}

