/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/13 20:11:58 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_stuff(void *mlx_ptr, void *win_ptr, double va, double ha, int scale)
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

t_point		**points_dup(t_point **points, int line_len)
{
	t_point	**p_dup;
	int		line_num;
	int		i;
	int 	j;

	line_num = 0;
	while (points[line_num] != 0)
		line_num++;

	p_dup = (t_point **)malloc(sizeof(t_point *) * (line_num + 1));
	if (p_dup == 0)
		return (0);
	p_dup[line_num] = 0;
	i = 0;
	while (i < line_num)
	{
		p_dup[i] = (t_point *)malloc(sizeof(t_point) * line_len);
		if (p_dup[i] == 0)
		{
			free_points(p_dup, line_len);
			return (0);
		}
		j = 0;
		while (j < line_len)
		{
			p_dup[i][j] = points[i][j];
			j++;
		}
		i++;
	}
	return (p_dup);
}

t_point		**new_points_as(t_point **points, int line_len)
{
	t_point	**p_dup;
	int		line_num;
	int		i;

	line_num = 0;
	while (points[line_num] != 0)
		line_num++;

	p_dup = (t_point **)malloc(sizeof(t_point *) * (line_num + 1));
	if (p_dup == 0)
		return (0);
	p_dup[line_num] = 0;
	i = 0;
	while (i < line_num)
	{
		p_dup[i] = (t_point *)malloc(sizeof(t_point) * line_len);
		if (p_dup[i] == 0)
		{
			free_points(p_dup, line_len);
			return (0);
		}
		i++;
	}
	return (p_dup);
}

void		draw_points(void *mlx_ptr, void *win_ptr, t_point **points, int line_len, double va, double ha, int scale)
{
	t_point blue_dot = {256, 0, 0, 0x000000FF};
	t_point blue_dot_2 = {256, 512, 0, 0x000000FF};

	t_point blue_dot_3 = {0, 256, 0, 0x000000FF};
	t_point blue_dot_4 = {512, 256, 0, 0x000000FF};

	t_line b1 = {&blue_dot, &blue_dot_2};
	t_line b2 = {&blue_dot_3, &blue_dot_4};

	draw_simple_line(mlx_ptr, win_ptr, b1);
	draw_simple_line(mlx_ptr, win_ptr, b2);


	//t_line	lines[100];
	t_point		**new_points;

	int 	line_num;
	int		i;
	int 	j;

	line_num = 0;
	i = 0;
	new_points = new_points_as(points, line_len);
	while (points[i] != 0)
	{
		line_num++;
		j = 0;
		while (j < line_len)
		{
			new_points[i][j] = convert_coords(points[i][j], va, ha, scale);
			j++;
		}
		i++;
	}
	//new_points[i] = (t_point *) 0;

	printf("\n");
	print_colors(new_points, line_len);
	//print_points(new_points, line_len);
	printf("\n");


	i = 0;
	while (i < line_num)
	{
		j = 0;
		while (j < line_len - 1)
		{
			//t_line tmp = {&points[i][j], &points[i][j+1]};
			t_line tmp = {&new_points[i][j], &new_points[i][j+1]};
			draw_simple_line(mlx_ptr, win_ptr, tmp);
			j++;
		}
		i++;
	}

	i = 0;
	while (i < line_len)
	{
		j = 0;
		while (j < line_num - 1)
		{
			t_line tmp = {&new_points[j][i], &new_points[j + 1][i]};
			draw_simple_line(mlx_ptr, win_ptr, tmp);
			j++;
		}
		i++;
	}


//	t_point red_dot = convert_coords(points[0][0], va, ha, scale);
//	t_point red_dot_2 = convert_coords(points[0][1], va, ha, scale);
//	t_point red_dot_3 = convert_coords(points[0][2], va, ha, scale);
//
//	t_point green_dot = convert_coords(points[1][0], va, ha, scale);
//
//	t_line l1 = {&red_dot, &red_dot_2};
//	t_line l2 = {&red_dot_2, &red_dot_3};
//	t_line l3 = {&red_dot, &green_dot};
//
//	draw_simple_line(mlx_ptr, win_ptr, l1);
//	draw_simple_line(mlx_ptr, win_ptr, l3);
//	draw_simple_line(mlx_ptr, win_ptr, l2);
}