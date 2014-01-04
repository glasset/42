/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:48:53 by glasset           #+#    #+#             */
/*   Updated: 2013/12/21 10:59:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "printf.h"

int				ft_putstr(char *s)
{
	int			i;

	i = 0;
	if (s)
	{
		write(1, s, ft_strlen(s));
		i = ft_strlen(s);
	}
	else
	{
		write(1, "(null)", 6);
		i = 6;
	}
	return (i);
}
