/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:34:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/05 13:56:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void			mouse_event_leave(t_env *e)
{
	ft_error(1, e, "Deleting objects...");
}

void			mouse_event_ray_trace(t_env *e)
{
	draw_image(e);
	e->cur_screen = RAY_TRACE;
}
