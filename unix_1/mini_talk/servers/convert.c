/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 17:51:10 by glasset           #+#    #+#             */
/*   Updated: 2014/02/02 20:19:22 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "server.h"

void			convert(void)
{
	int			c;
	int			puiss;
	char		d;

	puiss = 1;
	c = 0;
	while((env->oct) > 0)
	{
		c = (env->onechar[env->oct - 1] * puiss) + c;
		puiss = puiss * 2;
		env->oct--;
	}
	env->oct = 0;
	d = c;
	write (1, &d, 1);
}

