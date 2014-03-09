/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:42:57 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/09 17:05:41 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int		ev_vertical(char p, char **board, int line, int col)
{
	int		i;

	i = 1;
	while (board[++line] && board[line][col] && board[line][col] == p)
		i++;
	if (i > 1)
		return (i);
	return (0);
}

static int		ev_horizontal(char p, char *line, int col_right)
{
	int		col_left;

	col_left = col_right;
	while (col_left >= 0 && line[--col_left] && line[col_left] == p)
		;
	while (line[++col_right] && line[col_right] == p)
		;
	if (col_right - col_left > 2)
		return (col_right - col_left - 1);
	return (0);
}

static int		sub_ev_diagonal(char p, t_env *e, int line, int col)
{
	int		dline;
	int		dcol;
	int		i;

	i = 1;
	dline = line;
	dcol = col;
	while (++dline < e->line && ++dcol <= e->col && e->board[dline][dcol] == p)
		i++;
	dline = line;
	dcol = col;
	while (--dline > 0 && --dcol >= 0 && e->board[dline][dcol] == p)
		i++;
	if (i > 1)
		return (i);
	return (0);
}

static int		ev_diagonal(char p, t_env *e, int line, int col)
{
	int		dline;
	int		dcol;
	int		i;
	int		ct;

	ct = sub_ev_diagonal(p, e, line, col);
	i = 1;
	dline = line;
	dcol = col;
	while (++dline < e->line && --dcol >= 0 && e->board[dline][dcol] == p)
		i++;
	dline = line;
	dcol = col;
	while (--dline >= 0 && ++dcol <= e->col && e->board[dline][dcol] == p)
		i++;
	if (i > 1 && ct < i)
		return (i);
	return (ct);
}

int			evaluate_p(t_env *e, int col, char p)
{
	int		tmp;
	int		ct;

	ct = ft_sum(ev_vertical(p, e->board, e->curr_line, col - 1));
	tmp = ft_sum(ev_horizontal(p, e->board[e->curr_line], col - 1));
	if (tmp > ct)
		ct = tmp;
	tmp = ft_sum(ev_diagonal(p, e, e->curr_line, col - 1));
	if (tmp > ct)
		ct = tmp;
	if (e->curr_line - 1 >= 0)
	{
		e->curr_line--;
		if (check_victory(PAWNS_HUM, e, col))
			ct = 1;
		e->board[e->curr_line][col - 1] = '.';
		e->curr_line++;
	}
	return (ct);
}
