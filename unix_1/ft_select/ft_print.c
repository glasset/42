/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:54:52 by glasset           #+#    #+#             */
/*   Updated: 2014/01/08 18:49:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>

void		print_soft(char *opt, char *str)
{
	tputs(tgetstr(opt, NULL), 1, tputs_putchar);
	write(isatty(1), &(*str), ft_strlen(str));
	tputs(tgetstr("me", NULL), 1, tputs_putchar);

}

int			print(t_lst *print, int len, int max_size)
{
	int		i;

	i = 0;
	max_size = 0;
	write(isatty(1), "ESC = exit prog | SPACE = (un)select | RETURN = valid \n", 55);
	while (i < len)
	{
		if (print->bol != 4)
		{
			if (print->bol == 0)
				write(isatty(1), &*print->str, ft_strlen(print->str));
			else if (print->bol == 1)
				print_soft("us", print->str);
			else if (print->bol == 2)
				print_soft("mr", print->str);
			else if (print->bol == 3)
			{
				tputs(tgetstr("us", NULL), 1, tputs_putchar);
				tputs(tgetstr("mr", NULL), 1, tputs_putchar);
				write(isatty(1), &*print->str, ft_strlen(print->str));
				tputs(tgetstr("me", NULL), 1, tputs_putchar);
			}
			write(isatty(1), "\n", 1);
		}
		else
			max_size++;
		i++;
		print = print->next;
	}
	if (max_size == len)
		exit(0);
	return (0);
}

