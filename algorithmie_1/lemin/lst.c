/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:00:55 by glasset           #+#    #+#             */
/*   Updated: 2014/03/22 12:46:00 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "lemin.h"

t_lst				*lst_new(void)
{
	t_lst			*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->len = 1;
		tmp->end = NULL;
		tmp->start = NULL;
	}
	return (tmp);
}

t_lst				*lst_add_end(t_lst *l_x, char *name, int *xy, int pos)
{
	t_ch			*tmp;

	tmp = (t_ch *)malloc(sizeof(t_ch));
	if (tmp && l_x)
	{
		tmp->weight = -1;
		tmp->back = NULL;
		tmp->name = name;
		tmp->xy = xy;
		tmp->tube = NULL;
		tmp->pos = pos;
		if (l_x->start == NULL)
		{
			l_x->start = tmp;
			l_x->start->next = tmp;
			l_x->start->prev = tmp;
			return (l_x);
		}
		tmp->next = l_x->start->next;
		tmp->prev = l_x->start;
		tmp->next->prev = tmp;
		l_x->start->next = tmp;
		l_x->start = tmp;
		l_x->len++;
	}
	return (l_x);
}

