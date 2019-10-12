/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/12 04:59:26 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_stuff(void *mlx_ptr, void *win_ptr, double va, double ha, int scale)
{

	t_point red_dot = {4, 4, 0, 0x00FF0000};
	red_dot = convert_coords(red_dot, va, ha, scale);

	t_point green_dot = {-4, -4, 0, 0x0000FF00};
	green_dot = convert_coords(green_dot, va, ha, scale);

	t_point blue_dot = {-4, 4, 0, 0x000000FF};
	blue_dot = convert_coords(blue_dot, va, ha, scale);

	t_point pink_dot = {4, -4, 0, 0x00FF00FF};
	pink_dot = convert_coords(pink_dot, va, ha, scale);

	t_point white_dot = {0, 0,10, 0x00FFFFFF};
	white_dot = convert_coords(white_dot, va, ha, scale);

	t_line l1 = {&red_dot, &green_dot};
	t_line l2 = {&green_dot, &blue_dot};
	t_line l3 = {&blue_dot, &pink_dot};
	t_line l4 = {&pink_dot, &red_dot};
	t_line l5 = {&pink_dot, &green_dot};
	t_line l6 = {&red_dot, &blue_dot};

	t_line w1 = {&white_dot, &green_dot};
	t_line w2 = {&white_dot, &red_dot};
	t_line w3 = {&white_dot, &blue_dot};
	t_line w4 = {&white_dot, &pink_dot};

	draw_simple_line(mlx_ptr, win_ptr, l1);
	draw_simple_line(mlx_ptr, win_ptr, l2);
	draw_simple_line(mlx_ptr, win_ptr, l3);
	draw_simple_line(mlx_ptr, win_ptr, l4);
	draw_simple_line(mlx_ptr, win_ptr, l5);
	draw_simple_line(mlx_ptr, win_ptr, l6);

	draw_simple_line(mlx_ptr, win_ptr, w1);
	draw_simple_line(mlx_ptr, win_ptr, w2);
	draw_simple_line(mlx_ptr, win_ptr, w3);
	draw_simple_line(mlx_ptr, win_ptr, w4);
//	///0x00888080
//	t_point grey_dot = {300, 300, 0, 0x00AAAAAA};
//	t_point red_dot_2 = {350, 350, 0, 0x00FFFFFF};
//	t_line blend_line = {&grey_dot, &red_dot_2};
//	draw_simple_line(mlx_ptr, win_ptr, blend_line);
}