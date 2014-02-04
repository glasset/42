/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 12:00:56 by glasset           #+#    #+#             */
/*   Updated: 2014/02/04 14:55:52 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "rtv.h"

int				key_hook(int keycode)
{
	if (keycode == 65307)
		exit (0);
	return (0);
}

int				main(void)
{
	t_mlx		*t;

	t = malloc(sizeof(t_mlx));
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, WIN_X, WIN_Y, "RTV_1");
	t->img = mlx_new_image(t->mlx, WIN_X, WIN_Y);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_key_hook(t->win, key_hook, &t);
	mlx_loop(t->mlx);
	mlx_destroy_image(t->mlx, t->img);
	return (0);
}
