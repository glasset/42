/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/05 13:55:43 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"

void	key_event_esc(t_env *e)
{
	if (e->cur_screen == MENU)
		ft_error(1, e, "Deleting objects...");
	else if (e->cur_screen == RAY_TRACE)
		e->cur_screen = MENU;
	expose_hook(e);
}
