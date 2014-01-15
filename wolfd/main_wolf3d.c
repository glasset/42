/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 15:46:12 by fcorbel           #+#    #+#             */
/*   Updated: 2014/01/07 16:36:22 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "header_wolf3d.h"

int				main(int argc, char **argv)
{
	t_env		e;

	if (argc < 2)
		error("Error : No map.");
	init_e(&e, argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "wolf3d");
	mlx_loop_hook(e.mlx, draw_img, &e);
	mlx_loop(e.mlx);
	return (0);
}

void			error(char *s)
{
	if (s)
		write(2, &(*s), ft_strlen(s));
	write(2, "\n", 1);
	exit(0);
}
