/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartwith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 00:59:20 by fkalb             #+#    #+#             */
/*   Updated: 2014/02/01 20:28:41 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int			ft_strstartwith(const char *s1, const char *s2)
{
	size_t	s2len;

	if ((s2len = ft_strlen(s2)) > ft_strlen(s1))
		return (0);
	return (ft_strnequ(s1, s2, s2len));
}
