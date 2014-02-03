/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:58:04 by glasset           #+#    #+#             */
/*   Updated: 2014/02/03 13:34:22 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int							ft_putnbr(int n)
{
	char					c;
	int						u;

	u = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		u++;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		u++;
	}
	else
	{
		u = u + ft_putnbr(n / 10);
		u = u + ft_putnbr(n % 10);
	}
	return (u);
}

int							ft_putunint(unsigned int n)
{
	char					c;
	int						u;

	u = 0;
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		u++;
	}
	else
	{
		u = u + ft_putnbr(n / 10);
		u = u + ft_putnbr(n % 10);
	}
	return (u);
}

int							ft_octal(unsigned int n)
{
	int						a;
	int						u;
	char					c;

	u = 0;
	a = n % 8;
	n = n / 8;
	if (n > 0)
		u = u + ft_octal(n);
	c = a + '0';
	write(1, &c, 1);
	u++;
	return (u);
}

int							ft_hexa(unsigned int n)
{
	unsigned int			a;
	unsigned int			u;
	char					*str;

	str = "0123456789ABCDEF";
	u = 0;
	a = n % 16;
	n = n / 16;
	if (n > 0)
		u = u + ft_hexa(n);
	write(1, &str[a], 1);
	u++;
	return (u);
}

int						ft_hexax(unsigned long n)
{
	unsigned long		a;
	int					u;
	char				*str;

	str = "0123456789abcdef";
	u = 0;
	a = n % 16;
	if (n / 16)
		u = u + ft_hexax(n / 16);
	write(1, &str[a], 1);
	u++;
	return (u);
}
