/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djidji.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:02:14 by glasset           #+#    #+#             */
/*   Updated: 2014/03/15 15:13:52 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

void			seek_room(t_env *e, int pos, char *name)
{
	if (pos > 0)
	{
		while (e->room->start->pos != pos)
			e->room->start = e->room->start->next;
	}
	else
	{
		if (name == NULL)
			exit(0);
		while (ft_strcmp(e->room->start->name, name))
			e->room->start = e->room->start->next;
	}
}

int				lenght(t_env *e, char *curr, char *next)
{
	int			x;
	int			y;

	while (ft_strcmp(e->room->start->name, curr))
			e->room->start = e->room->start->next;
	x = e->room->start->xy[0];
	y = e->room->start->xy[1];
	while (ft_strcmp(e->room->start->name, next))
			e->room->start = e->room->start->next;
	if (x > e->room->start->xy[0])
		x -= e->room->start->xy[0];
	else
		x = e->room->start->xy[0] - x;
	if (y > e->room->start->xy[1])
		y -= e->room->start->xy[1];
	else
		y = e->room->start->xy[1] - y;
	return (y + x);
}

int				check_start(t_env *e, int pos)
{
	seek_room(e, pos, "s");
	if (e->room->start->weight > -1)
			return (1);
	return (0);
}

void			shoort(t_env *e)
{
	size_t		i;
	int			W;
	char		*back;
	int			x = 1;

	while (check_start(e, 1) == 0)
	{
		i = 0;
		if (x ==1)
		{
			seek_room(e, 2, "e");
			e->room->start->back = "e";
			e->room->start->weight = 0;
			x = 0;
		}
		while (i < e->room->start->tube->len)
		{
			back = e->room->start->name;
			W = lenght(e, e->room->start->name, e->room->start->tube->start->name);
			if ( e->room->start->weight == -1 || W < e->room->start->weight)
			{
				e->room->start->weight = W;
				e->room->start->back = back;
			}
			i++;
			e->room->start->tube->start = e->room->start->tube->start->next;
		}
	}
}
