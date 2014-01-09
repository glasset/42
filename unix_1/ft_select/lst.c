/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:00:55 by glasset           #+#    #+#             */
/*   Updated: 2014/01/08 18:49:09 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_select.h"

void				del_tlst(t_lst *cur)
{
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
}

l_lst				*lst_new(void)
{
	l_lst			*tmp;

	tmp = (l_lst *)malloc(sizeof(l_lst));
	if (tmp)
	{
		tmp->max_size = 0;
		tmp->len = 0;
		tmp->end = NULL;
		tmp->start = NULL;
	}
	return (tmp);
}

l_lst				*lst_add_end(l_lst *l_x, char *str, int bol)
{
	t_lst			*tmp;

	if (l_x)
	{
		tmp = (t_lst *)malloc(sizeof(t_lst));
		if (tmp)
		{
			tmp->str = str;
			tmp->bol = bol;
			tmp->next = NULL;
			if (l_x->end == NULL)
			{
				tmp->prev = NULL;
				l_x->start = tmp;
				l_x->end = tmp;
			}
			else
			{
				l_x->end->next = tmp;
				tmp->prev = l_x->end;
				l_x->end = tmp;
			}
			if (l_x->max_size < (int)ft_strlen(str))
			{
				l_x->max_size = ft_strlen(str);
			}
			l_x->len++;
		}
		l_x->end->next = l_x->start;
		l_x->start->prev = l_x->end;
	}
	return (l_x);
}

