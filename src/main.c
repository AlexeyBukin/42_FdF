/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/10 23:40:21 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_pressed()
{
	return (0);
}

int main()
{
	void * mlx_ptr = mlx_init();
	void * win_ptr = mlx_new_window(mlx_ptr, 1024, 768, "FdF");

	t_point green_dot_1;
	green_dot_1.x = 50;
	green_dot_1.y = 50;
	green_dot_1.col = 0x0000FF00;

	t_point green_dot_2;
	green_dot_2.x = 100;
	green_dot_2.y = 75;
	green_dot_2.col = 0x0000FF00;

	draw_simple_line(mlx_ptr, win_ptr, green_dot_1, green_dot_2);

	t_point red_dot;
	red_dot.x = 25;
	red_dot.y = 0;
	red_dot.col = 0x00FF0000;

	draw_simple_line(mlx_ptr, win_ptr, green_dot_1, red_dot);

	t_point blue_dot;
	blue_dot.x = 60;
	blue_dot.y = 200;
	blue_dot.col = 0x000000FF;

	draw_simple_line(mlx_ptr, win_ptr, green_dot_1, blue_dot);

	win_ptr = 0;
	mlx_loop(mlx_ptr);
	return (0);
}