/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:05:46 by glasset           #+#    #+#             */
/*   Updated: 2014/01/26 23:20:59 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "filler.h"

int				ft_abs(t_dot xy, t_dot p2, int y1, int x2)
{
	int			a1;
	int			a2;

	a1 = (x2 - xy.x) + (y1 - xy.y);
	a2 = (x2 - p2.x) + (y1 - p2.y);
	if (a1 < a2)
		return (1);
	return (0);
}

int				print(t_env *e, int x, int y, int tmp)
{
	if (tmp != 0)
	{
		if ((x + e->piece_size.x) >= e->board_size)
			x = x - e->board_size;
		if ((y + e->piece_size.y) > e->board_size_len)
			y = y - e->board_size_len;
		ft_putnbr(x);
		write(1, " ", 1);
		ft_putnbr(y);
		write(1, "\n", 1);
		return (0);
	}
	write(1, "0 0\n", 4);
	return (1);
}

void			freedom(char **tab)
{
	int			i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

int				main(void)
{
	t_env		e;

	ft_read(&e);
	return (0);
}

