/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 11:20:04 by glasset           #+#    #+#             */
/*   Updated: 2014/01/06 18:58:20 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_select.h"
#include <termios.h>
#include <termcap.h>

#include <stdio.h>

int			print_tlst(t_lst *print, int i)
{
	char	*tmp;
	int		t;

	t = 1;
	tmp = print->str;
	while (print->next->str != tmp)
	{
		if (i == 0)
			t = 0;
		if (t == 1)
		{
			write (1, print->str, ft_strlen(print->str));
			write (1, "\n", 1);
			i--;
		}
		else
		{
			tputs(tgetstr("mr", NULL), 1, tputs_putchar);
			write (1, print->str, ft_strlen(print->str));
			tputs(tgetstr("me", NULL), 1, tputs_putchar);
			write (1, "\n", 1);
			t = 1;
			i--;
		}
		print = print->next;
	}
	if (i == 0)
			tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	write (1, print->str, ft_strlen(print->str));
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
	write (1, "\n", 1);
	return (0);
}


int			main(int argc, char **argv)
{
//	int		fd;
	int		i;
	l_lst	*arg;
	l_lst	*select;
	i = 1;
//	fd = open(ttyname(0), O_WRONLY);
	select = lst_new();
	arg = lst_new();
	while (i < argc)
		arg = lst_add_end(arg, argv[i++]);
	select = moove(arg, select);
	while (select->start != select->end)
	{
		write(1, &*(select->start->str), ft_strlen(select->start->str));
		write(1, " ", 1);
		select->start = select->start->next;
	}
	write(1, &*(select->start->str), ft_strlen(select->start->str));
	write(1, "\n", 1);
	return (0);
}

