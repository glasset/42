/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 12:15:32 by glasset           #+#    #+#             */
/*   Updated: 2013/12/21 11:22:44 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 4096
# include "libft.h"

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;


typedef struct		s_line
{
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				x;
	int				y;
	int				cumul;
}					t_line;

void				ft_printempty(char *str);
void				ft_printusage(char *str);
void				ft_printperror(char *str);
int					ft_abs(int c);
int					get_next_line(int const fd, char **line);
int					ft_count(char *str);
t_point				*ft_getnbr(char *str, int q);
int					ft_open(char *str, t_point ***t);
void				ft_display_line(t_mlx **p, t_point s, t_point x, int u);
void				ft_display_all(t_point **s, t_mlx **t, int u);
t_point				ft_iso(int x, int y, int z);

int					ft_check(t_point **s);

#endif /* !FDF_H */
