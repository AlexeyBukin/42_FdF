/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_of_lines_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:54:58 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/17 18:06:44 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print_btree_in_order(t_node *ptr)
{
	static int	g_tabs;
	int			t;
	int			i;

	g_tabs++;
	if (ptr != 0)
		if (ptr->n >= 1)
		{
			i = -1;
			while (++i < ptr->n)
			{
				print_btree_in_order(ptr->p[i]);
				t = -1;
				while (++t < g_tabs)
					printf("\t");
				printf("%d\n", ptr->keys[i].z);
			}
			if (ptr->n >= i)
				print_btree_in_order(ptr->p[i]);
		}
	g_tabs--;
}

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

void			clean(t_node *ptr)
{
	int			i;

	if (ptr != 0)
	{
		if (ptr->n >= 1)
		{
			i = 0;
			while (i < ptr->n)
			{
				clean(ptr->p[i]);
				i++;
			}
			if (ptr->n >= i)
			{
				clean(ptr->p[i]);
			}
		}
		free(ptr);
	}
}
