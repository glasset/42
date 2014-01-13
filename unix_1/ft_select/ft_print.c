/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:54:52 by glasset           #+#    #+#             */
/*   Updated: 2014/01/11 17:17:18 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

static void		print_soft(char *opt, char *str)
{
	tputs(tgetstr(opt, NULL), 1, tputs_putchar);
	write(isatty(1), &(*str), ft_strlen(str));
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

static void		print_all(char *str, t_lst *print, int zu)
{
	if (zu == 1)
	{
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
		write(isatty(1), &(*str), ft_strlen(str));
		tputs(tgetstr("me", NULL), 1, tputs_putchar);
	}
	else
	{
		if (print->bol == 0)
			write(isatty(1), &*print->str, ft_strlen(print->str));
		else if (print->bol == 1)
			print_soft("us", print->str);
		else if (print->bol == 2)
			print_soft("mr", print->str);
		else if (print->bol == 3)
			print_all(print->str, print, 1);
	}
}

static int		use(int ok)
{
	char		*str;

	if (ok == -1)
	{
		str = "ESC = exit | SPACE = (un)select | RETURN = submit selection\n";
		write(isatty(1), &(*str), ft_strlen(str));
	}
	return (1);
}

static int		check(char *str, int max_size, int len, int cuw)
{
	if (ft_backn(len) != 0)
	{
		write(isatty(1), "\n", 1);
		cuw = 0;
	}
	else
	{
		if (ft_backli(max_size, cuw) == 0)
			ft_tab(str, max_size);
		else
		{
			write(isatty(1), "\n", 1);
			cuw = 0;
		}
	}
	return (cuw);
}

int				print(t_lst *print, int len, int max_size)
{
	int			t[3];

	t[0] = -1;
	t[1] = 0;
	t[2] = 1;
	while (use(t[0]) && (++t[0] < len) && (ft_sizeof(max_size, len) != 1))
	{
		if (print->bol != 4)
		{
			print_all(print->str, print, 0);
			t[2] = check(print->str, max_size, len, t[2]);
			t[2]++;
		}
		else
			t[1]++;
		print = print->next;
	}
	if (ft_finalp(t[1], len, t[2]) == -1)
		return (-1);
	return (0);
}

