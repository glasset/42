/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:54:52 by glasset           #+#    #+#             */
/*   Updated: 2014/01/07 21:08:04 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"
#include <termios.h>
#include <termcap.h>
#include <unistd.h>

void		print_soft(char *opt, char *str)
{
	tputs(tgetstr(opt, NULL), 1, tputs_putchar);
	ft_putstr(str);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);

}

int			print(t_lst *print, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (print->bol == 0)
			ft_putstr(print->str);
		else if (print->bol == 1)
			print_soft("us", print->str);
		else if (print->bol == 2)
			print_soft("mr", print->str);
		else if (print->bol == 3)
		{
			tputs(tgetstr("us", NULL), 1, tputs_putchar);
			tputs(tgetstr("mr", NULL), 1, tputs_putchar);
			ft_putstr(print->str);
			tputs(tgetstr("me", NULL), 1, tputs_putchar);
		}
		print = print->next;
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

