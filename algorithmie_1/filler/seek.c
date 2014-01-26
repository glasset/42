/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 13:11:27 by glasset           #+#    #+#             */
/*   Updated: 2014/01/26 23:28:32 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "filler.h"

void			check_board(t_env *e)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	i = 0;
	e->board_pst = (t_dot *)malloc(sizeof(t_dot) *
			(e->board_size * e->board_size_len));
	while (e->board[x])
	{
		y = 0;
		while (e->board[x][y])
		{
			if (e->board[x][y] == e->player || e->board[x][y] == e->player + 32)
			{
				e->board_pst[i].x = x;
				e->board_pst[i++].y = y;
			}
			y++;
		}
		x++;
	}
	e->nbr_board = i;
}

t_dot			ajust(t_env *e, int x, int y, int x2, int y2)
{
	t_dot		m;

	m.x = x + x2;
	m.y = y + y2;
	if (y + y2 > (e->board_size_len - 1))
		m.y = m.y - e->board_size_len;
	if (x + x2 > (e->board_size - 1))
		m.x = m.x - e->board_size;
	return (m);
}

t_dot			better_pos(t_env *e, t_dot save, int x, int y)
{
	t_dot		tmp;

	tmp.x = x;
	tmp.y = y;
	if (ft_abs(tmp, save, (e->board_size_len / 2), (e->board_size / 2)) != 0)
	{
		save.x = x;
		save.y = y;
	}
	return (save);
}

t_dot			check_piece(t_env *e, int x, int y2, t_dot m)
{
	t_dot		p;
	t_dot		check;

	check.y = 0;
	check.x = 0;
	m.x = 0;
	while (m.x < e->piece_size.x)
	{
		m.y = 0;
		while (m.y < e->piece_size.y)
		{
			p = ajust(e, x, y2, m.x, m.y);
			if (e->piece[m.x][m.y] == '*')
			{
				if (e->board[p.x][p.y] == e->player
						|| e->board[p.x][p.y] == e->player + 32)
					check.x++;
				else if (e->board[p.x][p.y] != '.')
					check.y++;
			}
			m.y++;
		}
		m.x++;
	}
	return (check);
}

int				use_piece(t_env *e)
{
	t_dot		m;
	t_dot		check;
	t_dot		save;
	t_dot		b;
	int			tmp;

	tmp = 0;
	b.x = 0;
	while (b.x < e->board_size)
	{
		b.y = 0;
		while (b.y < e->board_size_len)
		{
			check = check_piece(e, b.x, b.y, m);
			if (check.y == 0 && check.x == 1 && tmp++ < 2)
				save = b;
			else if (check.y == 0 && check.x == 1)
				save = better_pos(e, save, b.x, b.y);
			b.y++;
		}
		b.x++;
	}
	return (print(e, save.x, save.y, tmp));
}
