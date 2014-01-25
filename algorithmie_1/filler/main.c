/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:05:46 by glasset           #+#    #+#             */
/*   Updated: 2014/01/25 18:00:09 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "filler.h"

int				ft_abs(t_dot p1, t_dot p2, int y1, int x2)
{
	int			a1;
	int			a2;

	a1 = (x2 - p1.x) + (y1 - p1.y);
	a2 = (x2 - p2.x) + (y1 - p2.y);
	if (a1 < a2)
		return (1);
	return (0);
}

void			resize(t_env *e)
{
	int			i;

	i = 1;
	while (i < e->nbr_piece)
	{
		e->piece_pst[i].x = e->piece_pst[i].x - e->piece_pst[0].x;
		e->piece_pst[i].y = e->piece_pst[i].y - e->piece_pst[0].y;
		i++;
	}
}

void			print(t_env *e, int pos)
{
	if (e->piece_pst[0].x != 0)
		e->board_pst[pos].x = e->board_pst[pos].x - e->piece_pst[0].x;
	if (e->piece_pst[0].y != 0)
		e->board_pst[pos].y = e->board_pst[pos].y - e->piece_pst[0].y;
	if ((e->board_pst[pos].x + e->piece_size.x) > e->board_size)
		e->board_pst[pos].x = e->board_pst[pos].x - e->board_size;
	if ((e->board_pst[pos].y + e->piece_size.y) > e->board_size_len)
		e->board_pst[pos].y = e->board_pst[pos].y - e->board_size_len;
	ft_putnbr(e->board_pst[pos].x);
	write(1, " ", 1);
	ft_putnbr(e->board_pst[pos].y);
	write(1, "\n", 1);
}

void		freedom(t_env *e)
{
	int		i;

	i = 0;
	if (e->piece)
	{
		while (e->piece[i])
			free(e->piece[i++]);
		free(e->piece);
	}
}

int			main(void)
{
	t_env	e;

	ft_read(&e);
	return (0);
}

