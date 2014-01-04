/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:00:41 by glasset           #+#    #+#             */
/*   Updated: 2013/12/29 18:36:28 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "pushswap.h"

int			is_sort(l_lst *lx, char c)
{
	t_lst	*la;

	la = lx->start;
	while (la != NULL && la->next)
	{
		if (c == 'a' && la->num > la->next->num)
			return (1);
		if (c == 'b' && la->num < la->next->num)
			return (1);
		la = la->next;
	}
	return (0);
}

l_lst		*l_sort(l_lst *la, l_lst *lb)
{
	if (is_sort(la, 'a') == 0)
		return (la);
	while (is_sort(la, 'a'))
	{
		while (la->start && is_sort(la, 'a'))
		{
			if (la->start->next && la->start->num > la->start->next->num)
				s_swap(&la, &lb, 'a');
			if (la->start->next && la->start->num > la->end->num)
				r_swap(&la, &lb, 'a', ' ');
			else
				p_swap(&la, &lb, 'b');
		}
		while (lb->start->next)
		{
			if (lb->start->next
					&& lb->start->num < lb->start->next->num)
				s_swap(&la, &lb, 'b');
			if (lb->start->num < lb->end->num)
				r_swap(&la, &lb, 'b', ' ');
			else
			{
				p_swap(&la, &lb, 'a');
			}
		}
	}
	p_swap(&la, &lb, 'a');
	return (la);
}
