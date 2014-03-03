/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:21:34 by glasset           #+#    #+#             */
/*   Updated: 2014/03/03 13:08:31 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H
#include "ray_tracer.h"
#include <string.h>
typedef		int(*f)(t_env *, char *, int);
int			comment(t_env *e, char *str, int m);
int			nbmesch(t_env *e, char *str, int m);
int			nblight(t_env *e, char *str, int m);
int			lookat(t_env *e, char *str, int m);
int			pov(t_env *e, char *str, int m);
int			init_s(t_env *e, char *str, int m);
int			init_l(t_env *e, char *str, int m);

int			ft_atoi(const char *str);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

void		parse(t_env *e, char *path);

#endif 
