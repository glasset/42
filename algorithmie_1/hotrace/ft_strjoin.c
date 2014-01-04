/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:21:45 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 20:44:02 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "hotrace.h"

char			*ft_strjoin(char *s1, char *s2)
{
	char		*tmp;
	int			i;
	int			z;

	z = 0;
	i = 0;
	tmp = (char*)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
	{
		tmp[z] = s1[i];
		z++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		tmp[z] = s2[i];
		i++;
		z++;
	}
	tmp[z] = 0;
	return (tmp);
}

