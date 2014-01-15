/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 11:46:55 by fcorbel           #+#    #+#             */
/*   Updated: 2014/01/06 16:06:20 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <unistd.h>
#include "header_wolf3d.h"

int				draw_pixel(void *imlx, int x, int y)
{
	char		*img;
	int			bpp;
	int			size_line;
	int			endian;

	img = mlx_get_data_addr(imlx, &bpp, &size_line, &endian);
	(img[y * size_line + x * bpp / 8]) = 255;
	(img[y * size_line + x * bpp / 8 + 1]) = 255;
	(img[y * size_line + x * bpp / 8 + 2]) = 255;
	return (0);
}

int				draw_ray(void *imlx, int ray_size, int ray_x)
{
	int			y;
	int			y_max;

	y = WIN_Y / 2 - ray_size / 2;
	y_max = WIN_Y / 2 + ray_size / 2;
	while (y <= y_max)
	{
		draw_pixel(imlx, ray_x, y);
		y++;
	}
	return (0);
}

int				draw_img(t_env *e)
{
	void		*imlx;

	imlx = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	draw_ray(imlx, 100, 20);
	sleep(1);
	mlx_put_image_to_window(e->mlx, e->win, imlx, 0, 0);
	mlx_destroy_image(e->mlx, imlx);
	return (0);
}
