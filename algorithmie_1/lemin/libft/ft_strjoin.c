/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:42:48 by glasset           #+#    #+#             */
/*   Updated: 2013/11/27 12:02:38 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;
	int		z;

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

