/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:59:37 by glasset           #+#    #+#             */
/*   Updated: 2014/02/07 18:22:04 by glasset          ###   ########.fr       */
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

# define POV_X -5.0
# define POV_Y 0.0
# define POV_Z -100.0

/*
**	Object
*/
typedef struct			s_obj
{
	double				o_x;
	double				o_y;
	double				o_z;
	double				o_r;
}						t_obj;


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
**	Ray
*/
typedef struct			s_ray
{
	t_vec				ori;
	t_vec				dir;
	t_vec				vec;
	t_obj				*obj;
	int					size_obj;
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

void					shor_dist(double a, double b, t_vec *shor, double i);
void					norme(t_vec *l);
int						trace(void *img, char *str);
void					init_ori_obj(t_vec *c, t_ray *l, t_obj *obj);
void					init_obj(t_ray *ray, char *str);
t_vec					sphere(t_ray *l);
t_vec					plan(t_ray *l);
void					check_obj(t_ray *ray, void *img, t_vec *index);
#endif /* !RTV_H */
