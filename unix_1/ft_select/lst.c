/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:00:55 by glasset           #+#    #+#             */
/*   Updated: 2014/01/11 17:34:43 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_select.h"

l_lst				*lst_new(void)
{
	l_lst			*tmp;

	tmp = (l_lst *)malloc(sizeof(l_lst));
	if (tmp)
	{
		tmp->max_size = 0;
		tmp->len = 1;
		tmp->end = NULL;
		tmp->start = NULL;
	}
	return (tmp);
}

l_lst				*lst_add_end(l_lst *l_x, char *str, int bol)
{
	t_lst			*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (tmp && l_x)
	{
		tmp->str = str;
		tmp->bol = bol;
		if (l_x->max_size < (int)ft_strlen(str))
			l_x->max_size = ft_strlen(str);
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

