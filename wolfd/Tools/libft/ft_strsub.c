/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <fcorbel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:01:01 by fcorbel           #+#    #+#             */
/*   Updated: 2013/11/27 11:18:04 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp)
	{
		while (i < len)
		{
			tmp[i] = s[start + i];
			i++;
		}
		tmp[i] = 0;
		return (tmp);
	}
	return (NULL);
}
