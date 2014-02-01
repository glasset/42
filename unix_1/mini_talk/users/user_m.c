/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:51:23 by glasset           #+#    #+#             */
/*   Updated: 2014/02/01 16:45:39 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "user.h"
#include <stdio.h>
#include <stdlib.h>

int			main(int argc, char **argv)
{
	if (argc != 3)
		printf("Usage: %s pid \"message\".\n", argv[0]);
	else
		data(atoi(argv[1]), argv[2]);
	return (0);
}
