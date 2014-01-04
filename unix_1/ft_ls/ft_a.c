/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 18:15:24 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 23:32:22 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_ls.h"

int		ft_a(char **alst, int ac)
{
	DIR			*diro;
	d_struct	*dirr;
	int			i;

	i = 0;
	while (i < ac)
	{
		diro = NULL;
		if (ac > 2)
		{
			if (i == 0)
				i = i + 2;
			diro = opendir(alst[i]);
		}
		else
		{
			diro = opendir(".");
			i++;
		}
		if (diro == NULL)
		{
			ft_printperror(alst[i]);
		}
		else
		{
			if (ac > 3)
			{
				ft_putstr(alst[i]);
				ft_putendl(":");
			}
			while ((dirr = readdir(diro)))
				ft_putendl(dirr->d_name);
			if (closedir(diro) == -1)
			{
				perror("Error");
				return (0);
			}
			if ((i + 1) != ac)
				ft_putstr(" \n");
		}
		i++;
	}
	return (0);
}

