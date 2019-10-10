/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/10 08:35:37 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

#include <stdio.h>

int key_pressed()
{
	return (0);
}

int main()
{
	void * mlx_ptr = mlx_init();
	void * win_ptr = mlx_new_window(mlx_ptr, 1024, 768, "my new window");


	printf("\n\ngreen: \n");
	t_line green_line;
	green_line.x1 = 50;
	green_line.y1 = 50;
	green_line.x2 = 0;
	green_line.y2 = 75;
	green_line.color = 0x0000FF00;
	draw_simple_line(mlx_ptr, win_ptr, green_line);

	green_line.x1 = 50;
	green_line.y1 = 50;
	green_line.x2 = 0;
	green_line.y2 = 25;
	draw_simple_line(mlx_ptr, win_ptr, green_line);

	green_line.x1 = 50;
	green_line.y1 = 50;
	green_line.x2 = 0;
	green_line.y2 = 50;
	draw_simple_line(mlx_ptr, win_ptr, green_line);

	printf("\n\nblue: \n");
	t_line blue_line;
	blue_line.x1 = 50;
	blue_line.y1 = 50;
	blue_line.x2 = 100;
	blue_line.y2 = 25;
	blue_line.color = 0x000000FF;
	draw_simple_line(mlx_ptr, win_ptr, blue_line);

	blue_line.x1 = 50;
	blue_line.y1 = 50;
	blue_line.x2 = 100;
	blue_line.y2 = 75;
	draw_simple_line(mlx_ptr, win_ptr, blue_line);

	blue_line.x1 = 50;
	blue_line.y1 = 50;
	blue_line.x2 = 100;
	blue_line.y2 = 50;
	draw_simple_line(mlx_ptr, win_ptr, blue_line);

	printf("\n\nred: \n");
	t_line red_line;
	red_line.x1 = 50;
	red_line.y1 = 50;
	red_line.x2 = 75;
	red_line.y2 = 0;
	red_line.color = 0x00FF0000;
	draw_simple_line(mlx_ptr, win_ptr, red_line);

	red_line.x1 = 50;
	red_line.y1 = 50;
	red_line.x2 = 25;
	red_line.y2 = 0;
	draw_simple_line(mlx_ptr, win_ptr, red_line);

	red_line.x1 = 50;
	red_line.y1 = 50;
	red_line.x2 = 50;
	red_line.y2 = 0;
	draw_simple_line(mlx_ptr, win_ptr, red_line);

	printf("\n\nwhite: \n");
	t_line white_line;
	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 75;
	white_line.y2 = 100;
	white_line.color = 0x00FFFFFF;
	draw_simple_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 25;
	white_line.y2 = 100;
	draw_simple_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 51;
	white_line.y2 = 100;
	draw_simple_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 49;
	white_line.y2 = 100;
	draw_simple_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 50;
	white_line.y2 = 100;
	draw_simple_line(mlx_ptr, win_ptr, white_line);


	win_ptr = 0;
	mlx_loop(mlx_ptr);
	return (0);
}