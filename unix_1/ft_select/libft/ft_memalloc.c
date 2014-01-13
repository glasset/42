/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:44:49 by glasset           #+#    #+#             */
/*   Updated: 2013/12/02 11:35:35 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp)
	{
		ft_bzero(tmp, size);
		return ((void *)tmp);
	}
	return (NULL);
}
