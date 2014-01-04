/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:32:56 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 22:54:12 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "hotrace.h"

int				get_info(t_lst ***data, int q)
{
	char		*line;
	t_lst		info;

	while ((get_next_line(&line, 0)) == 1)
	{
		if ((q == 0 || q == 2) && line)
		{
			info.keyword = ft_strdup(line);
			if (q == 0)
				q = 1;
			else if (q == 2)
				make_data(info, '\n', &(*data));
		}
		else if (q == 1 && line)
		{
			info.value = ft_strdup(line);
			q = 0;
			make_data(info, info.keyword[0], &(*data));
		}
		if (line[0] == '\0')
			q = 2;
	}
	ft_memdel((void **)line);
	return (0);
}

