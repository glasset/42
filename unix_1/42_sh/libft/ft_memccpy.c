/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:03:01 by fkalb             #+#    #+#             */
/*   Updated: 2013/11/24 10:17:19 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = ((unsigned char*)s1);
	ptr2 = ((unsigned char*)s2);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr1[i++] == ((unsigned char)c))
			return (&(ptr1[i]));
	}
	return (NULL);
}
