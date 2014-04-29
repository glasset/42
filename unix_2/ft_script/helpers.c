/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 15:03:18 by glasset           #+#    #+#             */
/*   Updated: 2014/04/29 15:17:39 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int			ft_strl(char *str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void		ft_puts(char *str, int fd)
{
	write(fd, str, ft_strl(str));
}
