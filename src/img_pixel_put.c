/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 00:34:24 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/22 15:15:59 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that puts pixel to image
*/

int		img_pixel_put(t_data *data, int x, int y, int col)
{
	char	*pixel;

	if (data == NULL || x >= BOUND_X || y >= BOUND_Y)
		return (-1);
	if (data->img_adr == NULL || x < 0 || y < 0)
		return (-1);
	pixel = &(data->img_adr[BOUND_X * 4 * y + 4 * x]);
	pixel[0] = col;
	pixel[1] = (char)(col >> 8);
	pixel[2] = (char)(col >> 16);
	pixel[3] = 0;
	return (0);
}

/*
** Function that clears the image
*/

int		img_clear(t_data *data)
{
	int		i;

	if (data == NULL)
		return (-1);
	if (data->img_adr == NULL)
		return (-1);
	i = 0;
	while (i < (BOUND_Y) * (BOUND_X) * 4)
	{
		data->img_adr[i] = 0;
		i++;
	}
	return (0);
}
