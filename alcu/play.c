/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:09:59 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 22:13:02 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int				check_value(t_env *e, int choice)
{
	int		i;

	if (choice > 0 && choice <= e->col)
	{
		i = e->line - 1;
		while (i > -1 && e->board[i][choice - 1] != '.')
			i--;
		if (i == -1)
			return (-1);
		e->curr_line = i;
		return (choice);
	}
	return (-1);
}

static int		human(t_env *e)
{
	char	*line;
	int		choice;

	choice = -1;
	while (choice == -1)
	{
		ft_putstr(e->name);
		ft_putstr(": ");
		if (get_next_line(0, &line) > 0)
		{
			choice = ft_atoi(line);
			choice = check_value(e, choice);
			if (choice == -1)
				ft_putendl_fd("Usage: incorrect column number.", 2);
		}
	}
	return (choice);
}

int				play_round(t_env *e, int player)
{
	int		i;

	if (player)
	{
		if (check_victory('O', e, human(e)))
			return (1);
	}
	else if (check_victory('X', e, easy_ia(e)))
			return (2);
	i = 0;
	while (i++ <= e->col)
	{
		if (check_value(e, i) != -1)
			return (0);
	}
	return (3);
}
