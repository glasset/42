/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:27:18 by glasset           #+#    #+#             */
/*   Updated: 2013/12/10 17:04:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	size_t	i;

	tmp = (char *) s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (tmp[i] == (unsigned char) c)
			return (tmp + i);
		i--;
	}
	if (tmp[i] == (unsigned char) c)
		return (tmp + i);
	return (NULL);
}
