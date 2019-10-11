/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:24:35 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/12 00:39:03 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void re_draw(void *mlx_ptr, void *win_ptr, double va, double ha, int scale)
{
	void *img = mlx_new_image(mlx_ptr, 512, 512);
	int mpitw = mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mpitw--;
	draw_stuff(mlx_ptr, win_ptr, va, ha, scale);
}