/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:46 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/12 01:17:53 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "mlx.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

typedef struct		s_point
{
	int 			x;
	int 			y;
	int 			z;
	int 			col;
}					t_point;

typedef struct		s_line
{
	t_point			*p1;
	t_point			*p2;
}					t_line;

///convert_coords.c
t_point				convert_coords(t_point f,  double vert_angle, double hor_angle, int scale);

///re_draw.c
void				re_draw(void *mlx_ptr, void *win_ptr, double vert_angle, double hor_angle, int scale);

///draw_simple_line.c
void				draw_simple_line_by_points(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2);
void				draw_simple_line(void *mlx_p, void *win_p, t_line line);

///printables.c
void				print_point(t_point p);

///test.c
void				draw_stuff(void *mlx_ptr, void *win_ptr, double vert_angle, double hor_angle, int scale);

#endif