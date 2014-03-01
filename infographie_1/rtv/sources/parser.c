/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:47:43 by glasset           #+#    #+#             */
/*   Updated: 2014/03/01 19:55:21 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

f				*funct(void)
{
	f			*ft;
	ft = malloc(sizeof(ft) * 8);
	ft[0] = &comment;
	ft[1] = &base;
	ft[2] = &init_c;
	ft[3] = &init_s;
	return (ft);
}

int				check_line(char *str)
{
	char		*opt;
	int			i;
	f			*ft;

	ft = funct();
	i = -1;
	opt = "|CSPLC"
	while (opt[++i])
	{
		if (opt[i] == str[0])
			return (i + 1);
	}
	return (0);

void			parse(t_env *e, char *path)
{
	char		*line;
	int			fd;
	int			current_m;

	current_m = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		current_m = f[check_line(line)](e, line, current_m);
		free(line);
	}
}
