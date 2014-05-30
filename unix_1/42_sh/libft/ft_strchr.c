/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:56:51 by fkalb             #+#    #+#             */
/*   Updated: 2013/11/24 10:22:27 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	chr;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	chr = ((char)c);
	while (i <= s_len)
	{
		if (s[i] == chr)
			return ((char*)&(s[i]));
		i++;
	}
	return (NULL);
}
