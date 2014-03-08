/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:54:37 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 12:08:37 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "puissance.h"

static void		limit(t_env *e)
{
	int			i;
	char		c;

	c = '0';
	i = 0;
	write(1, "|", 1);
	while (i < e->col)
	{
		write(1, &c, 1);
		i++;
		c++;
	}
	write(1, "|\n", 2);
}

void			print_board(t_env *e)
{
	int			i;

	i = 0;
	limit(e);
	while (e->board[i] != NULL)
	{
		write(1, "|", 1);
		write(1, e->board[i], ft_strlen(e->board[i]));
		write(1, "|\n", 2);
		i++;
	}
	limit(e);
}
