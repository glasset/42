/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:59:09 by glasset           #+#    #+#             */
/*   Updated: 2014/04/29 16:55:14 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "ft_select.h"

int					tputs_putchar(int c)
{
	write(isatty(1), &c, 1);
	return (1);
}

static int			run(l_lst *arg, char *read_char)
{
	if (*(unsigned int *)read_char != 10)
	{
		if (ft_options(read_char, arg) == -1)
			return (-1);
	}
	tputs(tgetstr("cl", NULL), 1 , tputs_putchar);
	if (print(arg->start, arg->len, arg->max_size) == -1)
		return (-1);
	return (0);
}

void				sigw(int sig)
{
	if (sig == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1 , tputs_putchar);
		print(ard->start, ard->len, ard->max_size);
	}
	else if (sig == SIGINT)
	{
		tputs_status(OFF);
		exitclear(term);
	}
}

t_term				init(t_term term, int i)
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
	char			read_char[5];

	if (tgetent(buf, getenv("TERM")) < 1)
		exit(0);
	tcgetattr(0, &term);
	term = init(term, 1);
	tcsetattr(0, 0, &term);
	tputs_status(ON);
	print(arg->start, arg->len, arg->max_size);
	signal(SIGWINCH, &sigw);
	signal(SIGINT, &sigw);
	signal(SIGTSTP, &sigstepre);
	signal(SIGCONT, &sigstepre);
	while (!(*(unsigned int *)read_char == 10))
	{
		ft_bzero(read_char, 5);
		read(0, read_char, 4);
		if (run(arg, read_char) == -1)
			exitclear(term);
	}
	tputs_status(OFF);
	term = init(term, 0);
	tcsetattr(0, 0, &term);
	return (arg);
}

