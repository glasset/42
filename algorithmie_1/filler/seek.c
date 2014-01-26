/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 13:11:27 by glasset           #+#    #+#             */
/*   Updated: 2014/01/26 22:39:18 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "filler.h"

void			check_piece(t_env *e)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	i = 0;
	e->piece_pst = (t_dot *)malloc(sizeof(t_dot)
			* (e->piece_size.x * e->piece_size.y));
	while (e->piece[x])
	{
		y = 0;
		while (e->piece[x][y])
		{
			if (e->piece[x][y] == '*')
			{
				e->piece_pst[i].x = x;
				e->piece_pst[i++].y = y;
			}
			y++;
		}
		x++;
	}
	e->nbr_piece = i;
}

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

int				use_piece(t_env *e)
{
	int			x;
	int			tmp;
	t_dot		m;
	t_dot		p;
	int			index;
	int			y2;
	int			u;
	t_dot		save;

	tmp = 0;
	x = 0;
	while (x < e->board_size)
	{
		y2 = 0;
		while(y2 < e->board_size_len)
		{
			u = 0;
			m.x = 0;
			index = 0;
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
							index++;
						else if (e->board[p.x][p.y] != '.')
							u++;
					}
					m.y++;
				}
				m.x++;
			}
			if (u == 0 && index == 1 && tmp++ < 2)
			{
				save.x = x;
				save.y = y2;
			}
			else if (u == 0 && index == 1)
				save = better_pos(e, save, x, y2);
			y2++;
		}
		x++;
	}
	return (print(e,save.x, save.y, tmp));
}
