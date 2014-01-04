/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 13:06:33 by glasset           #+#    #+#             */
/*   Updated: 2013/12/13 18:43:41 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

void	ft_printperror(char *str)
{
	ft_putstr(str);
	ft_putstr(": ");
	perror("");
}

void	ft_printusage(char *str)
{
	ft_putstr("usage : ");
	ft_putstr(str);
	ft_putstr(" file1\n");
}

void	ft_printempty(char *str)
{
	ft_putstr(str);
	ft_putstr(": empty file\n");
}
