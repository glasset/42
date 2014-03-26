/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 10:00:44 by glasset           #+#    #+#             */
/*   Updated: 2014/03/26 10:06:12 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			comment_b(t_env *e, char *str)
{
	(void)e;
	(void)str;
	return (1);
}

int			checkline_inf(char *str)
{
	char	**tmp;

	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	if (!ft_strcmp(tmp[0], "numbers of light"))
		return (1);
	if (!ft_strcmp(tmp[0], "numbers of object"))
		return (2);
	if (!ft_strcmp(tmp[0], "point of view"))
		return (3);
	if (!ft_strcmp(tmp[0], "look at"))
		return (4);
	if (!ft_strcmp(tmp[0], "color ambient"))
		return (5);
	return (-1);
}
