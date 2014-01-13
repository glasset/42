/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 10:41:14 by glasset           #+#    #+#             */
/*   Updated: 2014/01/11 17:05:20 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "ft_select.h"

void					ft_tab(char *str, int max_size)
{
	int					size_str;

	size_str = ft_strlen(str);
	while (size_str <= max_size)
	{
		write(isatty(1), " ", 1);
		size_str++;
	}
}

int						ft_backn(int len)
{
	struct winsize		li;

	ioctl(0, TIOCGWINSZ, &li);
	if (li.ws_row < len)
		return (0);
	return (-1);
}

int						ft_backli(int max_size, int curw)
{
	int					result;
	struct winsize		li;

	ioctl(0, TIOCGWINSZ, &li);
	result = curw * (max_size + 1);
	if (result < li.ws_col && ((result + max_size + 1) <= li.ws_col))
		return (0);
	return (1);
}

int						ft_sizeof(int max_size, int len)
{
	struct winsize		li;

	ioctl(0, TIOCGWINSZ, &li);
	if ((max_size * len) <= (li.ws_col * li.ws_row))
		return (0);
	else
		write (isatty(1), "please resize your term", 24);
	return (1);
}

int						ft_finalp(int esc, int len, int cuw)
{
	if (esc == len)
		return (-1);
	if (cuw != 0)
		write(isatty(1), "\n", 1);
	return (0);
}
