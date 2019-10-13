/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:24:13 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/14 00:44:24 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define CENTER_X 256
#define CENTER_Y 256


//#define CENTER_X 400
//#define CENTER_Y 400

t_point		convert_coords(t_point f, double angle_vertical, double angle_horizontal, int scale)
{
	t_point	v;
	int		x0 = CENTER_X;
	int		y0 = CENTER_Y;
	double	z_size;
	double	radius;

	z_size = (scale + 0.0) * cos(angle_vertical);

	v.x = f.x * scale;
	v.y = f.y * scale;
	radius = v.x * v.x + v.y * v.y;
	radius = (radius <= 0) ? 0 : sqrt(radius);

	v.x = x0 + round(radius * cos(atan2(f.y, f.x) + angle_horizontal));
	v.y = y0 + round(sin(angle_vertical) * radius * sin(atan2(f.y, f.x) + angle_horizontal));

	v.z = round(f.z * z_size);
	v.y = v.y - v.z;
	v.col = f.col;

	//printf("conv  x:(\t%d\t->\t%d\t: %.1f\t)   y:(\t%d\t->\t%d\t: %.2f\t)\n", f.x, v.x, v_x, f.y, v.y, v_y);
	return (v);
}

void		convert_coords_on_place(t_point *f, double angle_vertical, double angle_horizontal, int scale)
{
	t_point	v;
	int		x0 = CENTER_X;
	int		y0 = CENTER_Y;
	double	z_size;
	double	radius;

	z_size = (scale + 0.0) * cos(angle_vertical);

	printf("converting x(%d) ", f->x);

	v.x = f->x * scale;
	v.y = f->y * scale;
	radius = v.x * v.x + v.y * v.y;
	radius = (radius <= 0) ? 0 : sqrt(radius);

	v.x = x0 + round(radius * cos(atan2(f->y, f->x) + angle_horizontal));
	v.y = y0 + round(sin(angle_vertical) * radius * sin(atan2(f->y, f->x) + angle_horizontal));

	v.z = round(f->z * z_size);
	v.y = v.y - v.z;

	f->x = v.x;
	f->y = v.y;
	f->z = v.z;

	printf("to %d, %d \n", f->x, v.x);
}