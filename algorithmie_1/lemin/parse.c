/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset </var/mail/glasset>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 12:42:33 by glasset           #+#    #+#             */
/*   Updated: 2014/03/22 13:00:17 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void			init(t_env *e)
{
			seek_room(e, 2, "e");
			e->room->start->back = "e";
			e->room->start->weight = 0;
}

void			make(char **cord, int status, t_env *e)
{
	int			*xy;

	xy = (int *)malloc(sizeof(int) *2);
	if (!cord)
		error();
	if (status == 0)
		make_tube(cord, e, 0);
	else
	{
		xy[0] = ft_atoi(cord[1]);
		xy[1] = ft_atoi(cord[2]);
		e->room = lst_add_end(e->room, cord[0], xy, status);
	}
}

int				check_ants(char *line, t_env *e)
{
	if (e->ants == -1)
		e->ants = ft_atoi(line);
	else
		return (-1);
	return (0);
}

char			char_split(int status)
{
	if (status == END || status == START || status == ROOM)
		return (' ');
	else
		return ('-');
}
