#include "ray_tracer.h"

t_vector		normal_cone(t_cone *con, t_vector *v)
{
	t_vector	n;
	t_vector	tmp;

	tmp.x = v->x;
	tmp.y = v->y;
	tmp.z = con->pos.z;
	n = sub(tmp, con->pos);
	n = prod_val(n, con->coeff);
	return (n);
}

t_vector		normal_cylinder(t_cylinder *cyl, t_vector *v)
{
	t_vector	n;
	t_vector	tmp;

	tmp.x = v->x;
	tmp.y = v->y;
	tmp.z = cyl->pos.z;
	n = sub(tmp, cyl->pos);
	n = prod_val(n, cyl->radius);
	return (n);
}

t_vector		normal_sphere(t_sphere *sph, t_vector *v)
{
	return (normalize(prod_val(sub(*v, sph->pos), sph->radius)));
}
