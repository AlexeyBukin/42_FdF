/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:24:13 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/29 16:24:34 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that converts coordinates
** of one point from 'basic' to the ones with
** vertical and horizontal angles
*/

void	convert_coords(t_point *f, t_data *d, double h)
{
	t_point		v;
	int			x0;
	int			y0;
	double		radius;

	x0 = BOUND_X / 2;
	y0 = BOUND_Y / 2;
	h = (d->scale + 0.0) * cos(d->va) * h;
	v.x = f->x * d->scale;
	v.y = f->y * d->scale;
	radius = v.x * v.x + v.y * v.y;
	radius = (radius <= 0) ? 0 : sqrt(radius);
	v.x = x0 + round(radius * cos(atan2(f->y, f->x) + d->ha));
	v.y = round(sin(d->va) * radius *
				sin(atan2(f->y, f->x) + d->ha));
	v.z = v.y;
	v.y = y0 + v.y - round(f->z * h);
	f->x = v.x;
	f->y = v.y;
	f->z = v.z;
}
