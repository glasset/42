#include <math.h>
#include "ray_tracer.h"

t_color			specular(t_env *e, t_light *light, t_mesh *mesh, t_ray *ray, t_ray *cam_ray)
{
	t_color		col;
	t_vector	normal;
	t_vector	r;
	double		d;
	double		spec;

	col = init_color(0.0, 0.0, 0.0);
	if (mesh->spec > 0.0001)
	{
		normal = e->normals[mesh->type](mesh, &ray->pos);
		ray->dir.x += perlin_ocean(e, ray->pos, mesh->type, SPE); //mesh->type a changer OCEAN
		r = sub(ray->dir, prod_val(normal, 2.0 * dot(ray->dir, normal)));
		d = dot(cam_ray->dir, normalize(r));
		if (d > 0.0001)
		{
			spec = pow(d, 30) * mesh->spec;
			col = prod_col_val(light->color, spec);
		}
	}
	return (col);
}
