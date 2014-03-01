/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:23:00 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/27 18:26:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "objects.h"

# define WIDTH			1080
# define HEIGHT			720
# define NAME			"Raytracer"
# define NB_KEY_EVENT	1
# define NB_TYPE		4
# define MAX_DBL		1.7976931348623158e+308
# define X_INDENT		0.5 / (double)WIDTH
# define Y_INDENT		0.35 / (double)HEIGHT

/*
** Error messages
*/
# define E_MEM			"Not enough memory."
# define E_MLX			"MLX fail init."
# define E_WIN			"WIN fail init."

/*
** Keys
*/
# define ESC			65307

typedef struct s_env	t_env;
typedef void			(key_event)(t_env *e);
typedef double			(*inter)(t_mesh *mesh, t_ray *ray);
typedef t_color			(*diffuse)(t_light *light, t_mesh *mesh, t_ray *ray);

/*
** keycode : key value
** is_press : 1 | 0
** event : event function
*/
typedef struct		s_key
{
	int				keycode;
	int				is_press;
	key_event		*event;
}					t_key;

/*
** ptr : pointer image data
** img : image
** bpp : bit per pixel
** size_line : size of line
** endian : endian
** width : image's width
** height : image's height
** max_size : precompute to avoid obsolete calcul
*/
typedef struct		s_img
{
	void			*ptr;
	char			*img;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				max_size;
}					t_img;

/*
** mlx : pointer to mlx
** win : pointer to win
** screen : image to display on screen
*/
struct				s_env
{
	void			*mlx;
	void			*win;
	double			ambient;
	t_color			color;
	t_vertex		look_at_point;
	t_vertex		up_left;
	t_cam			cam;
	t_img			image;
	int				nb_mesh;
	t_mesh			*meshes;
	int				nb_light;
	t_light			*lights;
	t_key			key_events[NB_KEY_EVENT];
	inter			inter_tab[NB_TYPE];
	diffuse			diffuse_tab[NB_TYPE];
};

/*
** Inits
*/
t_env		*init_env(char *path);
void		init_events(t_env *e);
void		init_tab(t_env *e);
void		init_scene(t_env *e, char *path);
void		init_image(void *mlx, t_img *i, int width, int height);
t_vector	init_vec(double x, double y, double z);

/*
** Display
*/
void		draw_image(t_env *e);

/*
** Helpers
*/
void		ft_error(int b_exit, t_env *e, char *str);
int			ft_strlen(char *s);

/*
** Intersection
*/
int			intersect_mesh(t_env *e, t_ray *ray, t_mesh **mesh);
double		inter_sphere(t_mesh *mesh, t_ray *ray);
double		inter_plan(t_mesh *mesh, t_ray *ray);
double		inter_cylinder(t_mesh *mesh, t_ray *ray);
double		inter_cone(t_mesh *mesh, t_ray *ray);

t_vector	normal_cone(t_cone *con, t_vector *v);
t_vector	normal_cylinder(t_cylinder *cyl, t_vector *v);
t_vector	normal_sphere(t_sphere *sph, t_vector *v);

/*
** Light
*/
t_color			compute_color(t_env *e, t_ray *ray, t_mesh *mesh);
t_color			diffuse_sphere(t_light *light, t_mesh *mesh, t_ray *ray);
t_color			diffuse_cyl(t_light *light, t_mesh *mesh, t_ray *ray);
t_color			diffuse_triangle(t_light *light, t_mesh *mesh, t_ray *ray);
t_color			diffuse_plan(t_light *light, t_mesh *mesh, t_ray *ray);

/*
** Events
*/
int			expose_hook(t_env *e);
int			key_hook_release(int keycode, t_env *e);
int			key_hook_press(int keycode, t_env *e);
void		key_event_esc(t_env *e);

/*
** Math
*/
double		dot(t_vector u, t_vector v);
double		square_length(t_vector u);
double		magnitude(t_vector u);
t_vector	normalize(t_vector u);
double		determinant(double a, double b, double c);
t_vector	add(t_vector u, t_vector v);
t_vector	sub(t_vector u, t_vector v);
t_vector	prod(t_vector u, t_vector v);
t_vector	cross(t_vector u, t_vector v);
t_vector	prod_val(t_vector u, double val);

#endif /* !RAY_TRACER_H */
