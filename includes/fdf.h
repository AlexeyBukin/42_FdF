/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:46 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/20 19:58:13 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include "btree_of_lines.h"

# define MAX_BLEND 255
# define MIN_BLEND 0

# define BOUND_X 1024
# define BOUND_Y 1024

typedef struct		s_data
{
	void			*mlx;
	void			*win_ptr;
	double			va;
	double			ha;
	int				scale;
	t_point			***points;
}					t_data;

t_point				**read_point_line(int fd, int *max_z, int *line_len);

t_point				***read_points(char *f, t_point ***pts, int fd, int m_z);

void				free_lines(char **lines);
void				free_point_line(t_point **point_line);
void				free_points(t_point ***points);

int					atouhi(const char *str);
int					blend(int c1, int c2, unsigned char val);
double				clamp(double val, double min, double max);
double				cycle(double val, double min, double max);

void				convert_coords(t_point *f, double a_v, double a_h, int s);

void				draw_simple_line(void *mlx_p, void *win_p, t_line line);

void				draw_parallel(t_data *data);

t_point				***points_dup(t_point ***points, int l_n, int len, int i);

#endif
