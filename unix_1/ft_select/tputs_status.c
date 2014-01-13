/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 17:35:09 by glasset           #+#    #+#             */
/*   Updated: 2014/01/11 18:53:56 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <termios.h>
#include <termcap.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "ft_select.h"

void			tputs_status(int status)
{
	if (status == ON)
	{
		tputs(tgetstr("ti", NULL), 1, tputs_putchar);
		tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	}
	else if (status == OFF)
	{
		tputs(tgetstr("ve", NULL), 1, tputs_putchar);
		tputs(tgetstr("cl", NULL), 1, tputs_putchar);
		tputs(tgetstr("te", NULL), 1, tputs_putchar);
	}
}

void			sigstepre(int sig)
{
	char		cp[2] = {term.c_cc[VSUSP], 0};

	if (sig == SIGTSTP)
	{
		tputs(tgetstr("cl", NULL), 1 , tputs_putchar);
		tputs_status(OFF);
		term = init(term, 0);
		tcsetattr(0, 0, &term);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
	else if (sig == SIGCONT)
	{
		tputs_status(ON);
		term = init(term, 1);
		tcsetattr(0, 0, &term);
		tputs(tgetstr("cl", NULL), 1 , tputs_putchar);
		print(ard->start, ard->len, ard->max_size);
	}
}
