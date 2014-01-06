/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 15:27:46 by glasset           #+#    #+#             */
/*   Updated: 2014/01/06 18:58:22 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <termios.h>
#include <termcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_select.h"

int						tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

l_lst					*moove(l_lst *arg, l_lst *select)
{
	char				buffer[2048];
	struct termios		term;
	char				read_char[5];
	int					i;
	int					z;
	t_lst				*a2;

	i = 0;
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (0);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	print_tlst(arg->start, -1);
	while (!(*(unsigned int *)read_char == 27))
	{
		ft_bzero(read_char, 5);
		read(0, read_char, 4);
		if ((*(unsigned int *)read_char == 4348699))
		{
			if (i == (int)arg->len)
				i = 0;
			tputs(tgetstr("cl", NULL), 1, tputs_putchar);
			print_tlst(arg->start, i++);
		}
		if ((*(unsigned int *)read_char == 4283163))
		{
			if (i == 0)
				i = arg->len;
			tputs(tgetstr("cl", NULL), 1, tputs_putchar);
			print_tlst(arg->start, --i);
		}
		if ((*(unsigned int *)read_char == 32))
		{
			z = 0;
			a2 = arg->start;
			while (z++ < i)
				a2 = a2->next;
			select = lst_add_end(select, a2->str);
		}
	}
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	return (select);
}
