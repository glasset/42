/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:40:56 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/19 17:10:12 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

int				compute_shadow(t_env *e, t_ray *ray, t_ray *oldray, t_mesh *mesh)
{
	int			i;
	t_ray		tmp;

	i = -1;
	while (++i < e->nb_mesh)
	{
		if (&e->meshes[i] != mesh)
		{
			tmp.pos = add(oldray->pos, prod_val(oldray->dir, oldray->dist));
			tmp.dir = ray->dir;
			if (e->inter_tab[e->meshes[i].type](&e->meshes[i], &tmp, &tmp) > 0.0001)
				return (1);
		}
	}
	return (0);
}

// creer des fonction pour additioner et multiplier des couleurs
t_color			compute_color(t_env *e, t_ray *ray, t_mesh *mesh, int depth, double refr, t_vertex *inter)
{
	t_ray		ray_light;
	t_color		pix;
	t_color		tmp;
	int			i;

	i = -1;
	ray_light.pos = *inter;
	if (mesh->type == T_SPHERE) // if perlin
	{
		pix = perlin_marble(ray_light.pos.x, ray_light.pos.y, ray_light.pos.z);
		pix.r *= e->ambient;
		pix.g *= e->ambient;
		pix.b *= e->ambient;
	}
	else
	{
		pix.r = mesh->color.r * e->ambient;
		pix.g = mesh->color.g * e->ambient;
		pix.b = mesh->color.b * e->ambient;
	}
	while (++i < e->nb_light)
	{
		ray_light.dir = sub(e->lights[i].pos, ray_light.pos);
		if (compute_shadow(e, &ray_light, ray, mesh))
			continue ;
		else
		{
			ray_light.dist = magnitude(ray_light.dir);
			// if diffuse
			tmp = diffuse(e, &e->lights[i], mesh, &ray_light);
			pix.r += tmp.r;
			pix.g += tmp.g;
			pix.b += tmp.b;
			// if spe
			tmp = specular(e, &e->lights[i], mesh, &ray_light, ray);
			pix.r += tmp.r;
			pix.g += tmp.g;
			pix.b += tmp.b;
		}
	}
	if (mesh->refl > 0.0001)
	{
		tmp = reflection(e, mesh, &ray_light, ray, depth, refr);
		pix.r += tmp.r;
		pix.g += tmp.g;
		pix.b += tmp.b;
	}
	if (mesh->refr > 0.0001)
	{
		tmp = refraction(e, mesh, &ray_light, ray, depth, refr);
		pix.r += tmp.r;
		pix.g += tmp.g;
		pix.b += tmp.b;
	}
	/*
	pix.r *= (1 / (0.9 + 0.9 / ray_light.dist + 0.9 / (ray_light.dist * ray_light.dist)));
	pix.g *= (1 / (0.9 + 0.9 / ray_light.dist + 0.9 / (ray_light.dist * ray_light.dist)));
	pix.b *= (1 / (0.9 + 0.9 / ray_light.dist + 0.9 / (ray_light.dist * ray_light.dist)));
	pix.r = 1.0 - exp(pix.r * -1.5);
	pix.g = 1.0 - exp(pix.g * -1.5);
	pix.b = 1.0 - exp(pix.b * -1.5);
	*/
	return (pix);
}

int				intersect_mesh(t_env *e, t_ray *ray, t_mesh **mesh, t_vertex *m_ver)
{
	t_ray		tmp_ray;
	int			i;
	double		tmp;

	i = -1;
	ray->dist = MAX_DBL;
	while (++i < e->nb_mesh)
	{
		if ((tmp = e->inter_tab[e->meshes[i].type](&e->meshes[i], ray, &tmp_ray)))
		{
			if (tmp >= 0 && tmp < ray->dist)
			{
				ray->dist = tmp;
				*mesh = &e->meshes[i];
				if (m_ver)
					*m_ver = add(tmp_ray.pos, prod_val(tmp_ray.dir, ray->dist));
			}
		}
	}
	if (ray->dist < MAX_DBL)
		return (1);
	return (0);
}