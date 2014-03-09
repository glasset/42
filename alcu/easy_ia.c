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

static int		*init_tab(t_env *e, int *tab)
{
	int		mid;
	int		i;

	mid = (e->col + 1) / 2;
	i = 0;
	if (tab)
	{
		tab[mid - 1] = 1;
		while (mid + i <= e->col)
		{
			if (check_value(e, mid + i) != -1)
				tab[mid + i - 1] += evaluate_p(e, mid + i, PAWNS_IA)
					+ evaluate_p(e, mid + i, PAWNS_HUM);
			if (i > 0 &&  mid - i > 0 && check_value(e, mid - i) != -1)
				tab[mid - i - 1] += evaluate_p(e, mid - i, PAWNS_IA)
					+ evaluate_p(e, mid - i, PAWNS_HUM);
			i++;
		}
	}
	return (tab);
}

static int		print_result(int result)
{
	ft_putstr("IA: ");
	ft_putnbr(result);
	ft_putchar('\n');
	return (result);
}

int				easy_ia(t_env *e)
{
    int			*tab = NULL;
	int			i;
	int			result;
	int			weight;

	tab = (int *)ft_memalloc(sizeof(int) * e->col);
	weight = 0;
	result = 1;
	if (tab)
	{
		tab = init_tab(e, tab);
		i = 0;
		while (i < e->col)
		{
			if (tab[i] > weight)
			{
				result = i + 1;
				weight = tab[i];
			}
			i++;
		}
	}
	check_value(e, result);
	free(tab);
	return (print_result(result));
}
