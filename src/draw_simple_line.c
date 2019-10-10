/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_simple_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:29 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/10 08:45:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

void make_drawable_simple_y(t_line *line)
{
	if (line->y1 > line->y2)
	{
		int tmp;
		tmp = line->x1;
		line->x1 = line->x2;
		line->x2 = tmp;

		tmp = line->y1;
		line->y1 = line->y2;
		line->y2 = tmp;
	}
}

void make_drawable_simple_x(t_line *line)
{
	if (line->x1 > line->x2)
	{
		int tmp;
		tmp = line->x1;
		line->x1 = line->x2;
		line->x2 = tmp;

		tmp = line->y1;
		line->y1 = line->y2;
		line->y2 = tmp;
	}
}

/*
 * Draws a simple line with (|k| < 1)
 *
 * delta_y = ft_abs(l.y2 - l.y1);
 */

void	draw_simple_line_x(void *mlx_ptr, void *win_ptr, t_line l)
{
	int error;
	int dir_y;
	int delta_x;
	int x;
	int y;

	make_drawable_simple_x(&l);
	delta_x = ft_abs(l.x2 - l.x1);
	error = 0;
	dir_y = l.y2 - l.y1;
	dir_y = (dir_y > 0) - (dir_y < 0);
	x = l.x1;
	y = l.y1;
	while (x <= l.x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, l.color);
		error += ft_abs(l.y2 - l.y1);
		if (2 * error >= delta_x)
		{
			y += dir_y;
			error = error - delta_x;
		}
		x++;
	}
}

/*
 * Draws a simple line with (|k| > 1)
 *
 * delta_x = ft_abs(l.x2 - l.x1);
 */

void	draw_simple_line_y(void *mlx_ptr, void *win_ptr, t_line l)
{
	int error;
	int dir_x;
	int delta_y;
	int x;
	int y;

	make_drawable_simple_y(&l);
	error = 0;
	delta_y = ft_abs(l.y2 - l.y1);
	dir_x = l.x2 - l.x1;
	dir_x = (dir_x > 0) - (dir_x < 0);
	x = l.x1;
	y = l.y1;
	while (y <= l.y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, l.color);
		error += ft_abs(l.x2 - l.x1);
		if (2 * error >= delta_y)
		{
			x += dir_x;
			error -= delta_y;
		}
		y++;
	}
}

void	draw_simple_line(void *mlx_ptr, void *win_ptr, t_line l)
{
	double k;

	k = (l.x2 == l.x1) ? 1 : (l.y2 - l.y1 + 0.0) / (l.x2 - l.x1 + 0.0);
	if (ft_abs(k) >= 1)
		draw_simple_line_y(mlx_ptr, win_ptr, l);
	else
		draw_simple_line_x(mlx_ptr, win_ptr, l);
}
