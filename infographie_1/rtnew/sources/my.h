/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:21:34 by glasset           #+#    #+#             */
/*   Updated: 2014/03/07 11:47:24 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H
#include "ray_tracer.h"
#include <string.h>

typedef		int(*f)(t_env *, char *);

int			comment(t_env *e, char *str);
int			nbmesh(t_env *e, char *str);
int			nblight(t_env *e, char *str);
int			lookat(t_env *e, char *str);
int			pov(t_env *e, char *str);
int			init_mesh(t_env *e, char *str);
int			init_l(t_env *e, char *str);
int			ambient(t_env *e, char *str);

int			init_s(t_env *e, char *str, int c);
int			init_p(t_env *e, char *str, int c);
int			init_cyl(t_env *e, char *str, int c);
int			init_cone(t_env *e, char *str, int c);

int			badcoeff(char **tmp, int start);
double		ft_atod(char *str);
int			ft_atoi(const char *str);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

t_color		get_color(char *str);
int			no_name(char **tmp);
void		error_p(int error, int line, char *str);

void		parse(t_env *e, char *path);
#endif 
