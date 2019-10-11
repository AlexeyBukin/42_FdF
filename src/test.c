/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/11 23:03:48 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//double to_degrees(double radians) {
//	return radians * (180.0 / M_PI);
//}

t_point		convert_coords(t_point f)
{
	t_point	v;
	int		x0 = 256;
	int		y0 = 256;
	int		tile_size = 20;

	printf("before: \n");
	print_point(f);

	double pi = M_PI;
	double angle_vertical = pi / 2 / 100 * 50;
	double angle_horizontal = pi * 2 / 360 * 30;

	double z_size = round(tile_size * cos(angle_vertical));

	v.x = f.x * tile_size;
	v.y = f.y * tile_size;
	v.z = f.z * tile_size;

	int radius_squared = v.x * v.x + v.y * v.y;
	double radius = (radius_squared <= 0) ? 0 : (int) sqrt(radius_squared);

//	int old_angle = (int) to_degrees(atan2(f.y, f.x));
//
//	v.x = x0 + radius * cos(atan2(f.y, f.x));
//	v.y = y0 + radius * sin(atan2(f.y, f.x));
//	printf("old x: %d, old y: %d\n", v.x, v.y);
//	printf("x0: %d, cos: %f\n", x0, cos(atan2(f.y, f.x) + angle_horizontal));

	v.x = x0 + round(radius * cos(atan2(f.y, f.x) + angle_horizontal));
	///v.y = y0 + round(radius * sin(atan2(f.y, f.x) + angle_horizontal));

	double z_a_size = 1 * sin(angle_vertical);
	printf("z_a_size: %f\n", z_a_size);

	v.y = y0 + round(z_a_size * radius * sin(atan2(f.y, f.x) + angle_horizontal));

//	v.y = v.y * z_size;

	v.z = f.z * z_size;
	v.y = v.y - v.z;
	v.col = f.col;

//	int new_angle = (int) to_degrees(atan2(f.y, f.x) + angle_horizontal);
//
//
//	printf("add_pixels_x: %d, x now: %d\n", (int) (radius * cos(atan2(f.y, f.x) + angle_horizontal)), v.x);
//	printf("add_pixels_y: %d, y now: %d\n", (int) (radius * sin(atan2(f.y, f.x) + angle_horizontal)), v.y);
//	printf("radius: %f, old angle: %d, new angle: %d\n", radius, old_angle, new_angle);
//
//	printf("after: \n");
	print_point(v);

	printf("\n");
	return (v);
}

void	draw_stuff(void *mlx_ptr, void *win_ptr)
{

	t_point red_dot;
	red_dot.x = 4;
	red_dot.y = 4;
	red_dot.z = 0;
	red_dot.col = 0x00FF0000;
	red_dot = convert_coords(red_dot);

	t_point green_dot;
	green_dot.x = -4;
	green_dot.y = -4;
	green_dot.z = 0;
	green_dot.col = 0x0000FF00;
	green_dot = convert_coords(green_dot);

	t_point blue_dot;
	blue_dot.x = -4;
	blue_dot.y = 4;
	blue_dot.z = 0;
	blue_dot.col = 0x000000FF;
	blue_dot = convert_coords(blue_dot);

	t_point pink_dot;
	pink_dot.x = 4;
	pink_dot.y = -4;
	pink_dot.z = 0;
	pink_dot.col = 0x00FF00FF;
	pink_dot = convert_coords(pink_dot);

	t_point white_dot;
	white_dot.x = 0;
	white_dot.y = 0;
	white_dot.z = 10;
	white_dot.col = 0x00FFFFFF;
	white_dot = convert_coords(white_dot);

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
//	t_point res1 = convert_coords(red_dot);
//	t_point res2 = convert_coords(green_dot);
//	t_point res3 = convert_coords(blue_dot);
//	t_point res4 = convert_coords(pink_dot);


	//draw_simple_line(mlx_ptr, win_ptr, l);
//	draw_simple_line(mlx_ptr, win_ptr, res2, res3);
//	draw_simple_line(mlx_ptr, win_ptr, res3, res1);
//	draw_simple_line(mlx_ptr, win_ptr, res4, res2);
}