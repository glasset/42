/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:59:09 by glasset           #+#    #+#             */
/*   Updated: 2014/01/09 17:41:03 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"
#include <termios.h>
#include <termcap.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ioctl.h>

int					tputs_putchar(int c)
{
	write(isatty(1), &c, 1);
	return (1);
}

static void			run(l_lst *arg, char *read_char)
{
	if (*(unsigned int *)read_char != 10)
		ft_options(read_char, arg);
	tputs(tgetstr("cl", NULL), 1 , tputs_putchar);
	print(arg->start, arg->len, arg->max_size);
}

struct termios		init(struct termios term, int i)
{
	if (i == 1)
	{
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
	}
	else if (i == 0)
	{
		term.c_lflag |= ICANON;
		term.c_lflag |= ECHO;
	}
	return (term);
}

l_lst				*ft_select(l_lst *arg)
{
	char			buf[2048];
	struct termios	term;
	char			read_char[5];

	if (tgetent(buf, getenv("TERM")) < 1)
		exit(0);
	tcgetattr(0, &term);
	term = init(term, 1);
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1 , tputs_putchar);
	print(arg->start, arg->len, arg->max_size);
	while (!(*(unsigned int *)read_char == 10))
	{
		ft_bzero(read_char, 5);
		read(0, read_char, 4);
		run(arg, read_char);
	}
	tputs(tgetstr("cl", NULL), 1 , tputs_putchar);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	term = init(term, 0);
	tcsetattr(0, 0, &term);
	return (arg);
}

