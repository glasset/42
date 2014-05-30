/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:03:14 by fkalb             #+#    #+#             */
/*   Updated: 2013/11/24 08:34:24 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = ((unsigned char*)s1);
	ptr2 = ((unsigned char*)s2);
	if (n == 0)
		return (0);
	while (i < n && ptr1[i] == ptr2[i] && ptr1[i] != 0)
		i++;
	if (i == n)
		return (0);
	return (ptr1[i] - ptr2[i]);
}
