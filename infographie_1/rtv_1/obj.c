/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:56:11 by glasset           #+#    #+#             */
/*   Updated: 2014/02/15 16:33:56 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "rtv.h"

t_vec			sphere(t_ray *l, t_vec *dir, t_vec *ori, int index)
{
	t_vec		c;
	t_vec		res;
	t_vec		shor;
	double		s;
	int			i;
	shor.z = 42.0;
	shor.x = -1.0;
	i = 0;
	if (i == index)
			i++;
	while (i < l->size_obj_s)
	{
		init_ori_obj(&c, ori, &l->obj[i]);
		s = l->obj[i].o_r;
		res.x = pow(dir->x, 2.0) + pow(dir->y, 2.0) + pow(dir->z, 2.0);
		res.y = 2.0 * (dir->x * c.x + dir->y * c.y + dir->z * c.z);
		res.z = pow(c.x, 2.0) + pow(c.y, 2.0) + pow(c.z, 2.0) - pow(s, 2.0);
		c.x = pow(res.y, 2.0) - 4.0 * res.x * res.z;
		if (c.x < 0.0 && shor.z == 42.0)
			shor.z = -1.0;
		else if (c.x >= 0.0)
		{
			if (shor_dist(((-res.y + sqrt(c.x)) / 2 * res.x),
					((-res.y - sqrt(c.x)) / 2 * res.x), &shor, c.x) == 1)
				shor.z = i;
		}
		i++;
		if (i == index)
			i++;
	}
	return (shor);
}

t_vec			plan(t_ray *l, t_vec *dir, t_vec *ori, int index)
{
	t_vec		shor;
	t_vec		c;
	int			i;
	double		res;

	i = l->size_obj_s;
	shor.x = -1.0;
	shor.y = -1.0;
	if (i == index)
		i++;
	while (i < (l->size_obj_p + l->size_obj_s))
	{
		init_ori_obj(&c, ori, &l->obj[i]);
		norme(&l->obj[i].norme);
		res = -((l->obj[i].norme.x * c.x + l->obj[i].norme.y * c.y +
					l->obj[i].norme.z * c.z) /
				(l->obj[i].norme.x * dir->x  + l->obj[i].norme.y * dir->y +
				 l->obj[i].norme.z * dir->z));
		shor_plans(&shor, res, (double)i);
		i++;
		if (i == index)
			i++;
	}
	return (shor);
}
