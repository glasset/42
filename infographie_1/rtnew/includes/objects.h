/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:49:36 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/27 18:26:07 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_vertex		t_vector;

/*
** Vertex : 3d point
** Vertices : 3d points
*/
typedef struct		s_vertex
{
	double			x;
	double			y;
	double			z;
}					t_vertex;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_ray
{
	t_vertex		pos;
	t_vector		dir;
	double			dist;
}					t_ray;

/*
** pos : position
** dir : direction
** right && up : define the top
*/
typedef struct		s_cam
{
	t_vertex		pos;
	t_vector		dir;
	t_vector		right;
	t_vector		up;
}					t_cam;

typedef struct		s_light
{
	t_vertex		pos;
	t_color			color;
}					t_light;

typedef struct		s_cylinder
{
	t_vertex		pos;
	t_vector		dir;
	double			radius;
}					t_cylinder;

typedef struct		s_cone
{
	t_vertex		pos;
	t_vector		dir;
	double			coeff;
}					t_cone;

typedef struct		s_sphere
{
	t_vertex		pos;
	double			radius;
}					t_sphere;

typedef struct		s_plan
{
	t_vertex		pos;
	t_vector		normal;
}					t_plan;

typedef enum		e_type
{
	T_SPHERE, T_PLAN, T_CYLINDER, T_CONE
}					t_type;

/*
** Primitives
*/
typedef union		u_prim
{
	t_sphere		sphere;
	t_plan			plan;
	t_cylinder		cylinder;
	t_cone			cone;
}					t_prim;

/*
** Mesh : 3d object
** Meshes : 3d objects
** diff : diffuse coeff between 0 and 1
** spec : specular coeff between 0 and 1
** refl : reflection coeff between 0 and 1
** refr : refraction coeff between 0 and 1
*/
typedef struct		s_mesh
{
	t_prim			prim;
	t_color			color;
	double			diff;
	double			spec;
	double			refl;
	double			refr;
	int				type;
}					t_mesh;

#endif /* !OBJECTS_H */
