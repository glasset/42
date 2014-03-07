/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:43:47 by glasset           #+#    #+#             */
/*   Updated: 2014/03/07 13:57:17 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "my.h"
#include "ray_tracer.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void			ft_write(int line, char *str, char *msg)
{
	write(1, "l", 1);
	ft_putnbr(line);
	write(1, ": ", 2);
	write(1, msg, ft_strlen(msg));
	write(1, ": ", 2);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int				no_name(char **tmp, int true_size)
{
	int			i;
	int			j;
	int			x;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			x = 0;
			if (tmp[i][j] == '.' || tmp[i][j] == '-' || tmp[i][j] == '\r'
				|| tmp[i][j] == ']')
				x++;
			if (tmp[i][j] >= '0' && tmp[i][j] <= '9')
				x++;
			if (tmp[i + 1] == NULL)
			{
				if (tmp[i][j] == 'x' ||  (tmp[i][j] >= 'a' && tmp[i][j] <= 'f'))
					x++;
			}
			if (x == 0)
				return (-4);
			j++;
		}
		i++;
	}
	if (j != 10)
		return (-4);
	if (i != true_size)
		return (-4);
	return (0);
}

void			error_p(int error, int line, char *str)
{
	if (error == -1)
		ft_write(line, str, "[\033[31mFAIL\033[00m] (too many meshes)");
	if (error == -2)
		ft_write(line, str, "[\033[31mFAIL\033[00m] (too many lights)");
	if (error == -3)
	{
		write(1, "[\033[31mERROR\033[00m]need |[nb]light && |[nb]object.\n", 49);
		exit(0);
	}
	if (error == -4)
		ft_write(line, str, "[\033[31mFAIL\033[00m] (bad syntax)");
	if (error == 0)
		ft_write(line, str, "[\033[32mOK\033[00m]");
	if (error == -6)
		ft_write(line, str, "[\033[31mFAIL\033[00m] (Coeff between 0 and 1)");
		
}

t_color			get_color(char *str)
{
	t_color		fin;
	int			i;
	int			ccolor;

	ccolor = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ccolor =  ccolor * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			ccolor = ccolor * 16 + (str[i] - 'a' + 10);
		i++;
	}
	fin.r = (ccolor % 256) / 255;
	fin.g = (ccolor / 256 % 256) / 255;
	fin.b = (ccolor / 256 / 256) / 255;
	return (fin);
}

