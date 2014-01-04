/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegay <alegay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:23:24 by glasset           #+#    #+#             */
/*   Updated: 2013/12/31 18:04:00 by alegay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef			struct	s_stru
{
	char	**env;
	int		a;
	char	**path;
}						t_stru;

char		**ft_get_PATH(char **env, char **path);
void		ft_exec(t_stru s, char **cmd1, char *arg, int a);
int			ft_get_cmd(char ***cmd, char ***cmd2, char **arg, int file);
void		ft_error2(int a, int b, char **arg, t_stru *s);

#endif /* !PIPEX_H */
