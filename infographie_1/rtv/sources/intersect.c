/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:40:56 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/27 18:24:42 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

int				compute_shadow(t_env *e, t_ray *ray, t_mesh *mesh)
{
	int			i;

	i = -1;
	while (++i < e->nb_mesh)
	{
		if (&e->meshes[i] == mesh)
				return (0);
		if (e->inter_tab[e->meshes[i].type](&e->meshes[i], ray))
			return (1);
	}
	return (0);
}

#include <stdio.h>
t_color			compute_color(t_env *e, t_ray *ray, t_mesh *mesh)
{
	t_ray		ray_light;
	t_color		pix;
	t_color		tmp;
	int			i;

	i = -1;
	ray_light.pos = add(ray->pos, prod_val(ray->dir, ray->dist));
	pix.r = mesh->color.r * e->ambient;
	pix.g = mesh->color.g * e->ambient;
	pix.b = mesh->color.b * e->ambient;
	while (++i < e->nb_light)
	{
		ray_light.dir = sub(e->lights[i].pos, ray_light.pos);
		// voir ici pour la transparence
		if (compute_shadow(e, &ray_light, mesh))
			continue ;
		else
		{
			ray_light.dist = magnitude(ray_light.dir);
			tmp = e->diffuse_tab[mesh->type](&e->lights[i], mesh, &ray_light);
			pix.r += tmp.r;
			pix.g += tmp.g;
			pix.b += tmp.b;
			// attenuation
		}
	}
	pix.r *= (1 / (0.9 + 0.3 / ray_light.dist + 0.7 / (ray_light.dist * ray_light.dist)));
	pix.g *= (1 / (0.9 + 0.3 / ray_light.dist + 0.7 / (ray_light.dist * ray_light.dist)));
	pix.b *= (1 / (0.9 + 0.3 / ray_light.dist + 0.7 / (ray_light.dist * ray_light.dist)));
	return (pix);
}

int				intersect_mesh(t_env *e, t_ray *ray, t_mesh **mesh)
{
	int			i;
	double		tmp;

	i = -1;
	(void)mesh; // delete
	ray->dist = MAX_DBL;
	while (++i < e->nb_mesh)
	{
		if ((tmp = e->inter_tab[e->meshes[i].type](&e->meshes[i], ray)))
		{
			if (tmp >= 0 && tmp < ray->dist)
			{
				ray->dist = tmp;
				*mesh = &e->meshes[i];
			}
		}
	}
	if (ray->dist < MAX_DBL)
		return (1);
	return (0);
}
