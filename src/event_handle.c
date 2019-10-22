/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:02:22 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/22 17:22:56 by kcharla          ###   ########.fr       */
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
	if (key == RIGHT_KEY)
		d->ha = cycle(d->ha + HA_DELTA, HA_MIN, HA_MAX);
	else if (key == LEFT_KEY)
		d->ha = cycle(d->ha - HA_DELTA, HA_MIN, HA_MAX);
	else if (key == UP_KEY)
		d->va = clamp(d->va + VA_DELTA, VA_MIN, VA_MAX);
	else if (key == DOWN_KEY)
		d->va = clamp(d->va - VA_DELTA, VA_MIN, VA_MAX);
	else
		return (-1);
	if (is_data_equal(d, ref))
		return (0);
	draw_parallel(d);
	return (0);
}

/*
** Function that handles WASD buttons
*/

int		wasd_pressed(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == D_KEY)
		d->ha = cycle(d->ha + HA_DELTA, HA_MIN, HA_MAX);
	else if (key == A_KEY)
		d->ha = cycle(d->ha - HA_DELTA, HA_MIN, HA_MAX);
	else if (key == W_KEY)
		d->va = clamp(d->va + VA_DELTA, VA_MIN, VA_MAX);
	else if (key == S_KEY)
		d->va = clamp(d->va - VA_DELTA, VA_MIN, VA_MAX);
	else
		return (-1);
	if (is_data_equal(d, ref))
		return (0);
	draw_parallel(d);
	return (0);
}

/*
** Function that handles mouse scroll
*/

int		mouse_scrolled(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == SCROLL_UP)
		d->scale = (int)clamp(d->scale + SCALE_DELTA, SCALE_MIN, SCALE_MAX);
	else if (key == SCROLL_DOWN)
		d->scale = (int)clamp(d->scale - SCALE_DELTA, SCALE_MIN, SCALE_MAX);
	else
		return (-1);
	if (is_data_equal(d, ref))
		return (-1);
	draw_parallel(d);
	return (0);
}

/*
** Function that handles shift and ctrl buttons
*/

int		shift_or_ctrl_pressed(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == E_KEY)
		d->h = clamp(d->h + HEIGHT_DELTA, HEIGHT_MIN, HEIGHT_MAX);
	else if (key == Q_KEY)
		d->h = clamp(d->h - HEIGHT_DELTA, HEIGHT_MIN, HEIGHT_MAX);
	else
		return (-1);
	if (is_data_equal(d, ref))
		return (0);
	draw_parallel(d);
	return (0);
}

/*
** Function that handles shift and ctrl buttons
*/

int		num_keys_pressed(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == NUM_1_KEY || key == NUM_3_KEY)
		d->ha = 0;
	if (key == NUM_1_KEY || key == NUM_2_KEY)
		d->va = 0;
	if (key == NUM_2_KEY)
		d->ha = M_PI / 2;
	else if (key == NUM_3_KEY)
		d->va = VA_MAX;
	else if (key == NUM_4_KEY)
	{
		d->ha = M_PI / 4;
		d->va = M_PI / 4;
	}
	else if (key == NUM_5_KEY)
		d->ha = cycle(d->ha + ((HA_MAX - HA_MIN) / 2), HA_MIN, HA_MAX);
	if (is_data_equal(d, ref))
		return (-1);
	draw_parallel(d);
	return (0);
}