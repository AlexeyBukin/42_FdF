/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/11 19:58:59 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ESC_KEY 53

int		key_pressed(int key, void *param)
{
	param = 0;
//	if (param == 0)
//		printf("param is empty!\n");
//	printf("key pressed: %d (\'%c\')\n", key, (char) key);


	if (key == ESC_KEY)
	{
		printf("esc pressed!\n");
		exit (0);
	}
	return (0);
}

int		main()
{
	void * mlx_ptr = mlx_init();
	void * win_ptr = mlx_new_window(mlx_ptr, 512, 512, "FdF");
	//void * win2_ptr = mlx_new_window(mlx_ptr, 512, 512, "FdF - 2");
	//win2_ptr = 0;


	mlx_key_hook(win_ptr, key_pressed, (void *) 0);

	draw_stuff(mlx_ptr, win_ptr);

	mlx_clear_window(mlx_ptr, win_ptr);
	//mlx_destroy_window(mlx_ptr, win_ptr);

	mlx_loop(mlx_ptr);
	return (0);
}