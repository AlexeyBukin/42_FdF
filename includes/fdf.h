/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:46 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/13 06:24:57 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "mlx.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <math.h>

#define MAX_BLEND 255
#define MIN_BLEND 0

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

///___read_file.c
t_point				**read_points(char *file, int *ret_len);

///___free_funcs.c
void				free_lines(char **lines);
void				free_points(t_point **points, int line_num);

///___utilities.c
int					atouhi(const char *str);
int					blend(int c1, int c2, unsigned char val);
double				clamp(double val, double min, double max);
double				cycle(double val, double min, double max);

///___convert_coords.c
t_point				convert_coords(t_point f,  double vert_angle, double hor_angle, int scale);

///___draw_simple_line.c
void				draw_simple_line(void *mlx_p, void *win_p, t_line line);

///___printables.c
void				print_point(t_point p);

///___test.c
void				draw_stuff(void *mlx_ptr, void *win_ptr, double vert_angle, double hor_angle, int scale);
void				draw_points(void *mlx_ptr, void *win_ptr, t_point **points, int line_len, double va, double ha, int scale);

#endif