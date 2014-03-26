/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:39:46 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/26 19:03:14 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "ray_tracer.h"

t_vector		init_vec(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

static void		del_env(t_env *e)
{
	if (!e)
		return ;
	(void)e;
	// del all malloc
	// verifier avec leaks
}

/*
** b_exit : quit
** t_env : environnement to delete
** str : message to display
*/
void			ft_error(int b_exit, t_env *e, char *str)
{
	del_env(e);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	if (b_exit)
	{
		write(2, "Exit.\n", 6);
		exit(1);
	}
}

t_compute		init_compute(t_ray ray, t_mesh *m, t_vertex i, t_ray ray_light)
{
	t_compute	c;

	c.ray = ray;
	c.mesh = m;
	c.inter = i;
	c.ray_light = ray_light;
	return (c);
}

t_env			*init_env(void)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		ft_error(1, e, E_MEM);
	if (!(e->mlx = mlx_init()))
		ft_error(1, e, E_MLX);
	if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, NAME)))
		ft_error(1, e, E_WIN);
	e->check_parse = 0;
	e->progressive_load = 1;
	e->ocean = 0;
	e->aa_active = 0;
	e->cell_shading = 0;
	e->attenuate = 0;
	e->video = 0;
	e->cur_panel = 0;
	e->aa.dx = (double)X_INDENT / 5;
	e->aa.dy = (double)Y_INDENT / 5;
	init_events(e);
	init_tab(e);
	init_screens(e);
	return (e);
}
