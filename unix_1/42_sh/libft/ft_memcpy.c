/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:47:25 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:51:55 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*ptr1;
	char		*ptr2;

	i = 0;
	ptr1 = ((char*)s1);
	ptr2 = ((char*)s2);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (((void*)ptr1));
}
