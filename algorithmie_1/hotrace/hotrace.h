/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 11:10:49 by glasset           #+#    #+#             */
/*   Updated: 2013/12/15 22:50:14 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <string.h>

typedef struct			s_lst
{
	char				*keyword;
	char				*value;
	struct s_lst		*next;
}						t_lst;

t_lst					*ft_lstnew(char *keyword, char *value);
int						get_info(t_lst ***data, int fd);
int						make_data(t_lst info, char c, t_lst ***data);
int						result_data(t_lst ***data);
void					ft_error(char *str);
void					ft_putstr(char *s);
void					ft_putendl(char *str);
int						ft_strlen(char *str);
char					*ft_strsub(char *str, int start, int len);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strjoin(char *s1, char *s2);
int						get_next_line(char **line, int fd);
void					ft_lstadd(t_lst **alst, t_lst *new);
void					ft_memdel(void **ap);
void					*ft_memchr(const void *s, int c, size_t n);
char					*ft_strnew(int size);
void					ft_strclr(char *s);
char					*ft_strdup(const char *src);

#endif /* !HOTRACE */
