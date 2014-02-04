/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:59:37 by glasset           #+#    #+#             */
/*   Updated: 2014/02/04 16:39:13 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
# define WIN_X 720
# define WIN_Y 480
# define POV_X (WIN_X / 2)
# define POV_Y (WIN_Y / 2)

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_mlx;

typedef struct			s_dot
{
	int					x;
	int					y;
	int					z;
}						t_dot;

typedef struct			s_vec
{
	int					x;
	int					y;
	int					d;
}						t_vec;

int						out_px_to_img(void *img, int x, int y);
#endif /* !RTV_H */
