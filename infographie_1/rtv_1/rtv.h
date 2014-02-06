/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:59:37 by glasset           #+#    #+#             */
/*   Updated: 2014/02/06 18:20:25 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
# include "libft.h"
# include <unistd.h>

# define WIN_X 640.0
# define WIN_Y 480.0


# define VPD 1.0
# define VPH 0.35
# define VPW 0.5

# define POV_X 0.0
# define POV_Y 0.0
# define POV_Z -50.0

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

int						trace(void *img, char *str);
void					init_ori_obj(t_vec *c, t_ray *l, t_obj *obj);
void					init_obj(t_ray *ray, char *str);
#endif /* !RTV_H */
