/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 10:43:27 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 23:31:13 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "ft_ls.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int			i;
	t_struct	*t;

	t = malloc(sizeof(t_struct));
	i = (ft_check(argv, argc, &t));
	if (i == -1)
		ft_putendl("usage: ls [-a] [file ...]");
	else if (i == 0)
		ft_noption(argv, argc);
	else if (i == 1)
		ft_a(argv, argc);
	return (0);
}
