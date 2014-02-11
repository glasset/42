/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:48:11 by glasset           #+#    #+#             */
/*   Updated: 2014/02/11 17:31:03 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv.h"

void			light(t_vec *c, t_vec *shor)
{
	t_vec		light;
	double		a;

	light.x = c->x - 10.0;
	light.y = c->y - 0.0;
	light.z = c->z - 5.0;
	norme(c);
	norme(&light);
	a = c->x * light.x + c->y * light.y + c->z * light.z;
	if (a <= 0)
		shor->y = 1;
	else
		shor->y = 9 * 0.78855 * a;
}

