#include "ray_tracer.h"

static void		compute_pix(t_env *e, t_color *col, double dx, double dy)
{
	t_color		tmp;
	t_compute	c;

	compute_ray(e, e->aa.ray, dx, dy);
	if (intersect_mesh(e, e->aa.ray, e->aa.mesh, e->aa.inter))
	{
		c = init_compute(*e->aa.ray, *e->aa.mesh, *e->aa.inter, *e->aa.ray);
		tmp = compute_color(e, c, 0, 1.0);
		col->r += tmp.r * 0.9;
		col->g += tmp.g * 0.9;
		col->b += tmp.b * 0.9;
	}
}

t_color			compute_aa(t_env *e, t_ray *ray, t_mesh **mesh, t_vertex *inter)
{
	t_color		col;
	double		dx;
	double		dy;
	t_compute	c;

	e->aa.ray = ray;
	e->aa.mesh = mesh;
	e->aa.inter = inter;
	dx = e->aa.dx;
	dy = e->aa.dy;
	c = init_compute(*ray, *mesh, *inter, *ray);
	col = compute_color(e, c, 0, 1.0);
	compute_pix(e, &col, e->aa.x + dx, e->aa.y);
	compute_pix(e, &col, e->aa.x + 2 * dx, e->aa.y);
	compute_pix(e, &col, e->aa.x, e->aa.y + dy);
	compute_pix(e, &col, e->aa.x, e->aa.y + 2 * dy);
	compute_pix(e, &col, e->aa.x - dx, e->aa.y);
	compute_pix(e, &col, e->aa.x - 2 * dx, e->aa.y);
	compute_pix(e, &col, e->aa.x, e->aa.y - dy);
	compute_pix(e, &col, e->aa.x, e->aa.y - 2 * dy);
	compute_pix(e, &col, e->aa.x + dx, e->aa.y + dy);
	compute_pix(e, &col, e->aa.x - dx, e->aa.y - dy);
	compute_pix(e, &col, e->aa.x + dx, e->aa.y - dy);
	compute_pix(e, &col, e->aa.x - dx, e->aa.y + dy);
	col = prod_col_val(col, (1.0 / 13.0));
	return (col);
}
