/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 10:19:55 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 23:30:57 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_ls.h"

void	ft_printbadopt(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
}

void	ft_printperror(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	perror("");
}
