/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 15:32:00 by glasset           #+#    #+#             */
/*   Updated: 2013/12/21 11:22:28 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "fdf.h"

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit (0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*t;
	t_point	**s;
	int		u;

	if (argc == 1)
	{
		ft_printusage(argv[0]);
		return (0);
	}
	t = malloc(sizeof(t_mlx));
	if (ft_open(argv[1], &s) == -1)
		return (0);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, 1500, 1000, "FdF");
	u = ft_check(s);
	ft_display_all(s, &t, u);
	free((void **)s);
	mlx_key_hook(t->win, key_hook, &t);
	mlx_loop(t->mlx);
	free(t);
	return (0);
}

