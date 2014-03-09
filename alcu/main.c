/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:09:40 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 21:49:38 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "puissance.h"

int			put_error(char *str, int ernum)
{
	write(2, str, ft_strlen(str));
	return (ernum);
}

int			only_nb(char *str, int min)
{
	size_t		i;

	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	if (i == ft_strlen(str) && min <= ft_atoi(str))
		return (0);
	return (-1);
}

int			ft_rand(void)
{
	srand(time(NULL));
	return (rand()%2);
}

void			print_winner(int winner, t_env *e)
{
	print_board(e);
	if (winner == 1)
	{
		ft_putstr(e->name);
		ft_putendl(": wins.");
	}
	else if (winner == 2)
	{
		ft_putendl("IA: wins.\nYou are so bad!");
	}
	else
		ft_putendl("(>X_X)> Draw! <(X_X<)");
}

int				main(int ac, char **av, char **env)
{
	t_env		e;
	int			player;
	int			winner;

	if (ac != 3)
		return (put_error("Usage: puissance4 [num_line] [num_column]\n", -1));
	if (init_env(&e, av, env) || init_board(&e) == -1)
		return (-1);
	player = ft_rand();
	print_board(&e);
	while (!(winner = play_round(&e, player)))
	{
		print_board(&e);
		player = (player) ? 0 : 1;
	}
	print_winner(winner, &e);
	return (0);
}
