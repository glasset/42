/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:08:23 by fkalb             #+#    #+#             */
/*   Updated: 2013/11/24 10:34:16 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	i = ft_strlen(s);
	chr = ((char)c);
	while (i > 0)
	{
		if (s[i] == chr)
			return ((char*)&(s[i]));
		i--;
	}
	if (s[i] == chr)
		return ((char*)&(s[i]));
	return (NULL);
}
