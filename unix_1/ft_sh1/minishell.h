/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 12:12:51 by glasset           #+#    #+#             */
/*   Updated: 2014/01/15 14:16:43 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"

typedef			void(*f)(char **, char ***);

void			cd(char **args, char ***envp);
char			*g_getenv(char *get, char ***env);
char			**g_setenv(char *replace, char *value, char ***env);
void			g_unsetenv(char *free, char ***env);

int				builtins(char **arg, char ***env);

void			gl_sh(char ***env);
void			ft_exec(char *str, char ***env);
char			**get_path(char **path, char ***env);

void			notfound(char *str);
void			notdir(char *str);

#endif /* !MINISHELL_H */
