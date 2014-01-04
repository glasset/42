/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 12:30:45 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 23:27:15 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_ls.h"
#include "libft.h"

int		ft_noption(char **alst, int ac)
{
	DIR			*diro;
	d_struct	*dirr;
	int			i;
		
	i = 0;
	while (i < ac)
	{
		diro = NULL;
		if (ac > 1)
		{
			if (i == 0)
				i++;
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
			return (0);
		}
		if (ac > 2)
		{
			ft_putstr(alst[i]);
			ft_putstr(":\n");
		}
		while ((dirr = readdir(diro)))
			if (dirr->d_name[0] != '.')
				ft_putendl(dirr->d_name);
		if (closedir(diro) == -1)
		{
			perror("Error");
			return (0);
		}
		if ((i + 1) != ac)
			ft_putstr(" \n");
		i++;
	}
	return (0);
}

