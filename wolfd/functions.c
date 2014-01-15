/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 19:08:46 by fcorbel           #+#    #+#             */
/*   Updated: 2014/01/07 15:15:34 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

#include <stdio.h>

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int				ft_char_int(char c)
{
	int			tmp;

	tmp = c -'0';
	return (tmp);
}

int				ft_atoi(const char *str)
{
	int			nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = nb * 10;
		nb = nb + (*str - '0');
		str++;
	}
	return (nb * sign);
}
