/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 12:29:38 by fcorbel           #+#    #+#             */
/*   Updated: 2013/12/15 23:20:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "hotrace.h"

t_lst			*ft_lstnew(char *keyword, char *value)
{
	t_lst		*tmp;

	tmp = malloc(sizeof(t_lst));
	tmp = NULL;
	if (tmp)
	{
		if (keyword && value)
		{
			tmp->keyword = (char *)malloc(sizeof(char) * ft_strlen(keyword));
			tmp->keyword = keyword;
			tmp->value = (char *)malloc(sizeof(char) * ft_strlen(value));
			tmp->value = value;
			tmp->next = NULL;
		}
		else if (keyword)
		{
			tmp->keyword = (char *)malloc(sizeof(char) * ft_strlen(keyword));
			tmp->keyword = keyword;
			tmp->value = NULL;
			tmp->next = NULL;
		}
		else
			return (0);
	}
	return (tmp);
}

void			ft_lstadd(t_lst **alst, t_lst *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
