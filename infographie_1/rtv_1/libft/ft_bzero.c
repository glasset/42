/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:16:49 by glasset           #+#    #+#             */
/*   Updated: 2013/12/10 16:57:34 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*new_s;

	new_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		new_s[i] = 0;
		i++;
	}
}

