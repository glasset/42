/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:41:58 by glasset           #+#    #+#             */
/*   Updated: 2014/03/13 16:06:05 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			information(t_env *e, int c_l, int fd)
{
	char	*line;
	int		l;
	i		*ft;

	l = 1;
	inf = 0;
	while (get_next_line(fd, &line))
	{
		
		l++;
	}
	return (l);
}
