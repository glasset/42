/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 06:23:57 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/12 14:03:01 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_key(char *s1, char *s2, char *key)
{
	char	*tmp;

	tmp = ft_strnew(1);
	tmp = ft_strjoin_free(tmp, s1);
	tmp = ft_strjoin_free(tmp, key);
	tmp = ft_strjoin_free(tmp, s2);
	return (tmp);
}

char		*ft_strfjoin_key(char *s1, char *s2, char *key)
{
	char	*tmp;

	tmp = ft_strjoin_key(s1, s2, key);
	ft_strdel(&s1);
	return (tmp);
}
