/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:17:56 by fcorbel           #+#    #+#             */
/*   Updated: 2014/01/06 17:36:26 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int				get_map(char ***map, char *path)
{
	int			fd;
	int			ret;
	int			i;
	char		*line;

	line = NULL;
	if ((fd = open(path, O_RDONLY) == -1))
		error("Error : open()");
	line = (char *)malloc(sizeof(char));
	if ((ret = read(fd, line, 6) == -1))
		error("Error : read()");
	e->map = (char **)malloc(sizeof(char) * ft_atoi(line));
	i = 0;
	while (get_next_line(fd, &line))
	{
		(*map)[i] = line;
		i++;
	}
}
