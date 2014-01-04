/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 11:38:28 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 23:33:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_ls.h"

int				ft_check(char **av, int ac, t_struct **t)
{
	int			i;
	int			u;

	i = 1;
	if (ac == 1 || av[1][0] != '-')
		return (0);
	while (i < ac)
	{
		u = 0;
		if (av[i][u] == '-')
			u++;
		while(av[i][u] != '\0')
		{
			if (av[i][u] == 'a')
				(*t)->a = "a";
			else
			{
				ft_printbadopt(av[i][u]);
				return (-1);
			}
			u++;
		}
		i++;
		if (i < ac && av[i][0] != '-')
			return (1);
	}
	return (1);
}
