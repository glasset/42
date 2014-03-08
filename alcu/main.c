/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:09:40 by glasset           #+#    #+#             */
/*   Updated: 2014/03/08 16:58:45 by glasset          ###   ########.fr       */
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

int				main(int ac, char **av, char **env)
{
	t_env		e;
	int			player;

	if (ac != 3)
		return (put_error("need: nb_l, nb_col", -1));
	if (init_env(&e, av, env))
		return (-1);
	player = ft_rand();
	if (init_board(&e) == -1)
		return (-1);
	print_board(&e);
	while (42)
	{
		if (player == 1)
		{
			if (init_value(&e) == 0)
			{
//				resolve(&e, player);
				player = 0;
				print_board(&e);
			}
		}
		else
		{
//			resolve(&e, player);
			player = 1;
			print_board(&e);
		}
	}
	return (0);
}
