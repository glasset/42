/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegay <alegay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 14:22:05 by glasset           #+#    #+#             */
/*   Updated: 2013/12/31 18:04:55 by alegay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		ft_error(void)
{
	write(2, "usage:./pipex file1 \"cmd1\" \"cmd2\" file2.\n", 41);
	return (0);
}

static void		ft_fork(char **arg, t_stru s, int *fds)
{
	pid_t		father;
	char		**cmd1;
	char		**cmd2;
	int			file[2];
	int			i;

	i = 0;
	file[1] = ft_get_cmd(&cmd1, &cmd2, arg, file[1]);
	file[0] = open(arg[1], O_RDONLY);
	ft_error2(file[0], file[1], arg, &s);
	father = fork();
	if (father == 0)
	{
		dup2(file[0], 0);
		dup2(fds[1], 1);
		ft_exec(s, cmd1, arg[2], s.a);
	}
	else
	{
		wait(&i);
		close(fds[1]);
		dup2(fds[0], 0);
		dup2(file[1], 1);
		ft_exec(s, cmd2, arg[3], 0);
	}
}

void		ft_error2(int a, int b, char **arg, t_stru *s)
{
	if (a == -1 && access(arg[1], F_OK) == -1)
	{
		write(2, "zsh: no such file or directory: ", 32);
		ft_putendl_fd(arg[1], 2);
		s->a = 1;
	}
	else if (a == -1)
	{
		write(2, "zsh: permission denied: ", 24);
		ft_putendl_fd(arg[1], 2);
		s->a = 1;
	}
	if (b == -1)
	{
		write(2, "zsh: permission denied: ", 24);
		ft_putendl_fd(arg[4], 2);
	}
}

int				main(int argc, char **argv, char **envp)
{
	int			*fds;
	t_stru		s;

	s.env = envp;
	fds = (int *)malloc(sizeof(int) * 2);
	pipe(fds);
	if (argc != 5)
		return (ft_error());
	else
	{
		s.path = ft_get_PATH(s.env, s.path);
		ft_fork(argv, s, fds);
	}
	return (0);
}
