/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:48:11 by glasset           #+#    #+#             */
/*   Updated: 2013/12/22 17:20:35 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "printf.h"

int					use_putstr(va_list arg)
{
	char			*str;
	int				i;

	str = va_arg(arg, char *);
	i = ft_putstr(str);
	return (i);
}

int					use_un_int(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	i = ft_putunint(i);
	return (i);
}

int					use_putchar(va_list arg)
{
	char			c;

	c = va_arg(arg, int);
	write(1, &c, 1);
	return (1);
}

int					use_pointer(va_list arg)
{
	unsigned long	adr;

	adr = va_arg(arg, unsigned long);
	write(1, "0x", 2);
	adr = 2 + (ft_hexax(adr));
	return (adr);
}

int					use_Z(va_list arg)
{
	char			c;

	c = va_arg(arg, int);
	write(1, "Z", 1);
	return (1);
}
