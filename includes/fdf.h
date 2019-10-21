/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:46 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/21 18:50:42 by kcharla          ###   ########.fr       */
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

# define ESC_KEY 	53
# define R_KEY   	15
# define SCROLL_UP 	4
# define SCROLL_DOWN 5

# define UP_KEY		126
# define DOWN_KEY	125
# define RIGHT_KEY	124
# define LEFT_KEY	123

# define HA_MIN 0
# define HA_MAX (M_PI * 2)
# define HA_DELTA (M_PI * 2 / 48)

# define VA_MIN 0
# define VA_MAX (M_PI / 2)
# define VA_DELTA (M_PI / 2 / 8)

# define SCALE_MIN 1
# define SCALE_MAX 40
# define SCALE_DELTA 1

typedef struct		s_data
{
	void			*mlx;
	void			*win_ptr;
	double			va;
	double			ha;
	int				scale;
	t_point			***points;
}					t_data;

t_point				**read_point_line(int fd, int *m_z, int *l_len, char *l);

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

int					arrows_pressed(int key, t_data *d, t_data *ref);
int					mouse_scrolled(int key, t_data *d, t_data *ref);
int					shift_or_ctrl_pressed(int key, t_data *d, t_data *ref);

int					is_data_equal(const t_data *d1, const t_data *d2);

#endif
