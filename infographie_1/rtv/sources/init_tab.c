/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:51:57 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/19 17:14:24 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static void		init_types(t_env *e)
{
	e->inter_tab[T_SPHERE] = inter_sphere;
	e->inter_tab[T_PLAN] = inter_plan;
	e->inter_tab[T_CYLINDER] = inter_cylinder;
	e->inter_tab[T_CONE] = inter_cone;
	e->inter_tab[T_PARABOLE] = inter_parabole;
	e->inter_tab[T_HYPERBOLE] = inter_hyperbole;
}

static void		init_normals(t_env *e)
{
	e->normals[T_SPHERE] = normal_sphere;
	e->normals[T_PLAN] = normal_plan;
	e->normals[T_CYLINDER] = normal_cylinder;
	e->normals[T_CONE] = normal_cone;
	e->normals[T_PARABOLE] = normal_parabole;
	e->normals[T_HYPERBOLE] = normal_cone;
}

void			init_tab(t_env *e)
{
	init_types(e);
	init_normals(e);
}
