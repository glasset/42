/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:17:07 by glasset           #+#    #+#             */
/*   Updated: 2013/11/26 10:53:27 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	i = 0;
	while (i < n)
	{
		*tmp1 = *tmp2;
		tmp1++;
		tmp2++;
		i++;
	}
	return (s1);
}
