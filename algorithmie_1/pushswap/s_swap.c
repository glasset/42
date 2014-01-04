/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:01:40 by glasset           #+#    #+#             */
/*   Updated: 2013/12/29 16:06:04 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "pushswap.h"

int			s_swap(l_lst **la, l_lst **lb, char c)
{
	int		num;

	if ((*la)->start && (*la)->start->next && (c == 'a' || c == 's'))
	{
		num = (*la)->start->num;
		(*la)->start->num = (*la)->start->next->num;
		(*la)->start->next->num = num;
	}
	if ((*lb)->start && (*lb)->start->next && (c == 'b' || c == 's'))
	{
		num = (*lb)->start->num;
		(*lb)->start->num = (*lb)->start->next->num;
		(*lb)->start->next->num = num;
	}
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, " ", 1);
	return (0);
}
