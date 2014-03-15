/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djidji.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 12:02:14 by glasset           #+#    #+#             */
/*   Updated: 2014/03/15 16:07:50 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

int				seek_nop(t_env *e, int pos, char *name)
{
	t_ch		*s;

	name = name;
	s = e->room->start;
	if (pos > 0)
	{
		while (s->pos != START)
			s = s->next;
	}
	if (s->weight > -1)
		return (0);
	return (1);
}


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
	t_ch		*tmp;

	tmp = e->room->start;
	while (ft_strcmp(tmp->name, curr))
			tmp = tmp->next;
	x = tmp->xy[0];
	y = tmp->xy[1];
	while (ft_strcmp(tmp->name, next))
			tmp = tmp->next;
	if (x > tmp->xy[0])
		x -= tmp->xy[0];
	else
		x = tmp->xy[0] - x;
	if (y > tmp->xy[1])
		y -= tmp->xy[1];
	else
		y = tmp->xy[1] - y;
	return (y + x);
}

void				update(t_env *e, int w, char *curr, char *next)
{
	t_ch		*tmp;

	tmp = e->room->start;
	while (ft_strcmp(tmp->name, next))
			tmp = tmp->next;
	if (tmp->back == NULL)
	{
		tmp->back = curr;
		tmp->weight = w;
	}
	else if (w < tmp->weight)
	{
		tmp->back = curr;
		tmp->weight = w;
	}
}

void			shoort(t_env *e)
{
	size_t		i;
	int			W;
	int			x = 1;

	while (seek_nop(e, START, "s"))
	{
		if (x ==1)
		{
			seek_room(e, 2, "e");
			e->room->start->back = "e";
			e->room->start->weight = 0;
			x = 0;
		}
		i = 0;
		while (i < e->room->start->tube->len)
		{
			W = lenght(e, e->room->start->name, e->room->start->tube->start->name);
			update(e, W, e->room->start->name, e->room->start->tube->start->name);
			i++;
			e->room->start->tube->start = e->room->start->tube->start->next;
			if (i == e->room->start->tube->len)
				e->room->start = e->room->start->next;
		}
	}
}
