/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 13:11:27 by glasset           #+#    #+#             */
/*   Updated: 2014/01/24 22:15:34 by glasset          ###   ########.fr       */
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
	e->board_pst = (t_dot *)malloc(sizeof(t_dot) * (e->board_size * 30));
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

void			print(t_env *e, int pos)
{
	if (e->piece_pst[0].x != 0)
		e->board_pst[pos].x = e->board_pst[pos].x - e->piece_pst[0].x;
	if (e->piece_pst[0].y != 0)
		e->board_pst[pos].y = e->board_pst[pos].y - e->piece_pst[0].y;
	ft_putnbr(e->board_pst[pos].x);
	write(1, " ", 1);
	ft_putnbr(e->board_pst[pos].y);
	write(1, "\n", 1);
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

void			use_piece(t_env *e)
{
	int			y;
	int			x;
	int			save;
	static int	i = 0;

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
			if (e->board[e->board_pst[x].x + e->piece_pst[y].x]
					[e->board_pst[x].y + e->piece_pst[y].y] != '.' ||
					(e->board_pst[x].y + e->piece_size.y) > e->board_size_len ||
					(e->board_pst[x].x + e->piece_size.x) > e->board_size)
				break;
			y++;
		}
		if (y == e->nbr_piece)
		{
			if (i > 1)
			{
				save = x;
				i = 0;
			}
			else
			{
				save = x;
				i = 2;
				break;
			}
		}
		x++;
	}
	if (save != -1)
		print(e, save);
	else
		exit (0);
	free(e->board_pst);
	free(e->piece_pst);
}
