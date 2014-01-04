/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 16:01:06 by glasset           #+#    #+#             */
/*   Updated: 2013/12/29 18:39:28 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"
void		error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int			main(int argc, char **argv)
{
	l_lst	*l_a;
	l_lst	*l_b;
	int		i;

	i = 1;
	l_a = lst_new();
	l_b = lst_new();
	if (argc < 2)
		error();
	if (argc == 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		l_a = lst_add_end(l_a, ft_atoi(argv[i]));
		i++;
	}
	l_a = l_sort(l_a, l_b);
	write(1, "\n", 1);
	return (0);
}
