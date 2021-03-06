/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:26:04 by glasset           #+#    #+#             */
/*   Updated: 2014/01/15 15:07:11 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *s1, const char *s2)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
		i++;
	s1[i++] = '=';
	while (s2[n] != '\0')
		s1[i++] = s2[n++];
	s1[i] = '\0';
	return (s1);
}
