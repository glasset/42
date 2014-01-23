/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:05:46 by glasset           #+#    #+#             */
/*   Updated: 2014/01/23 18:10:12 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "filler.h"

void		freedom(t_env *e)
{
	int		i;

	i = 0;
	if (e->piece)
	{
		while (e->piece[i])
			free(e->piece[i++]);
		free(e->piece);
	}
}

int			main(void)
{
	t_env	e;

	ft_read(&e);
	return (0);
}

