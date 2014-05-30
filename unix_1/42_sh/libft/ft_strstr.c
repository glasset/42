/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:25 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 10:01:40 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2 || !s2[0])
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s2[j])
			{
				if (s1[i + j] == s2[j])
					j++;
				else
					break ;
			}
			if (!s2[j])
				return ((char*)&(s1[i]));
		}
		i++;
	}
	return (NULL);
}
