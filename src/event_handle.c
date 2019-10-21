/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:02:22 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/20 22:21:17 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that handles arrow buttons
*/

int		arrows_pressed(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key >= LEFT_KEY && key <= UP_KEY)
	{
		if (key >= LEFT_KEY && key <= RIGHT_KEY)
		{
			if (key == LEFT_KEY)
				d->ha = cycle(d->ha - HA_DELTA, HA_MIN, HA_MAX);
			else
				d->ha = cycle(d->ha + HA_DELTA, HA_MIN, HA_MAX);
		}
		if (key >= DOWN_KEY && key <= UP_KEY)
		{
			if (key == UP_KEY)
				d->va = clamp(d->va + VA_DELTA, VA_MIN, VA_MAX);
			else
				d->va = clamp(d->va - VA_DELTA, VA_MIN, VA_MAX);
		}
		if (is_data_equal(d, ref))
			return (0);
		mlx_clear_window(d->mlx, d->win_ptr);
		draw_parallel(d);
		return (0);
	}
	return (-1);
}

/*
** Function that handles shift and ctrl buttons
*/

int		mouse_scrolled(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == SCROLL_UP || key == SCROLL_DOWN)
	{
		if (key == SCROLL_UP)
			d->scale = (int)clamp(d->scale + SCALE_DELTA, SCALE_MIN, SCALE_MAX);
		else
			d->scale = (int)clamp(d->scale - SCALE_DELTA, SCALE_MIN, SCALE_MAX);
		if (is_data_equal(d, ref))
			return (-1);
		mlx_clear_window(d->mlx, d->win_ptr);
		draw_parallel(d);
		return (0);
	}
	return (-1);
}
