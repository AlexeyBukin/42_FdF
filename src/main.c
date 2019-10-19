/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/19 11:20:27 by kcharla          ###   ########.fr       */
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

/*
** Function that compares two t_data 'object'
*/

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

/*
** Function that handles arrows buttons
*/

int		arrows_pressed(int key, t_data *d, t_data *ref)
{
	if (key >= LEFT_KEY && key <= RIGHT_KEY)
	{
		if (key == LEFT_KEY)
			d->ha = cycle(d->ha - HA_DELTA, HA_MIN, HA_MAX);
		else if (key == RIGHT_KEY)
			d->ha = cycle(d->ha + HA_DELTA, HA_MIN, HA_MAX);
		mlx_clear_window(d->mlx, d->win_ptr);
		draw_parallel(d->mlx, d->win_ptr, d->points, d->va, d->ha, d->scale);
		return (0);
	}
	if (key >= DOWN_KEY && key <= UP_KEY)
	{
		if (key == UP_KEY)
			d->va = clamp(d->va + VA_DELTA, VA_MIN, VA_MAX);
		else
			d->va = clamp(d->va - VA_DELTA, VA_MIN, VA_MAX);
		if (is_data_equal(d, ref))
			return (0);
		mlx_clear_window(d->mlx, d->win_ptr);
		draw_parallel(d->mlx, d->win_ptr, d->points, d->va, d->ha, d->scale);
		return (0);
	}
	return (0);
}

/*
** Function that handles shift and ctrl buttons
*/

int		shift_or_ctrl_pressed(int key, t_data *d, t_data *ref)
{
	if (key == SHIFT_KEY)
		d->scale = clamp(d->scale + SCALE_DELTA, SCALE_MIN, SCALE_MAX);
	else
		d->scale = clamp(d->scale - SCALE_DELTA, SCALE_MIN, SCALE_MAX);
	if (is_data_equal(d, ref))
		return (0);
	mlx_clear_window(d->mlx, d->win_ptr);
	draw_parallel(d->mlx, d->win_ptr, d->points, d->va, d->ha, d->scale);
	return (0);
}

/*
** Function that handles key input
*/

int		key_pressed(int key, void *data)
{
	t_data	ref;
	t_data	*d;

	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	ref = *d;
	if (key >= LEFT_KEY && key <= UP_KEY)
		return (arrows_pressed(key, data, &ref));
	if (key == SHIFT_KEY || key == CTRL_KEY)
		return (shift_or_ctrl_pressed(key, data, &ref));
	if (key == R_KEY)
	{
		mlx_clear_window(d->mlx, d->win_ptr);
		draw_parallel(d->mlx, d->win_ptr, d->points, d->va, d->ha, d->scale);
	}
	if (key == ESC_KEY)
		exit(0);
	return (0);
}

/*
** Main function
*/

int		main(int argc, char **argv)
{
	t_data		d;
	void		*mlx;
	void		*win_ptr;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, BOUND_X, BOUND_Y, "FdF");
	d.mlx = mlx;
	d.win_ptr = win_ptr;
	d.va = M_PI / 4;
	d.ha = -1.0 * M_PI / 8;
	d.scale = 20;
	d.points = NULL;
	if (argc == 2)
	{
		d.points = read_points(argv[1], d.points, d.points, d.scale);
		if (d.points != 0)
		{
			draw_parallel(mlx, win_ptr, d.points, d.va, d.ha, d.scale);
			mlx_key_hook(win_ptr, key_pressed, (void *)&d);
			mlx_loop(mlx);
		}
		ft_putstr("error occurred while reading file\n");
		return (0);
	}
	ft_putstr("usage: ./fdf file.fdf\n");
	return (0);
}
