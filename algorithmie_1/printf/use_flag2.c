/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flag2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 10:51:17 by glasset           #+#    #+#             */
/*   Updated: 2013/12/19 13:27:57 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "printf.h"

int					use_putnbr(va_list arg)
{
	int				i;

	i = va_arg(arg, int);
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
	}
	else
	i = ft_putnbr(i);
	return (i);
}

int					use_octal(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	i = ft_octal(i);
	return (i);
}

int					use_hex(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	i = ft_hexa(i);
	return (i);
}

int					use_hexx(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	i = ft_hexax(i);
	return (i);
}

int					use_countn(va_list arg)
{
	int				i;

	i = va_arg(arg, unsigned int);
	return (i);
}
