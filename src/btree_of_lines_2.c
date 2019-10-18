/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_of_lines_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:54:58 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/17 19:00:06 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_btree_in_order(void *mlx_ptr, void *win_ptr, t_node **ptr)
{
	int			i;

	if (ptr != NULL)
	{
		if ((*ptr) != NULL)
		{
			if ((*ptr)->n >= 1)
			{
				i = 0;
				while (i < (*ptr)->n)
				{
					draw_btree_in_order(mlx_ptr, win_ptr, &((*ptr)->p[i]));
					draw_simple_line(mlx_ptr, win_ptr, (*ptr)->keys[i]);
					i++;
				}
				if ((*ptr)->n >= i)
					draw_btree_in_order(mlx_ptr, win_ptr, &((*ptr)->p[i]));
			}
			free(*ptr);
			*ptr = 0;
		}
	}
}

void			free_btree(t_node *ptr)
{
	int			i;

	if (ptr != 0)
	{
		if (ptr->n >= 1)
		{
			i = 0;
			while (i < ptr->n)
			{
				free_btree(ptr->p[i]);
				i++;
			}
			if (ptr->n >= i)
			{
				free_btree(ptr->p[i]);
			}
		}
		free(ptr);
	}
}
