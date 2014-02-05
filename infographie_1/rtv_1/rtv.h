/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:59:37 by glasset           #+#    #+#             */
/*   Updated: 2014/02/05 18:05:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
# define VALUE 200.0
# define WIN_X 4.0 * VALUE
# define WIN_Y 3.0 * VALUE


# define XLEFT -12.0
# define XRIGHT 12.0
# define YTOP 9.0
# define YBOT -9.0

# define POV_X 0.0
# define POV_Y 0.0
# define POV_Z -10.0

# define START_X 0.0;
# define START_Y 0.0;
# define START_Z 10.0;
# define RAY_S   5.0;

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
	double				d;
}						t_vec;

/*
**	Ray
*/
typedef struct			s_ray
{
	t_vec				ori;
	t_vec				dir;
	t_vec				vec;
	double				len;
}						t_ray;

/*
** Cam
*/
typedef struct			s_cam
{
	double				campos;
	double				camdir;
	double				camright;
	double				camdown;
}						t_cam;

int						trace(void *img, double p_x, double p_y);

#endif /* !RTV_H */
