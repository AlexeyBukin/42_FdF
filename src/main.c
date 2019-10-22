/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/22 16:24:46 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that handles red cross exit
*/

int		close_on_x(void *param)
{
	(void)param;
	exit(0);
}

/*
** Function that handles mouse scroll
*/

int		on_mouse_scrolled(int key, int x, int y, void *data)
{
	t_data	ref;
	t_data	*d;

	x = y;
	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	ref = *d;
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		return (mouse_scrolled(key, data, &ref));
	return (-1);
}

/*
** Function that handles ESC key exit
*/

int		on_key_pressed(int key, void *data)
{
	t_data	ref;
	t_data	*d;

	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	ref = *d;
	if (arrows_pressed(key, data, &ref) >= 0)
		return (0);
	if (wasd_pressed(key, data, &ref) >= 0)
		return (0);
	if (shift_or_ctrl_pressed(key, data, &ref) >= 0)
		return (0);
	if (num_keys_pressed(key, data, &ref) >= 0)
		return (0);
	if (key == R_KEY)
	{
		mlx_clear_window(d->mlx, d->win);
		draw_parallel(d);
	}
	if (key == ESC_KEY)
		exit(0);
	return (0);
}

/*
** Function that initialize data structure
*/

#include <stdio.h>

int		init_data(t_data *data)
{
	int 	endian;
	int 	size_line;
	int 	bps;

	if (data == NULL)
		return (-1);
	endian = 0;
	size_line = 0;
	bps = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, BOUND_X, BOUND_Y, "FdF");
	data->img = mlx_new_image(data->mlx, BOUND_X, BOUND_Y);
	data->img_adr = mlx_get_data_addr(data->img, &bps, &size_line, &endian);
	printf("size_line: %d, endian: %d, bits_per_pixel: %d\n", size_line, endian, bps);

	data->va = M_PI / 4;
	data->ha = -1.0 * M_PI / 8;
	data->scale = 20;
	if (data->mlx == NULL || data->win == NULL)
		return (-1);
	if (data->img == NULL || data->img_adr == NULL)
		return (-2);
	return (0);
}

/*
** Main function
*/

int		main(int argc, char **argv)
{
	t_data		data;

	if (init_data(&data) < 0)
	{
		ft_putstr("failed to init, exit...\n");
		return (-1);
	}
	if (argc == 2)
	{
		data.points = read_points(argv[1], 0, 0, 0);
		if (data.points != NULL)
		{
			draw_parallel(&data);
			mlx_hook(data.win, 17, 0, close_on_x, (void *)&data);
			mlx_hook(data.win, 2, 0, on_key_pressed, (void *)&data);
			mlx_hook(data.win, 4, 0, on_mouse_scrolled, (void *)&data);
			mlx_loop(data.mlx);
		}
		ft_putstr("error occurred while reading file\n");
		return (0);
	}
	ft_putstr("usage: ./fdf file.fdf\n");
	return (0);
}
