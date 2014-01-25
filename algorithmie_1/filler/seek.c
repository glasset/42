/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 13:11:27 by glasset           #+#    #+#             */
/*   Updated: 2014/01/25 18:00:13 by glasset          ###   ########.fr       */
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

t_dot			ajust(t_env *e, int x, int y)
{
	t_dot		m;

	m.x = e->board_pst[x].x + e->piece_pst[y].x;
	m.y = e->board_pst[x].y + e->piece_pst[y].y;
	if (e->board_pst[x].y + e->piece_pst[y].y > (e->board_size_len - 1))
		m.y = m.y - e->board_size_len;
	if (e->board_pst[x].x + e->piece_pst[y].x > (e->board_size - 1))
		m.x = m.x - e->board_size;
	return (m);
}

int				use_piece(t_env *e)
{
	int			y;
	int			x;
	int			save;
	t_dot		m;
	t_dot		j;
	int			tmp;

	tmp = 0;
	check_piece(e);
	check_board(e);
	resize(e);
	save = -1;
	x = 0;
	while (x < e->nbr_board)
	{
		y = 1;
		while (y < e->nbr_piece)
		{
			m = ajust(e, x, y);

			if (e->board[m.x][m.y] != '.')
				break;
			y++;
		}
		if (y == e->nbr_piece)
		{
			if(tmp == 0)
			{
				j.x = e->board_pst[x].x;
				j.y = e->board_pst[x].y;
				tmp = 1;
				save = x;
			}
			else if (ft_abs(e->board_pst[x], e->board_pst[save],
						(e->board_size_len / 2), (e->board_size / 2)) != 0)
				save = x;
		}
		x++;
	}

	if (save != -1)
	{
		print(e, save);
		return (0);
	}
	write(1, "0 0\n", 4);
	return (1);
//	free(e->board_pst);
//	free(e->piece_pst);
}
