/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:34:31 by glasset           #+#    #+#             */
/*   Updated: 2014/01/08 18:49:08 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_select.h"

void		space(t_lst *arg, int len)
{
	int		i;

	i = 0;
	while (i < len && arg->bol != 1)
	{
		if (arg->bol == 4)
		{
			arg = arg->next;
			i++;
		}
		if (arg->bol == 1 || arg->bol == 3)
			break;
		arg = arg->next;
		i++;
	}
	if (arg->bol == 3)
		arg->bol = 0;
	else
		arg->bol = 2;
	if (arg->next->bol == 2)
		arg->next->bol = 3;
	else
		arg->next->bol = 1;
}

void		up(t_lst *arg, int len)
{
	int		i;

	i = 0;
	while ((i < len) && (arg->bol != 1 || arg->bol != 3))
	{
		if (arg->bol == 4)
		{
			arg = arg->next;
			i++;
		}
		if (arg->bol == 1 || arg->bol == 3)
			break;
		arg = arg->next;
		i++;
	}
	if (arg->bol == 3)
		arg->bol = 2;
	else
		arg->bol = 0;
	if (arg->prev->bol == 2)
		arg->prev->bol = 3;
	else
		arg->prev->bol = 1;
}

void		down(t_lst *arg, int len)
{
	int		i;

	i = 0;
	while ((arg->bol != 1 || arg->bol != 3) && (i < len))
	{
		if (arg->bol == 4)
		{
			arg = arg->next;
			i++;
		}
		if (arg->bol == 1 || arg->bol == 3)
			break;
		ft_putnbr(arg->bol);
		write(1, "d", 1);
		arg = arg->next;
		i++;
	}
	if (arg->bol == 3)
		arg->bol = 2;
	else
		arg->bol = 0;
	if (arg->next->bol == 2)
		arg->next->bol = 3;
	else
		arg->next->bol = 1;
}

void		backdel(t_lst *arg, int len)
{
	int		i;

	i = 0;
	if (!arg)
		exit(0);
	while (i++ < len && arg->bol != 3)
	{
		if (arg->bol == 4)
		{
			arg = arg->next;
			i++;
		}
		if (arg->bol == 3 || arg->bol == 1)
			break;
		arg = arg->next;
	}
	arg->bol = 4;
	if (arg->next->bol == 2)
		arg->next->bol = 3;
	else if (arg->next->bol == 4)
		arg->bol = 4;
	else
		arg->next->bol = 1;
}

