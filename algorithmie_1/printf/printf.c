/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:59:27 by glasset           #+#    #+#             */
/*   Updated: 2013/12/22 18:11:17 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "printf.h"

int				wformat(char c)
{
	write(1, &c, 1);
	return (1);
}

int				wflag(char c, va_list arg, int *i)
{
	int			u;
	f			*ft;

	ft = ft_function();
	u = 0;
	if (c == '%')
		u = (use_perc(c));
	else
		u = (ft[check_flag(c)](arg));
	(*i)++;
	return (u);
}

int				wspace(char *tmp, int *i, char *format, va_list arg)
{
	int			u;
	f			*ft;

	ft = ft_function();
	u = 0;
	write(1, " ", 1);
	(*i) = (*i) + (check_space(tmp)) + 1;
	u =  (ft[check_flag(format[(*i)])](arg)) + 1;
	return (u);
}

int				ft_printf(char *format, ...)
{
	char		*tmp;
	va_list		arg;
	int			i;
	int			u;

	u = 0;
	i = -1;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			tmp = ft_strsub(format, (i + 1), (ft_strlen(format) - i));
			if (check_flag(format[i + 1]) != -1)
				u = u + (wflag(format[i + 1], arg, &i));
			else if (check_space(tmp) != -1)
				u = u + (wspace(tmp, &i, format, arg));
			else
				i = i + (check_nbr(tmp, &u, arg));
		}
		else
			u = u + (wformat(format[i]));
	}
	va_end(arg);
	return (u);
}

