/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:01:15 by glasset           #+#    #+#             */
/*   Updated: 2013/12/29 16:05:02 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "pushswap.h"

void		p_switch(l_lst **la, l_lst **lb)
{
	int		tmp;

	tmp = (*lb)->start->num;
	(*la) = lst_add_start((*la), tmp);
	if ((*lb)->start->next)
		(*lb)->start = (*lb)->start->next;
	else
		(*lb)->start->next = NULL;
	(*lb)->start->prev = NULL;
}

int			p_swap(l_lst **la, l_lst **lb, char c)
{
	if (*lb && c == 'a')
		p_switch(la, lb);
	else if (*la && c == 'b')
	{
		if (*lb)
			p_switch(lb, la);
		else
		{
			(*lb)->start = (*la)->start;
			(*la)->start = (*la)->start->next;
			(*la)->start->prev = NULL;
		}
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, " ", 1);
	return (0);
}
