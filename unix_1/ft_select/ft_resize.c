/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 10:41:14 by glasset           #+#    #+#             */
/*   Updated: 2014/01/08 17:28:27 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include "ft_select.h"

void			ft_tab(char *str, int max_size)
{
	int			size_str;

	size_str = ft_strlen(str);
	while(size_str < max_size + 1)
	{
		write(isatty(1), " ", 1);
		size_str++;
	}
}

int			ft_backn(int len)
{
	int		li;

	li = tgetnum("li");
	if (li < len)
		return (0);
	return (-1);
}

int			ft_backli(int max_size, int curw)
{
	int		li;
	int		result;

	li = tgetnum("li");
	result = li / (max_size + 1);
	if(result > curw)
		return (1);
	return (-1);
}

