/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <fcorbel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:18:16 by fcorbel           #+#    #+#             */
/*   Updated: 2013/11/22 18:45:10 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void		ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*uc;

	i = 0;
	uc = (unsigned char *) s;
	while (i < n)
	{
		uc[i] = 0;
		i++;
	}
}
