/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:34:43 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/05 12:56:18 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_vertex		normal_cone(t_mesh *mesh, t_vertex *v)
{
	t_vertex	n;
	t_vertex	tmp;

	tmp.x = v->x;
	tmp.y = v->y;
	tmp.z = mesh->prim.cone.pos.z;
	n = sub(tmp, mesh->prim.cone.pos);
	n = prod_val(n, mesh->prim.cone.coeff);
	return (n);
}

t_vertex		normal_cylinder(t_mesh *mesh, t_vertex *v)
{
	t_vertex	n;
	t_vertex	tmp;

	tmp.x = v->x;
	tmp.y = v->y;
	tmp.z = mesh->prim.cylinder.pos.z;
	n = sub(tmp, mesh->prim.cylinder.pos);
	n = prod_val(n, mesh->prim.cylinder.radius);
	return (n);
}

t_vertex		normal_sphere(t_mesh *mesh, t_vertex *v)
{
	return (normalize(prod_val(sub(*v, mesh->prim.sphere.pos),
					mesh->prim.sphere.radius)));
}

t_vertex		normal_plan(t_mesh *mesh, t_vertex *v)
{
	(void)v;
	return (mesh->prim.plan.normal);
}
