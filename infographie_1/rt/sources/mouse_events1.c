/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:34:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/26 19:28:16 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"
#include "video.h"

void			mouse_event_choose_scene(t_env *e)
{
	if (!e->cur_button->name)
	{
		ft_putstr("This button is empty !\n");
		return ;
	}	
	ft_putstr("Reading scene : ");
	ft_putstr(e->cur_button->name);
	ft_putstr("\n");
	// init_scene ici avec en parametre la chaine vers la scene, il faut verifier si le fichier existe toujours, et ajotuer le nom de dossier devant scenes/
	if (e->cur_button)
	{
		// add iinit_scene if
		init_scene(e, e->cur_button->name);
		if (e->video)
			create_pics(e);
		else
			draw_image(e);
	}
}

void			mouse_event_left_slide_scene(t_env *e)
{
	if (e->cur_screen == MENU)
		e->cur_screen = MENU + (e->nb_panel - 1);
	else
		e->cur_screen -= 1;
	e->cur_panel = e->cur_screen - MENU;
}

void			mouse_event_right_slide_scene(t_env *e)
{
	if (e->cur_screen == MENU + (e->nb_panel - 1))
		e->cur_screen = MENU;
	else
		e->cur_screen += 1;
	e->cur_panel = e->cur_screen - MENU;
}
