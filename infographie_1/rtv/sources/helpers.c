/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:48:16 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/22 16:49:59 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}