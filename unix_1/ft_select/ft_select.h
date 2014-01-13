/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 12:28:42 by glasset           #+#    #+#             */
/*   Updated: 2014/01/11 18:56:09 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define ON 1
# define OFF 0
# include <termcap.h>
# include <termios.h>
# include "libft.h"
typedef struct	termios	t_term;

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
	int					max_size;
	struct s_lst		*start;
	struct s_lst		*end;
}						l_lst;

l_lst					*ard;
t_term					term;
typedef					void(*f)(t_lst *, int);

void					exitclear(t_term term);
void					sigw(int sig);
void					sigstepre(int sig);
l_lst					*makelst(l_lst *arg, int argc,  char **argv, int x);
l_lst					*lst_new(void);
l_lst					*lst_add_end(l_lst *l_x, char *str, int bol);
l_lst					*lst_add_start(l_lst *l_x, char *str, int bol);
void					del_tlst(t_lst *cur);
struct termios			init(struct termios term, int i);
int						print(t_lst *print, int len, int max_size);
int						ft_finalp(int esc, int len, int cuw);
int						ft_options(char *str, l_lst *arg);
f						*ft_function(void);

int						resize(l_lst *arg, int row);

void					ft_tab(char *str, int max_size);
int						ft_backn(int len);
int						ft_backli(int max_size, int curw);
int						ft_sizeof(int max_size, int len);
void					tputs_status(int status);
int						check_key(unsigned int str);
void					space(t_lst *arg, int len);
void					up(t_lst *arg, int len);
void					down(t_lst *arg, int len);
void					backdel(t_lst *arg, int len);
l_lst					*ft_select(l_lst *arg);
int						tputs_putchar(int c);

#endif  /* !FT_SELECT_H */

