/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/17 19:52:25 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ESC_KEY 53
#define R_KEY   15

#define SHIFT_KEY   257
#define CTRL_KEY    256

#define UP_KEY		126
#define DOWN_KEY	125
#define RIGHT_KEY	124
#define LEFT_KEY	123

#define HA_MIN 0
#define HA_MAX (M_PI * 2)
#define HA_DELTA (M_PI * 2 / 48)

#define VA_MIN 0
#define VA_MAX (M_PI / 2)
#define VA_DELTA (M_PI / 2 / 8)

#define SCALE_MIN 1
#define SCALE_MAX 40
#define SCALE_DELTA 1

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		va;
	double		ha;
	int			scale;
	t_point		***points;
}				t_data;

int		is_data_equal(const t_data *d1, const t_data *d2)
{
	int		res;

	if (d1 == 0 || d2 == 0)
	{
		if (d1 == 0 && d2 == 0)
			return (1);
		return (0);
	}
	res = (d1->va == d2->va);
	res = res && (d1->ha == d2->ha);
	res = res && (d1->scale == d2->scale);
	return (res);
}

int		key_pressed(int key, void *data)
{
	t_data	ref;
	t_data	*d;
	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	ref = *d;

	if (key >= LEFT_KEY && key <= RIGHT_KEY)
	{
		if (key == LEFT_KEY)
			d->ha = cycle(d->ha - HA_DELTA, HA_MIN, HA_MAX);
		else if (key == RIGHT_KEY)
			d->ha = cycle(d->ha + HA_DELTA, HA_MIN, HA_MAX);
		mlx_clear_window(d->mlx_ptr, d->win_ptr);
		draw_parallel(d->mlx_ptr, d->win_ptr, d->points, d->va, d->ha, d->scale);
		return (0);
	}
	if (key >= DOWN_KEY && key <= UP_KEY)
	{
		if (key == UP_KEY)
			d->va = clamp(d->va + VA_DELTA, VA_MIN, VA_MAX);
		else if (key == DOWN_KEY)
			d->va = clamp(d->va - VA_DELTA, VA_MIN, VA_MAX);
		if (is_data_equal(d, &ref))
		{
			printf("inside KEYS LEFT and RIGHT, old and new is equal, no render\n");
			return (0);
		}
		mlx_clear_window(d->mlx_ptr, d->win_ptr);
		draw_parallel(d->mlx_ptr, d->win_ptr, d->points, d->va, d->ha, d->scale);
		return (0);
	}
	if (key == SHIFT_KEY || key == CTRL_KEY)
	{
		if (key == SHIFT_KEY)
			d->scale = clamp(d->scale + SCALE_DELTA, SCALE_MIN, SCALE_MAX);
		else if (key == CTRL_KEY)
			d->scale = clamp(d->scale - SCALE_DELTA, SCALE_MIN, SCALE_MAX);
		if (is_data_equal(d, &ref))
		{
			printf("inside KEYS SHIFT_KEY and CTRL_KEY, old and new is equal, no render\n");
			return (0);
		}
		mlx_clear_window(d->mlx_ptr, d->win_ptr);
		draw_parallel(d->mlx_ptr, d->win_ptr, d->points, d->va, d->ha, d->scale);
		return (0);
	}
	if (key == R_KEY)
	{
		mlx_clear_window(d->mlx_ptr, d->win_ptr);
		draw_parallel(d->mlx_ptr, d->win_ptr, d->points, d->va, d->ha, d->scale);
	}
	if (key == ESC_KEY)
	{
		printf("esc pressed!\n");
		exit (0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	void * mlx_ptr = mlx_init();
	void * win_ptr = mlx_new_window(mlx_ptr, 1024, 1024, "FdF");

	t_data d = {mlx_ptr, win_ptr, M_PI / 4, -1.0 * M_PI / 8, 20, 0};

	if (argc == 2)
	{
		//t_point *** points = read_points(argv[1]);
		d.points = read_points(argv[1]);
		//d.line_len = line_len;

//		//print_points(points);
//		t0 = clock();
		draw_parallel(mlx_ptr, win_ptr, d.points, d.va, d.ha, d.scale);
//		t1 = clock() - t0;
//		printf("(time: %f), drawn", ((double)t1)/CLOCKS_PER_SEC);
		//print_points(points);
	}

//	t_data d = {mlx_ptr, win_ptr, M_PI / 4, M_PI / 8, 10};
//
	mlx_key_hook(win_ptr, key_pressed, (void *) &d);
//
//	draw_stuff(mlx_ptr, win_ptr, d.va, d.ha, d.scale);

	mlx_loop(mlx_ptr);
	return (0);
}