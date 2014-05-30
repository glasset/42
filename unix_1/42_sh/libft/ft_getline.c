/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 08:52:26 by fkalb             #+#    #+#             */
/*   Updated: 2014/03/25 18:51:24 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

static char			*ft_rea_str(char *dst, char *buf, char **base)
{
	char			*tmp;
	size_t			len;

	len = ft_strlen(dst);
	tmp = malloc(len + ft_strlen(buf) + 1);
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, dst);
	ft_strcpy(tmp + len, buf);
	free(*base);
	*base = tmp;
	return (tmp);
}

static int			ft_line(char **line, char **str, char *zero)
{
	*zero = 0;
	*line = ft_strdup(*str);
	*str = zero + 1;
	return (1);
}

static int			ft_final_line(char **line, char *str, char *base)
{
	if (*str)
	{
		*line = ft_strdup(str);
		*str = 0;
		return (1);
	}
	ft_strdel(&base);
	return (0);
}

int					ft_getline(int fd, char **line)
{
	char			buf[16 + 1];
	static char		*str;
	static char		*str_base;
	char			*zero;
	int				ret;

	if (!str)
	{
		str = malloc(1);
		str_base = str;
		*str = 0;
	}
	zero = ft_strchr(str, '\n');
	while (!zero && (ret = read(fd, buf, 16)))
	{
		if (ret < 0)
			return (ret);
		buf[ret] = 0;
		if ((str = ft_rea_str(str, buf, &str_base)) == NULL)
			return (-1);
		zero = ft_strchr(str, '\n');
	}
	if (zero)
		return (ft_line(line, &str, zero));
	return (ft_final_line(line, str, str_base));
}
