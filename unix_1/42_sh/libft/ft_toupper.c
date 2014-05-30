/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:05:11 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:47:39 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(unsigned char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int			ft_toupper(int c)
{
	if (ft_islower(((unsigned char)c)))
		return ('A' + (c - 'a'));
	return (c);
}
