/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:49:35 by glasset           #+#    #+#             */
/*   Updated: 2013/11/30 11:34:43 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = malloc(content_size);
	if (tmp)
	{
		if (content)
		{
			tmp->content = (void *)content;
			tmp->content_size = content_size;
			tmp->next = NULL;
		}
		else
		{
			tmp->content = NULL;
			tmp->content_size = 0;
			tmp->next = NULL;
		}
	}
	return (tmp);
}

