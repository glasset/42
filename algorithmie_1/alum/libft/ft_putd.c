/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:27:47 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/01 14:19:54 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putd(char *name, double nbr)
{
	int	i;

	ft_putstr(name);
	ft_putstr(" = ");
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -1 * nbr;
	}
	ft_putnbr(nbr);
	if (nbr - (int)nbr)
	{
		ft_putchar('.');
		i = 1000000;
		nbr = (nbr - (int)nbr) * i;
		while ((nbr / (i / 10)) < 1 && i > 1)
		{
			ft_putchar('0');
			i /= 10;
		}
		ft_putnbr(nbr);
	}
	ft_putchar('\n');
}
