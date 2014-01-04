/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:01:29 by glasset           #+#    #+#             */
/*   Updated: 2013/12/29 16:05:38 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "pushswap.h"

void		r_start(l_lst **lx)
{
	int		tmp;

	tmp = (*lx)->start->num;
	(*lx) = lst_add_end((*lx), tmp);
	(*lx)->start = (*lx)->start->next;
	(*lx)->start->prev = NULL;
}

void		r_end(l_lst **lx)
{
	int		tmp;

	tmp = (*lx)->end->num;
	(*lx)->end = (*lx)->end->prev;
	(*lx)->end->next = NULL;
	(*lx) = lst_add_start((*lx), tmp);
}

int			r_swap(l_lst **la, l_lst **lb, char c, char way)
{
	if (*la && (c == 'a' || c == 'r'))
	{
		if (way == ' ')
			r_start(la);
		else if (way == 'r')
			r_end(la);
	}
	if (*lb && (c == 'b' || c == 'r'))
	{
		if (way == ' ')
			r_start(lb);
		else if (way == 'r')
			r_end(lb);
	}
	if	(way == 'r')
		write(1, "r", 1);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, " ", 1);
	return (0);
}
