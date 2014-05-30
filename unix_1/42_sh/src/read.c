/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 18:29:42 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/27 10:49:20 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void			ft_read(t_sh *sh)
{
	int			ret;
	char		buf[BSIZE + 1];
	char		*str;
	char		*tmp;

	ret = -2;
	tmp = ft_strnew(1);
	while ((ret < -1 || buf[ret - 1] != '\n') && (ret = read(0, buf, BSIZE)))
	{
		buf[ret] = 0;
		tmp = ft_strjoin_free(tmp, buf);
	}
	str = ft_strrepl(tmp, "\n", NULL);
	ft_strdel(&tmp);
	if (ft_strnlen(str, 1))
		ft_inspect_read(sh, str);
	ft_strdel(&str);
}

char			*ft_read_fd(int fd)
{
	int		ret;
	int		len;
	char	*str;
	char	buf[BSIZE + 1];

	len = 0;
	ret = -2;
	str = NULL;
	fd = fd < 0 ? 0 : fd;
	while ((ret < -1 || buf[ret - 1] != '\n') && (ret = read(fd, buf, BSIZE)))
	{
		if (!str)
			str = ft_strnew(0);
		buf[ret] = 0;
		str = ft_strjoin_free(str, buf);
		len += ret;
	}
	if (str && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

void			ft_inspect_read(t_sh *sh, char *str)
{
	int			i;
	char		**cmd_lst;

	i = -1;
	if (!(str = ft_strtrim(str)))
		return ;
	cmd_lst = ft_strsplit_esc(str, ';');
	while (cmd_lst && cmd_lst[++i])
		ft_logic_operator_and(sh, cmd_lst[i]);
	ft_strtabdel(&cmd_lst);
}
