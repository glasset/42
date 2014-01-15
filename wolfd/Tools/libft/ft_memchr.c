/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <fcorbel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:16:28 by fcorbel           #+#    #+#             */
/*   Updated: 2013/11/30 15:31:19 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	new_c;
	size_t			i;
	char			*new_s;

	new_c = c;
	i = 0;
	new_s = (char *) s;
	while (i < n)
	{
		if (new_s[i] == new_c)
			return (new_s + i);
		i++;
	}
	return (NULL);
}
