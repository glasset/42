/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:56:10 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/07 16:46:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "ray_tracer.h"

static void			init_img(void *mlx, t_img *i, int width, int height)
{
	i->width = width;
	i->height = height;
	i->ptr = mlx_new_image(mlx, width, height);
	i->img = mlx_get_data_addr(i->ptr, &i->bpp, &i->size_line, &i->endian);
	i->bpp /= 8;
	i->max_size = i->size_line * height + i->bpp * width;
}

static t_img		init_img_xpm(void *mlx, char *path, int width, int height)
{
	t_img			img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img.img = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size_line * height + img.bpp * width;
	return (img);
}

static t_button		init_button(int x, int y, mouse_event *event, t_img img)
{
	t_button		button;

	button.x_pos = x;
	button.y_pos = y;
	button.state = NONE;
	button.img = img;
	button.frame_size = img.height / 2;
	button.event = event;
	return (button);
}

int					init_screens(t_env *e)
{
	e->cur_screen = MENU;
	if (!(e->screens = (t_screen *)malloc(sizeof(t_screen) * 3)))
		return (0);
	e->screens[MENU].nb_button = 2;
	if (!(e->screens[MENU].buttons = (t_button *)malloc(sizeof(t_button) * 2)))
		return (0);
	e->screens[MENU].buttons[0] = init_button(WIDTH / 2 - 100, HEIGHT / 2, &mouse_event_ray_trace, init_img_xpm(e->mlx, "images/buttontrace.xpm", 200, 200));
	e->screens[MENU].buttons[1] = init_button(WIDTH / 2 - 100, HEIGHT / 2 + 150, &mouse_event_leave, init_img_xpm(e->mlx, "images/buttontrace.xpm", 200, 200));
	e->screens[MENU].background = init_img_xpm(e->mlx, "images/background.xpm", 1440, 1080);
	init_img(e->mlx, &e->screens[RAY_TRACE].background, WIDTH, HEIGHT);

	return (1);
}
