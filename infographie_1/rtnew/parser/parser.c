/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:30:30 by glasset           #+#    #+#             */
/*   Updated: 2014/03/13 16:06:08 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void		parse(t_env *e, char *path)
{
	char	*line;
	int		fd;
	int		current_m;
	f		*ft;

	ft = func();
	current_m = 1;
	if (fd = open(path, ORDONLY) == -1)
		exit(0);
	while (get_next_line(fd, &line))
	{
		current_m += ft...);
		free(line);
	}
	
}
