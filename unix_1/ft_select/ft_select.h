/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 12:28:42 by glasset           #+#    #+#             */
/*   Updated: 2014/01/06 18:51:03 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"

typedef struct			s_lst
{
	char				*str;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

typedef struct			p_lst
{
	size_t				len;
	struct s_lst		*start;
	struct s_lst		*end;
}						l_lst;

l_lst					*lst_new(void);
l_lst					*lst_add_end(l_lst *l_x, char *str);
l_lst					*lst_add_start(l_lst *l_x, char *str);

l_lst					*moove(l_lst *arg, l_lst *select);
int						print_tlst(t_lst *print, int i);
int						tputs_putchar(int c);

#endif  /* !FT_SELECT_H */

