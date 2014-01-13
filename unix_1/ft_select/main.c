/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 11:20:04 by glasset           #+#    #+#             */
/*   Updated: 2014/01/11 17:07:29 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <termios.h>
#include <termcap.h>
#include <stdio.h>
#include "ft_select.h"

static void			printr(char *str, int curr, int end)
{
		ft_putstr(str);
		if ((curr + 1) != end)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
}

static void			error(char *str)
{
	write(1, "usage: ", 7);
	write(1, &(*str), ft_strlen(str));
	write(1, " arg1 arg2 ...\n", 15);
	exit(0);
}

static int			ft_celement(l_lst *arg)
{
	int				i;
	int				count;
	t_lst			*tmp;

	tmp = arg->start;
	count = 0;
	i = 0;
	while (i < (int)arg->len)
	{
		if (tmp->bol == 2 || tmp->bol == 3)
			count++;
		tmp = tmp->next;
		i++;
	}
	return (count);
}

l_lst				*makelst(l_lst *arg, int argc, char **argv, int x)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		arg = lst_add_end(arg, argv[i++], x);
		x = 0;
	}
	arg->start = arg->start->next;
	return (arg);
}

int					main(int argc, char **argv)
{
	int				x;
	int				i;

	i = 1;
	x = 0;
	if (argc == 1)
		error(argv[0]);
	ard = lst_new();
	ard = makelst(ard, argc, argv, 1);
	ft_select(ard);
	i = 0;
	while (i < (int)ard->len)
	{
		if (ard->start->bol == 2 || ard->start->bol == 3)
				printr(ard->start->str, x++, ft_celement(ard));
		ard->start = ard->start->next;
		i++;
	}
	return (0);
}

