/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:46 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/22 17:14:19 by kcharla          ###   ########.fr       */
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

# define ESC_KEY 	53
# define R_KEY   	15

# define E_KEY	    14
# define Q_KEY	    12

# define SCROLL_UP 	 4
# define SCROLL_DOWN 5

# define UP_KEY		126
# define DOWN_KEY	125
# define RIGHT_KEY	124
# define LEFT_KEY	123

# define W_KEY	13
# define A_KEY	0
# define S_KEY	1
# define D_KEY	2

# define NUM_1_KEY	18
# define NUM_2_KEY	19
# define NUM_3_KEY	20
# define NUM_4_KEY	21
# define NUM_5_KEY	23

# define MASK_RED   0x00FF0000
# define MASK_GREEN 0x0000FF00
# define MASK_BLUE  0x000000FF

# define HA_MIN 0
# define HA_MAX (M_PI * 2)
# define HA_DELTA (M_PI * 2 / 48)

# define VA_MIN 0
# define VA_MAX (M_PI / 2)
# define VA_DELTA (M_PI / 2 / 8)

# define SCALE_MIN 1
# define SCALE_MAX 40
# define SCALE_DELTA 1

# define HEIGHT_MIN  -10
# define HEIGHT_MAX   10
# define HEIGHT_DELTA 0.2

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				col;
}					t_point;

typedef struct		s_line
{
	t_point			*p1;
	t_point			*p2;
	int				z;
}					t_line;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_adr;
	double			va;
	double			ha;
	int				scale;
	double 			h;
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

void				convert_coords(t_point *f, double a_v, double a_h, int s, double h);

void				draw_simple_line(t_data *data, t_line line);

void				draw_parallel(t_data *data);

t_point				***points_dup(t_point ***points, int l_n, int len, int i);

int					arrows_pressed(int key, t_data *d, t_data *ref);
int					wasd_pressed(int key, t_data *d, t_data *ref);
int					mouse_scrolled(int key, t_data *d, t_data *ref);
int					shift_or_ctrl_pressed(int key, t_data *d, t_data *ref);
int					num_keys_pressed(int key, t_data *d, t_data *ref);

int					is_data_equal(const t_data *d1, const t_data *d2);

int					img_pixel_put(t_data *data, int x, int y, int col);
int					img_clear(t_data *data);

/*
** n		n < M, number of keys keys in node
** 			will always less than order of B tree1
**
** keys 	array of keys (lines)
** *p[M]	(n+1 pointers will be in use)
*/

# define M 22

typedef struct		s_node
{
	int				n;
	t_line			keys[M - 1];
	struct s_node	*p[M];
}					t_node;

int					insert_line_in_btree(t_line key, t_node **root);
int					ins(t_node *r, t_line x, t_line *y, t_node **u);
void				free_btree(t_node *ptr);

void				draw_btree_in_order(t_data *data, t_node **ptr);

#endif
