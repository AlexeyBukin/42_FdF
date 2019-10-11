/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_simple_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:29 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/11 20:38:23 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_simple_line_x(void *m_p, void *w_p, t_point p1, t_point p2)
{
	t_point		d;

	if (p1.x > p2.x)
	{
		draw_simple_line_x(m_p, w_p, p2, p1);
		return ;
	}
	d.z = 0;
	p2.z = ft_abs(p2.x - p1.x);
	d.col = p2.y - p1.y;
	p1.z = ft_abs(d.col);
	d.col = (d.col > 0) - (d.col < 0);
	d.x = p1.x;
	d.y = p1.y;
	while (d.x <= p2.x)
	{
		mlx_pixel_put(m_p, w_p, d.x, d.y, (p1.col | p2.col));
		d.z += p1.z;
		if (2 * d.z >= p2.z)
		{
			d.y += d.col;
			d.z -= p2.z;
		}
		d.x++;
	}
}

static void	draw_simple_line_y(void *m_p, void *w_p, t_point p1, t_point p2)
{
	t_point		d;

	if (p1.y > p2.y)
	{
		draw_simple_line_y(m_p, w_p, p2, p1);
		return ;
	}
	d.z = 0;
	p2.z = ft_abs(p2.y - p1.y);
	d.col = p2.x - p1.x;
	p1.z = ft_abs(d.col);
	d.col = (d.col > 0) - (d.col < 0);
	d.x = p1.x;
	d.y = p1.y;
	while (d.y <= p2.y)
	{
		mlx_pixel_put(m_p, w_p, d.x, d.y, (p1.col | p2.col));
		d.z += p1.z;
		if (2 * d.z >= p2.z)
		{
			d.x += d.col;
			d.z -= p2.z;
		}
		d.y++;
	}
}

void		draw_simple_line_by_points(void *mlx_p, void *win_p, t_point p1, t_point p2)
{
	double k;

	k = (p2.x == p1.x) ? 1 : (p2.y - p1.y + 0.0) / (p2.x - p1.x + 0.0);
	if (ft_abs(k) >= 1)
		draw_simple_line_y(mlx_p, win_p, p1, p2);
	else
		draw_simple_line_x(mlx_p, win_p, p1, p2);
}

void		draw_simple_line(void *mlx_p, void *win_p, t_line line)
{
	double k;

	k = ((line.p2->x) == (line.p1->x)) ? 1 : ((line.p2->y) - (line.p1->y) + 0.0) / ((line.p2->x) - (line.p1->x) + 0.0);
	if (ft_abs(k) >= 1)
		draw_simple_line_y(mlx_p, win_p, *(line.p1), *(line.p2));
	else
		draw_simple_line_x(mlx_p, win_p, *(line.p1), *(line.p2));
}