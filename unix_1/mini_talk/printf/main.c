/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:43:36 by glasset           #+#    #+#             */
/*   Updated: 2013/12/23 11:37:25 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "printf.h"

int			main(void)
{
	int		i;
	int		u;
	char	c;
	int		n;

	n = 0;
	c = 'd';
	i = 101;
/*	u = printf("%d|%i|%u|%x|%X|%o|%c|%s|%%|%p|\n", i, i, i, i, i, i, c, "tata", &c);
	printf("%d|\n", u);
	u = ft_printf("%d|%i|%u|%x|%X|%o|%c|%s|%%|%p|\n", i, i, i, i, i, i, c, "tata", &c);
	printf("%d|\n", u);*/
	u = printf("%s|%d|%p\n", NULL, i, &c);
	printf("%d|\n", u);
	u = ft_printf("%s|%d|%p\n", NULL, i, &c);
	printf("%d|\n", u);
	return (0);
}
