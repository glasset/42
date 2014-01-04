/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <fcorbel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:30:06 by fcorbel           #+#    #+#             */
/*   Updated: 2013/12/15 20:43:50 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char			*ft_strdup(const char *src)
{
	int			i;
	char		*dup;

	i = 0;
	if (src)
	{
		while (src[i])
			i++;
		dup = (char*)malloc(sizeof (char) * (i + 1));
		i = 0;
		while (src[i])
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = 0;
		return (dup);
	}
	return (0);
}
