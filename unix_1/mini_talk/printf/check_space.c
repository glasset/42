/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 11:20:30 by glasset           #+#    #+#             */
/*   Updated: 2014/02/02 17:33:26 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "printf.h"

int				check_space(char *str)
{
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '0')
		i++;
	if (check_flag(str[i]) != -1)
		return (i);
	return (-1);
}

int				intlen(int c)
{
	int			len;

	len = 1;
	while ((c / 10) > 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

int			wzero(char *str, int cou, int *u)
{
	if (str[0] == '0')
		write(1, "0", 1);
	else
		write(1, " ", 1);
	cou--;
	(*u)++;
	return (cou);
}

int				check_nbr(char *str, int *u, va_list arg)
{
	t_int		x;
	int			i;

	x.t = va_arg(arg, int);
	x.nbr = intlen(x.t);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[0] == '0' || str[0] == ' ')
	{
		x.cou = ft_atoi(ft_strsub(str, 1, (i - 1)));
		while ((x.nbr - x.cou) < 0)
			x.cou = wzero(str, x.cou, &(*u));
		(*u) = (*u) + (ft_putnbr(x.t));
		i++;
	}
	else if (str[0] >= '0' && str[0] <= '9')
	{
		x.cou = ft_atoi(ft_strsub(str, 0, (i)));
		while ((x.nbr - x.cou) < 0)
			x.cou = wzero(str, x.cou, &(*u));
		(*u) = (*u) + (ft_putnbr(x.t));
		i++;
	}
	return (i);
}

