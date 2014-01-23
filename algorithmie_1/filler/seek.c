/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 13:11:27 by glasset           #+#    #+#             */
/*   Updated: 2014/01/23 18:01:58 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "filler.h"

static void		first_p(t_env *e)
{
	int			x;
	int			y;

	x = 0;
	while (e->board[x])
	{
		y = 0;
		while (e->board[x][y])
		{
			if (e->board[x][y] == e->player)
			{
				e->i.x = x;
				e->i.y = y;
			}
			if (e->board[x][y] == (e->player + 32))
			{
				e->i.x = x;
				e->i.y = y;
			}
			y++;
		}
		x++;
	}
}

void			first_piece(t_env *e)
{
	first_p(e);
	if (e->piece[0][0] == '*')
	{
		ft_putnbr(e->i.x);
		write(1, " ", 1);
		ft_putnbr(e->i.y);
		write(1, "\n", 1);
	}
	else if (e->piece[0][1] == '*')
	{
		ft_putnbr((e->i.x));
		write(1, " ", 1);
		ft_putnbr((e->i.y - 1));
		write(1, "\n", 1);
	}
	else
		exit(0);
}

