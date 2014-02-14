/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:59:37 by glasset           #+#    #+#             */
/*   Updated: 2014/02/14 19:11:16 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RTV_H
# define RTV_H
# include "libft.h"
# include <unistd.h>

# define VALUE 300.0
# define WIN_X (VALUE * 4.0)
# define WIN_Y (VALUE * 3.0)

# define VPD 1.0
# define VPH 0.35
# define VPW 0.5

# define POV_X 0.0
# define POV_Y 5.0
# define POV_Z -10.0

/*
**	Mlx
*/
typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_mlx;

int						put_px_to_img(void *img, int x, int y, int r, int g, int b);

/*
**	Vector
*/
typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

/*
**	Object
*/
typedef struct			s_obj
{
	t_vec				point;
	t_vec				norme;
	double				o_r;
	t_vec				color;
}						t_obj;

/*
**	Ray
*/
typedef struct			s_ray
{
	t_vec				ori;
	t_vec				dir;
	t_vec				vec;
	t_obj				*obj;
	int					size_obj_s;
	int					size_obj_p;
}						t_ray;

/*
** Cam
*/
typedef struct			s_cam
{
	double				width;
	double				height;
	double				dist;
	t_vec				campos;
	t_vec				up;
	t_vec				right;
	t_vec				view;
}						t_cam;

/*
**	vector.c
*/
int						trace(void *img, char *str);

/*
**	init(2).c
*/
void					print_px(t_ray *ray, void *img, t_vec *index);
void					init_obj(t_ray *ray, char *str);
void					init_plans(t_ray *ray, int fd);
void					color(char *str, t_vec *color);
/*
**	obj.c
*/
t_vec					sphere(t_ray *l, t_vec *dir, t_vec *ori); // +25lignes !!!
t_vec					plan(t_ray *l, t_vec *dir, t_vec *ori);

/*
**	tool.c
*/
void					shor_plans(t_vec *shor, double a, double i);
int						shor_dist(double a, double b, t_vec *shor, double i);
void					norme(t_vec *l);
void					init_ori_obj(t_vec *c, t_vec *ori, t_obj *obj);
void					find_dot(t_vec *c, double dist, t_vec *ori, t_vec *dir);

/*
**	light.c
*/
double				ft_light(t_vec *c, t_vec *light);
t_vec				shadow(t_ray *ray, t_vec *point, int bol, t_vec *light);
double				find_light(t_ray *ray, double dist, double index, int bol);
#endif /* !RTV_H */
