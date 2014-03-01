#include "ray_tracer.h"

static void		diff_col(t_color *c, t_color *objc, t_color *lic, double diff)
{
	c->r = diff * lic->r * objc->r;
	c->g = diff * lic->g * objc->g;
	c->b = diff * lic->b * objc->b;
}

t_color			diffuse_sphere(t_light *light, t_mesh *mesh, t_ray *ray)
{
	t_color		col;
	t_vector	normal;
	double		d;
	double		diff;

	col.r = 0.0;
	col.g = 0.0;
	col.b = 0.0;
	normal = normal_sphere(&mesh->prim.sphere, &ray->pos);
	d = dot(normalize(ray->dir), normal);
	if (d > 0)
	{
		diff = d * mesh->diff;
		diff_col(&col, &mesh->color, &light->color, diff);
	}
	return (col);
}
/*
t_color			diffuse_cyl(t_light *light, t_mesh *mesh, t_ray *ray)
{
	t_color		col;
	t_vector		normal;
	t_vector		u;
	double		dot;
	double		diff;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	sub_vec(&u, &li->pos, vi);
	normalize(&u);
	normal = normal_cylinder(&obj->prim.cylinder, vi);
	dot = dot_product(&u, &normal);
	if (dot > 0)
	{
		diff = dot * 0.2 * sh;
		diff_col(&col, &obj->color, &li->color, diff);
	}
	return (col);
}

t_color			diffuse_triangle(t_light *light, t_mesh *mesh, t_ray *ray)
{
	t_color		col;
	t_vector		u;
	double		dot;
	double		diff;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	sub_vec(&u, &li->pos, vi);
	normalize(&u);
	dot = dot_product(&u, &obj->prim.triangle.normal);
	if (dot > 0)
	{
		diff = dot * 0.9 * sh;
		diff_col(&col, &obj->color, &li->color, diff);
	}
	return (col);
}

t_color			diffuse_plan(t_light *light, t_mesh *mesh, t_ray *ray)
{
	t_color		col;
	t_vector		u;
	double		dot;
	double		diff;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	sub_vec(&u, &li->pos, vi);
	normalize(&u);
	dot = dot_product(&u, &obj->prim.plan.normal);
	if (dot > 0)
	{
		diff = dot * 0.9 * sh;
		diff_col(&col, &obj->color, &li->color, diff);
	}
	return (col);
}*/
