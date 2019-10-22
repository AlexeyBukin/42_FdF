/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:24:13 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/22 16:51:07 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that converts coordinates
** of one point from 'basic' to the ones with
** vertical and horizontal angles
*/

void	convert_coords(t_point *f, double v_a, double h_a, int scale, double h)
{
	t_point		v;
	int			x0;
	int			y0;
	double		radius;

	x0 = BOUND_X / 2;
	y0 = BOUND_Y / 2;
	h = (scale + 0.0) * cos(v_a) * h;
	v.x = f->x * scale;
	v.y = f->y * scale;
	radius = v.x * v.x + v.y * v.y;
	radius = (radius <= 0) ? 0 : sqrt(radius);
	v.x = x0 + round(radius * cos(atan2(f->y, f->x) + h_a));
	v.y = round(sin(v_a) * radius *
			sin(atan2(f->y, f->x) + h_a));
	v.z = v.y;
	v.y = y0 + v.y - round(f->z * h);
	f->x = v.x;
	f->y = v.y;
	f->z = v.z;
}
