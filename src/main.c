/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/20 22:16:41 by kcharla          ###   ########.fr       */
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
	if (key >= LEFT_KEY && key <= UP_KEY)
		return (arrows_pressed(key, data, &ref));
//	if (key == SHIFT_KEY || key == CTRL_KEY)
//		return (shift_or_ctrl_pressed(key, data, &ref));
	if (key == R_KEY)
	{
		mlx_clear_window(d->mlx, d->win_ptr);
		draw_parallel(d);
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
	t_data		data;
	void		*mlx;
	void		*win_ptr;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, BOUND_X, BOUND_Y, "FdF");
	data.mlx = mlx;
	data.win_ptr = win_ptr;
	data.va = M_PI / 4;
	data.ha = -1.0 * M_PI / 8;
	data.scale = 20;
	if (argc == 2)
	{
		data.points = read_points(argv[1], 0, 0, 0);
		if (data.points != NULL)
		{
			draw_parallel(&data);

			mlx_hook(win_ptr, 17, 0, close_on_x, (void *)&data);
			mlx_hook(win_ptr, 2, 0, on_key_pressed, (void *)&data);
			mlx_hook(win_ptr, 4, 0, on_mouse_scrolled, (void *)&data);
			mlx_loop(mlx);
		}
		ft_putstr("error occurred while reading file\n");
		return (0);
	}
	ft_putstr("usage: ./fdf file.fdf\n");
	return (0);
}
