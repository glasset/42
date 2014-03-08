/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:09:59 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 17:38:46 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance.h>

int		check_value(t_env *e, int choice)
{
	int		i;

	if (choice > 0 &&  choice < e->col)
	{
		i = e->line;
		while (i && e->board[i][choice] != '.')
			i--;
		if (!i)
			return (-1);
		return (choice);
	}
	return (-1);
}

int		human(t_env *e)
{
	char	*line;
	int		choice;

	choice = -1;
	while (choice == -1)
	{
		line = get_next_line(0, &line);
		choice = ft_atoi(line);
		choice = check_value(e, choice);
	}
	return (choice);
}

int		check_victory(t_env *e, int	last_play)
{

}

int		round(t_env *e, int	player)
{
	if (player)
	{
		return (check_victory(e, human(e)));
	}
	else
	
}
