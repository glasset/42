/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:05:40 by fkalb             #+#    #+#             */
/*   Updated: 2013/11/24 10:33:56 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	while (i < n)
	{
		s1[i] = '\0';
		if (i <= s2_len)
			s1[i] = s2[i];
		i++;
	}
	return (s1);
}
