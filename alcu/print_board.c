/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:54:37 by glasset           #+#    #+#             */
/*   Updated: 2014/03/09 15:55:01 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "puissance.h"

static void		limit(t_env *e)
{
	int			i;
	char		c;

	c = '1';
	i = 0;
	while (i < e->col)
	{
		ft_putstr("\033[1;34m|\033[0m");
		write(1, &c, 1);
		i++;
		c++;
		if (c > '9')
			c = '0';
	}
	ft_putstr("\033[1;34m|\n\033[0m");
}

void			put_charcolor(char c, char *color)
{
	ft_putstr(color);
	ft_putchar(c);
	ft_putstr("\033[0m");
}

void			print_board(t_env *e)
{
	int			i;
	int			j;

	i = 0;
	limit(e);
	while (e->board[i] != NULL)
	{
		j = -1;
		while (++j < e->col)
		{
			ft_putstr("\033[1;34m|\033[0m");
			if (e->board[i][j] == '.')
				ft_putstr("\033[1;30m.\033[0m");
			else if (e->board[i][j] == PAWNS_IA)
				put_charcolor(PAWNS_IA, "\033[1;31m");
			else if (e->board[i][j] == PAWNS_HUM)
				put_charcolor(PAWNS_HUM, "\033[1;33m");
		}
		ft_putstr("\033[1;34m|\n\033[0m");
		i++;
	}
	limit(e);
}
