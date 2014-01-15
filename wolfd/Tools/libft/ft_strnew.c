/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <fcorbel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:28:12 by fcorbel           #+#    #+#             */
/*   Updated: 2013/11/27 18:03:41 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp)
	{
		ft_bzero(tmp, (size + 1));
		return (tmp);
	}
	return (NULL);
}
