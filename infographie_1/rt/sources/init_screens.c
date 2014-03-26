/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:56:10 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/26 19:03:14 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
#include <dirent.h>
#include "ray_tracer.h"
#include "menu.h"

void				set_button_name(t_env *e, int i)
{
	DIR				*dp;
	struct dirent	*ep;
	int				k;
	int				button;

	if ((dp = opendir("scenes/")))
	{
		k = 0;
		button = 0;
		while ((ep = readdir(dp)) && k < (i * 4) + 4)
		{
			if (k < (i * 4) && check_scene_name(ep->d_name))
				k++;
			else if (check_scene_name(ep->d_name))
			{
				if (ep->d_name[0] != '.')
					e->screens[MENU + i].buttons[5 + k - i * 4].name = ft_strdup(ep->d_name);
				button++;
				k++;
			}
		}
		closedir(dp);
	}
}

static int			init_menu(t_env *e, int i)
{
	int				k;

	e->screens[MENU + i].nb_button = 9;
	if (!(e->screens[MENU + i].buttons = (t_button *)malloc(sizeof(t_button) * e->screens[MENU + i].nb_button)))
		return (0);
	e->screens[MENU + i].background = init_img_xpm(e->mlx, "images/menu_panel.xpm" , 1080, 720);
	e->screens[MENU + i].buttons[0] = init_button(70, 420, &mouse_event_left_slide_scene, init_img_xpm(e->mlx, "images/arrow_left.xpm", 130, 240));
	e->screens[MENU + i].buttons[1] = init_button(233 + (4 * 160), 420, &mouse_event_right_slide_scene, init_img_xpm(e->mlx, "images/arrow_right.xpm", 130, 240));
	e->screens[MENU + i].buttons[2] = init_button(380, 330, &mouse_event_options, init_img_xpm(e->mlx, "images/options.xpm", 294, 94));
	e->screens[MENU + i].buttons[3] = init_button(70, 660, &mouse_event_void, init_img_xpm(e->mlx, "images/load_progress.xpm", 940, 40));
	e->screens[MENU + i].buttons[3].check_box = 1;
	e->screens[MENU + i].buttons[4] = init_button(710, 330, &key_event_esc, init_img_xpm(e->mlx, "images/quit.xpm", 294, 94));
	k = 0;
	while (k < 4)
	{
		e->screens[MENU + i].buttons[k + 5] = init_button(233 + (k % 4) * 161, 420, &mouse_event_choose_scene, init_img_xpm(e->mlx, "images/vignettes.xpm", 130, 240));
		k++;
	}
	set_button_name(e, i);
	return (1);
}

static int			init_options(t_env *e)
{
	e->screens[OPTIONS].nb_button = 6;
	e->screens[OPTIONS].buttons = (t_button *)malloc(sizeof(t_button) * 5);
	if (!e->screens[OPTIONS].buttons)
		return (0);
	e->screens[OPTIONS].buttons[0] = init_button(WIDTH / 2 - 100, 300, &check_event_ocean, init_img_xpm(e->mlx, "images/wtf.xpm", 294, 94));
	e->screens[OPTIONS].buttons[0].check_box = 1;
	e->screens[OPTIONS].buttons[1] = init_button(WIDTH / 2 - 100, 350, &check_event_aa, init_img_xpm(e->mlx, "images/anti_aliasing.xpm", 294, 94));
	e->screens[OPTIONS].buttons[1].check_box = 1;
	e->screens[OPTIONS].buttons[2] = init_button(WIDTH / 2 - 100, 400, &check_event_cell_shading, init_img_xpm(e->mlx, "images/cell_shading.xpm", 294, 94));
	e->screens[OPTIONS].buttons[2].check_box = 1;
	e->screens[OPTIONS].buttons[3] = init_button(WIDTH / 2 - 100, 450, &check_event_attenuate, init_img_xpm(e->mlx, "images/attenuate.xpm", 294, 94));
	e->screens[OPTIONS].buttons[3].check_box = 1;
	e->screens[OPTIONS].buttons[4] = init_button(WIDTH / 2 - 100, 500, &check_event_video, init_img_xpm(e->mlx, "images/video.xpm", 294, 94));
	e->screens[OPTIONS].buttons[4].check_box = 1;
	e->screens[OPTIONS].buttons[5] = init_button(WIDTH / 2 - 100, 600, &check_event_back, init_img_xpm(e->mlx, "images/back.xpm", 294, 84));
	e->screens[OPTIONS].background = init_img_xpm(e->mlx,
					"images/options_panel.xpm", 1080, 720);
	return (1);
}

static int			init_ray_trace(t_env *e)
{
	init_img(e->mlx, &e->screens[RAY_TRACE].background, WIDTH, HEIGHT);
	return (1);
}

int					init_screens(t_env *e)
{
	int		i;

	e->cur_screen = MENU;
	e->nb_panel = count_panel(e);
	if (!(e->screens = (t_screen *)malloc(sizeof(t_screen) * (4 + e->nb_panel - 1))))
		return (0);
	i = 0;
	while (i < e->nb_panel)
	{
		if (!init_menu(e, i))
			return (0);
		i++;
	}
	if (!init_options(e))
		return (0);
	if (!init_ray_trace(e))
		return (0);
	return (1);
}
