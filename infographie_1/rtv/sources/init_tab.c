/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:51:57 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/27 18:26:11 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static void		init_types(t_env *e)
{
	e->inter_tab[T_SPHERE] = inter_sphere;
	e->inter_tab[T_PLAN] = inter_plan;
	e->inter_tab[T_CYLINDER] = inter_cylinder;
	e->inter_tab[T_CONE] = inter_cone;
}

static void		init_diffuses(t_env *e)
{
	e->diffuse_tab[T_SPHERE] = diffuse_sphere;
//	e->diffuse_tab[T_PLAN] = diffuse_plan;
//	e->diffuse_tab[T_CYLINDER] = diffuse_cylinder;
//	e->diffuse_tab[T_CONE] = diffuse_cone;
}

void			init_tab(t_env *e)
{
	init_types(e);
	init_diffuses(e);
}
