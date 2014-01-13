/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:46:52 by glasset           #+#    #+#             */
/*   Updated: 2014/01/11 15:15:16 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_select.h"
#include <sys/ioctl.h>
#include <termios.h>
#include <termcap.h>

void				exitclear(t_term term)
{
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	term = init(term, 0);
	tcsetattr(0, 0, &term);
	exit(0);
}

f					*ft_function(void)
{
	f				*ft;

	ft = malloc(sizeof(ft) * 4);
	ft[0] = &space;
	ft[1] = &up;
	ft[2] = &down;
	ft[3] = &backdel;
	return (ft);
}

int					check_key(unsigned int str)
{
	unsigned int	cmp[5];
	int				i;

	i = 0;
	cmp[0] = 32;
	cmp[1] = 4283163;
	cmp[2] = 4348699;
	cmp[3] = 127;
	cmp[4] = 2117294875;
	while (i < 5)
	{
		if (cmp[i] == str)
		{
			if (i == 4)
				return (3);
			return (i);
		}
		i++;
	}
	return (-1);
}

int					ft_options(char *str, l_lst *arg)
{
	f				*ft;

	ft = ft_function();
	if ((*(unsigned int *)str == 27))
		return (-1);
	if (check_key((*(unsigned int *)str)) != -1)
		ft[check_key((*(unsigned int *)str))](arg->start, arg->len);
	return (0);
}
