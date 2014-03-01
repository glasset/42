/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:56:47 by glasset           #+#    #+#             */
/*   Updated: 2014/03/01 19:48:26 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"

void			init_scene(t_env *e, char *path)
{
	(void)path;
	e->nb_mesh = 2;
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh);
	e->meshes[0].type = T_SPHERE;
	e->meshes[0].prim.sphere.radius = 1;
	e->meshes[0].prim.sphere.pos = init_vec(0, 0, 0);
	e->meshes[0].color.r = 0.0;
	e->meshes[0].color.g = 0.2;
	e->meshes[0].color.b = 0.7;
	e->meshes[0].diff = 1.0;
	e->meshes[1].type = T_SPHERE;
	e->meshes[1].prim.sphere.radius = 3;
	e->meshes[1].prim.sphere.pos = init_vec(-5, -5, -8);
	e->meshes[1].color.r = 0.7;
	e->meshes[1].color.g = 0.0;
	e->meshes[1].color.b = 0.7;
	e->meshes[1].diff = 0.8;
	e->cam.pos = init_vec(0, 0, 40);
	e->look_at_point = init_vec(0, 0, 0);
	e->ambient = 0.1;
	e->nb_light = 2;
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light);
	e->lights[0].color.r = 0.7;
	e->lights[0].color.g = 0.7;
	e->lights[0].color.b = 0.7;
	e->lights[0].pos = init_vec(40, 40, 40);
	e->lights[1].color.r = 0.7;
	e->lights[1].color.g = 0.7;
	e->lights[1].color.b = 0.7;
	e->lights[1].pos = init_vec(40, 40, 50);
}
