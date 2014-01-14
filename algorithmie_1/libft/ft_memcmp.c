/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:24:40 by glasset           #+#    #+#             */
/*   Updated: 2013/11/30 15:17:17 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*tmp;
	const char	*tmp2;

	tmp = s1;
	tmp2 = s2;
	i = 0;
	while (i < n)
	{
		if (*tmp != *tmp2)
			return (*tmp - *tmp2);
		i++;
		tmp++;
		tmp2++;
	}
	return (0);
}
