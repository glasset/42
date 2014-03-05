/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:57:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 12:05:40 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

double			inter_sphere(t_mesh *mesh, t_ray *ray)
{
	t_sphere	*sphere;
	t_vector	tmp;
	double		a_b_c[3];
	double		d;

	sphere = &mesh->prim.sphere;
	tmp = sub(ray->pos, sphere->pos);
	a_b_c[0] = square_length(ray->dir);
	a_b_c[1] = 2 * dot(ray->dir, tmp);
	a_b_c[2] = square_length(tmp) - pow(sphere->radius, 2);
	d = determinant(a_b_c[0], a_b_c[1], a_b_c[2]);
	if (d >= 0)
		return (d);
	return (-1);
}

double			inter_plan(t_mesh *mesh, t_ray *ray)
{
	t_plan		*plan;
	double		d;

	plan = &mesh->prim.plan;
	d = -(dot(plan->normal, sub(ray->pos, plan->pos))
		/ dot(plan->normal, ray->dir));
	if (d >= 0)
		return (d);
	return (-1);
}

double			inter_cylinder(t_mesh *mesh, t_ray *ray)
{
	t_cylinder	*cyl;
	t_vector	tmp;
	double		a_b_c[3];
	double		d;

	cyl = &mesh->prim.cylinder;
	tmp = sub(ray->pos, cyl->pos);
	a_b_c[0] = pow(ray->dir.x, 2) + pow(ray->dir.y, 2);
	a_b_c[1] = 2 * (ray->dir.x * tmp.x + ray->dir.y * tmp.y);
	a_b_c[2] = pow(ray->pos.x, 2) + pow(ray->pos.y, 2) - pow(cyl->radius, 2);
	d = determinant(a_b_c[0], a_b_c[1], a_b_c[2]);
	if (d >= 0)
		return (d);
	return (-1);
}

double			inter_cone(t_mesh *mesh, t_ray *ray)
{
	t_cone		*con;
	double		a_b_c[3];
	double		d;

	con = &mesh->prim.cone;
	a_b_c[0] = pow(ray->dir.x, 2) + pow(ray->dir.y, 2)
		- pow(ray->dir.z, 2) * pow(tan(con->coeff), 2);
	a_b_c[1] = (2 * (ray->dir.x * ray->pos.x + ray->dir.y * ray->pos.y))
		- (2 * ray->dir.z * ray->pos.z * pow(tan(con->coeff), 2));
	a_b_c[2] = pow(ray->pos.x, 2) + pow(ray->pos.y, 2)
		- (pow(ray->pos.z, 2) * pow(tan(con->coeff), 2));
	d = determinant(a_b_c[0], a_b_c[1], a_b_c[2]);
	if (d >= 0)
		return (d);
	return (-1);
}
/*
double			inter_triangle(t_mesh *mesh, t_ray *ray)
{
	t_triangle	*tri;
	t_vector	w;
	t_vector	tmp;
	double		d;
	double		a;
	double		b;
	double		t;

	tri = &mesh->prim.triangle;
	normalize(&ray->dir);
	if (!(d = -dot(&ray->dir, &tri->normal))) // si le triangle est parallele au rayon, on return 0
		return (0);
	w.x = ray->pos.x - tri->v1.x;
	w.y = ray->pos.y - tri->v1.y;
	w.z = ray->pos.z - tri->v1.z;
	mul_vec(&tmp, &w, &tri->v3);
	a = -dot(&tmp, &ray->dir) / d;
	mul_vec(&tmp, &tri->v2, &w);
	b = -dot(&tmp, &ray->dir) / d;
	mul_vec(&tmp, &tri->v2, &tri->v3);
	t = dot(&tmp, &w) / d;
	if (a > 0 && b > 0 && a + b <= 1)
		return (t);
	return (0);
}*/
