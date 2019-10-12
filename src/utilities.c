/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:39:53 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/12 05:41:59 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MASK_RED   0x00FF0000
#define MASK_GREEN 0x0000FF00
#define MASK_BLUE  0x000000FF

int		blend(int c1, int c2, unsigned char val)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (c2 & MASK_RED) >> 16;
	r =  t + (((c1 & MASK_RED) >> 16) - t) * (val + 0.0) / MAX_BLEND;

	t = (c2 & MASK_GREEN) >> 8;
	g =  t + (((c1 & MASK_GREEN) >> 8) - t) * (val + 0.0) / MAX_BLEND;

	t = (c2 & MASK_BLUE);
	b =  t + ((c1 & MASK_BLUE) - t) * (val + 0.0) / MAX_BLEND;

	t = ((int)(r << 16)) + ((int)(g << 8)) + b;
	return (t);
}

double	clamp(double val, double min, double max)
{
	if (val < min)
	{
		return (min);
	}
	if (val > max)
	{
		return (max);
	}
	return (val);
}

double	cycle(double val, double min, double max)
{
	while (val > max)
	{
		val = min + (val - max);
	}
	while (val < min)
	{
		val = max - (min - val);
	}
	return (val);
}
