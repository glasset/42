/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_wolf3d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 15:43:49 by fcorbel           #+#    #+#             */
/*   Updated: 2014/01/07 15:07:02 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <string.h>

# define BUFF_SIZE 4096
# define WIN_X 320
# define WIN_Y 200
# define GRID 64

typedef struct	s_dot
{
	int			x;
	int			y;
	int			color;
}				t_dot;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**map;
	int			*cos;
	int			*tan;
	int			ray_size;
	int			ray_x;
	t_dot		p;
}				t_env;

int				draw_img(t_env *e);
int				init_e(t_env *e, char *path);

void			error(char *s);
size_t			ft_strlen(const char *str);
int				ft_char_int(char c);
int				ft_atoi(const char *str);

#endif
