/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 23:33:24 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 13:08:15 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H
# define SH42_H
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define OR 1
# define AND 2
# define ENV (sh->env)
# define DEF_ENV (sh->def_env)
# define LAST_RET_VAL (sh->last_ret_val)
# define BSIZE 1024
# define PGNAME "42sh"

# include <stdlib.h>

typedef struct		s_sh
{
	int				end;
	int				exit_ret;
	unsigned char	last_ret_val;
	char			warn_bypass;
	char			**env;
	char			**def_env;
}					t_sh;

int					ft_error1(char *error);
int					ft_error2(char *error, char *name);
int					ft_error3(char *prog, char *error, char *name);

void				ft_read(t_sh *sh);
char				*ft_read_fd(int fd);
void				ft_inspect_read(t_sh *sh, char *str);
void				ft_logic_operator_and(t_sh *sh, char *str);

int					ft_check_located_cmd(t_sh *sh, char **args);
int					ft_check_unlocated_cmd(t_sh *sh, char **args);
void				ft_fork_and_exec(t_sh *sh, char *path, char **args);
void				ft_exec_cmd(t_sh *sh, pid_t pid, char *path, char **args);
char				*ft_read_cmd_result(t_sh *sh, char *path, char **args);

char				**ft_create_args(t_sh *sh, char *str);
char				*ft_repl_dollars(t_sh *sh, char *str);
char				*ft_repl_tilds(t_sh *sh, char *str);
char				**ft_strsplit_esc(char *str, char c);
int					ft_builtin(t_sh *sh, char **args);

int					ft_cd(t_sh *sh, char **cmd);
int					ft_env(t_sh *sh, char **args, char **env);
int					ft_envsize(char **env);
int					ft_defaultenv(t_sh *sh);
int					ft_newenv(t_sh *sh, char **env);
int					ft_is_inenv(char **env, char *key);
int					ft_setenv(t_sh *sh, char ***env, char *key, char *value);
int					ft_setallenv(t_sh *sh, char *key, char *value);
int					ft_unsetenv(t_sh *sh, char ***env, char *key);
int					ft_unsetenv_all(t_sh *sh, char *key);
char				*ft_search_inenv(char **env, char *key);
char				*ft_search_inallenv(t_sh *sh, char *key);

#endif
