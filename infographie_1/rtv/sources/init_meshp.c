/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_meshp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 14:50:21 by glasset           #+#    #+#             */
/*   Updated: 2014/03/04 19:58:55 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my.h"

int				init_p(t_env *e, char *str, int c)
{
	char		**tmp;

	tmp = ft_strsplit(str, '[');
	if (no_name(tmp) == -4)
		return (-4);
	e->meshes[c].type = T_PLAN;
	e->meshes[c].prim.plan.pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	e->meshes[c].prim.plan.normal = init_vec(ft_atoi(tmp[4]),
	ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	e->meshes[c].color = get_color(tmp[7]);
	e->meshes[c].diff = ft_atod(tmp[8]);
	return (0);
}

int				init_cyl(t_env *e, char *str, int c)
{
	char		**tmp;

	tmp = ft_strsplit(str, '[');
	if (no_name(tmp) == -4)
		return (-4);
	e->meshes[c].type = T_CYLINDER;
	e->meshes[c].prim.cylinder.radius = ft_atoi(tmp[4]);
	e->meshes[c].prim.cylinder.pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	e->meshes[c].prim.cylinder.dir = init_vec(ft_atoi(tmp[5]),
	ft_atoi(tmp[6]), ft_atoi(tmp[7]));
	e->meshes[c].color = get_color(tmp[8]);
	e->meshes[c].diff = ft_atod(tmp[9]);
	return (0);
}

int				init_cone(t_env *e, char *str, int c)
{
	char		**tmp;

	tmp = ft_strsplit(str, '[');
	if (no_name(tmp) == -4)
		return (-4);
	e->meshes[c].type = T_CONE;
	e->meshes[c].prim.cone.coeff = ft_atoi(tmp[7]);
	e->meshes[c].prim.cone.pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	e->meshes[c].prim.cone.dir = init_vec(ft_atoi(tmp[4]),
	ft_atoi(tmp[5]), ft_atoi(tmp[6]));
	e->meshes[c].color = get_color(tmp[8]);
	e->meshes[c].diff = ft_atod(tmp[9]);
	return (0);
}

int				init_s(t_env *e, char *str, int c)
{
	char		**tmp;

	tmp = ft_strsplit(str, '[');
	if (no_name(tmp) == -4)
		return (-4);
	e->meshes[c].type = T_SPHERE;
	e->meshes[c].prim.sphere.radius = ft_atoi(tmp[4]);
	e->meshes[c].prim.sphere.pos = init_vec(ft_atoi(tmp[1]),
	ft_atoi(tmp[2]), ft_atoi(tmp[3]));
	e->meshes[c].color = get_color(tmp[5]);
	e->meshes[c].diff = ft_atod(tmp[6]) ;
	return (0);
}
