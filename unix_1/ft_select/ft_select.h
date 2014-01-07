/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 12:28:42 by glasset           #+#    #+#             */
/*   Updated: 2014/01/07 21:08:06 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"


typedef struct			s_lst
{
	char				*str;
	int					bol;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

typedef struct			p_lst
{
	size_t				len;
	struct s_lst		*start;
	struct s_lst		*end;
}						l_lst;

typedef					void(*f)(t_lst *,int len);

l_lst					*lst_new(void);
l_lst					*lst_add_end(l_lst *l_x, char *str, int bol);
l_lst					*lst_add_start(l_lst *l_x, char *str, int bol);
void					del_tlst(t_lst *cur);

int						print(t_lst *print, int len);
void					ft_options(char *str, l_lst *arg);
f						*ft_function(void);

int						check_key(unsigned int str);

void					space(t_lst *arg, int len);
void					up(t_lst *arg, int len);
void					down(t_lst *arg, int len);
void					backdel(t_lst *arg, int len);

l_lst					*ft_select(l_lst *arg);
int						tputs_putchar(int c);

#endif  /* !FT_SELECT_H */

