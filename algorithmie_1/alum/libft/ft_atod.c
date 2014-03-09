/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:24:28 by gmarais           #+#    #+#             */
/*   Updated: 2014/02/16 18:24:04 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ten_pow(int pow)
{
	int		ret;

	if (pow < 0)
		return (0);
	if (pow >= 9)
		return (1000000000);
	ret = 1;
	while (pow)
	{
		ret *= 10;
		pow--;
	}
	return (ret);
}

static int	count_digits(int nbr)
{
	int		ret;

	ret = 1;
	while (nbr / 10)
	{
		ret++;
		nbr /= 10;
	}
	return (ret);
}

double		ft_atod(const char *str)
{
	int		i;
	int		j;
	double	ret;
	double	tmp;
	int		sign;

	sign = (str[0] == '-') ? -1 : 1;
	ret = (double)ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] && str[i + 1] != '\0')
	{
		j = 0;
		while (str[i + 1 + j] == '0')
			j++;
		tmp = (double)ft_atoi((char *)&str[i + 1]);
		tmp /= ten_pow(count_digits((int)tmp) + j);
		if (tmp < 1)
			ret += tmp;
	}
	if (sign == -1 && ret >= 0.0)
		return (-ret);
	return (ret);
}
