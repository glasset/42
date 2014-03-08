/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_ia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:42:57 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/08 22:23:45 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int				*init_tab(t_env e, int *tab)
{
	int		mid;
	int		i;

	mid = (e->col + 1) / 2;
	i = 0;
	if (tab)
	{
		while (check(valuee, mid + i))
	}
	return (tab);
}

int				easy_ia(t_env *e)
{
	static int	*tab = NULL;
	int			i;

	if (!tab)
		tab = (int *)memmalloc(sizeof(int) * e->col);
	tab = init_tab(e, tab);
	i = 0;
	while ()
}
