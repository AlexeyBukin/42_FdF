/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:46 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/19 17:18:35 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>

# define MAX_BLEND 255
# define MIN_BLEND 0

# define BOUND_X 1024
# define BOUND_Y 1024

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
	int 			z;
}					t_line;

typedef struct	s_data
{
	void		*mlx;
	void		*win_ptr;
	double		va;
	double		ha;
	int			scale;
	t_point		***points;
}				t_data;

///___read_point_line.c
t_point				**read_point_line(int fd, int *max_z, int *line_len);

///___read_file.c
t_point				***read_points(char *file, t_point ***pts, int fd);

///___free_funcs.c
void				free_lines(char **lines);
void				free_point_line(t_point **point_line);
void				free_points(t_point ***points);

///___utilities.c
int					atouhi(const char *str);
int					blend(int c1, int c2, unsigned char val);
double				clamp(double val, double min, double max);
double				cycle(double val, double min, double max);

///___convert_coords.c
void				convert_coords(t_point *f, double angle_vertical, double angle_horizontal, int scale);

///___draw_simple_line.c
void				draw_simple_line(void *mlx_p, void *win_p, t_line line);

///___test.c
void				draw_parallel(t_data *data);

///___points_dup.c
t_point				***points_dup(t_point ***points, int l_n, int line_len, int i);

# include "btree_of_lines.h"

#endif