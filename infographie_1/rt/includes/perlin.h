/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:20:58 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/26 16:21:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# define PERSISTANCE 0.7
# define FREQUENCY 0.2
# define OCTAVES 5

# define OCEAN 10
# define DIF 1
# define SPE 2
# define INTER 3

# include "ray_tracer.h"

typedef struct	s_perlin
{
	t_vertex	integer;
	t_vertex	fract;
	t_vertex	a;
	t_vertex	b;
	t_vertex	c;
	t_vertex	d;
	double		v;
	double		w;
}				t_perlin;

typedef struct	s_effect
{
	t_color		color;
	t_vertex	c1;
	t_vertex	c2;
	double		value;
	double		result;
}				t_effect;

double			noise_3d(double x, double y, double z);
double			cos_interpolate(double a, double b, double t);
double			ft_perlin(double x, double y, double z);
t_color			perlin_zebra(t_vertex var, t_color pix1, t_color pix2, int n);
double			perlin_ocean(t_env *e, t_vertex pos, int type, int light);
t_color			perlin_marble(t_vertex var, t_color pix1, t_color pix2, int n);
t_color			perlin_wood(t_vertex var, t_color pix1, t_color pix2, int n);
t_color			checker1(t_vertex var, t_color pix1, t_color pix2, int n);
t_color			checker2(t_vertex var, t_color pix1, t_color pix2, int n);
t_color			checker3(t_vertex var, t_color pix1, t_color pix2, int n);
t_color			no_mat(t_vertex var, t_color pix1, t_color pix2, int n);
t_color			cell_shading(t_env *e, t_color color);

#endif
