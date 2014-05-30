/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:04:57 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:47:43 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(unsigned char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int			ft_tolower(int c)
{
	if (ft_isupper(((unsigned char)c)))
		return ('a' + (c - 'A'));
	return (c);
}
