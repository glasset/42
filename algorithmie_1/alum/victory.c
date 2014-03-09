/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:20:28 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/09 17:05:43 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int		check_vertical(char p, char **board, int line, int col)
{
	int		i;

	i = 1;
	while (board[++line] && board[line][col] && board[line][col] == p)
		i++;
	if (i >= 4)
		return (1);
	return (0);
}

static int		check_horizontal(char p, char *line, int col_right)
{
	int		col_left;

	col_left = col_right;
	while (col_left >= 0 && line[--col_left] && line[col_left] == p)
		;
	while (line[++col_right] && line[col_right] == p)
		;
	if (col_right - col_left >= 5)
		return (1);
	return (0);
}

static int		sub_check_diagonal(char p, t_env *e, int line, int col)
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
	if (i >= 4)
		return (1);
	return (0);
}

static int		check_diagonal(char p, t_env *e, int line, int col)
{
	int		dline;
	int		dcol;
	int		i;

	if (sub_check_diagonal(p, e, line, col))
		return (1);
	i = 1;
	dline = line;
	dcol = col;
	while (++dline < e->line && --dcol >= 0 && e->board[dline][dcol] == p)
		i++;
	dline = line;
	dcol = col;
	while (--dline >= 0 && ++dcol <= e->col && e->board[dline][dcol] == p)
		i++;
	if (i >= 4)
		return (1);
	return (0);
}

int				check_victory(char p, t_env *e, int curr_col)
{
	e->board[e->curr_line][curr_col - 1] = p;
	if (check_vertical(p, e->board, e->curr_line, curr_col - 1))
		return (1);
	if (check_horizontal(p, e->board[e->curr_line], curr_col - 1))
		return (1);
	if (check_diagonal(p, e, e->curr_line, curr_col - 1))
		return (1);
	return (0);
}
