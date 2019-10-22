/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_of_lines_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:54:58 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/21 20:26:31 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that draws lines and cleanf btree at the same time
** (Should be called once with one btree)
*/

void			draw_btree_in_order(t_data *data, t_node **ptr)
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
					draw_btree_in_order(data, &((*ptr)->p[i]));
					draw_simple_line(data, (*ptr)->keys[i]);
					i++;
				}
				if ((*ptr)->n >= i)
					draw_btree_in_order(data, &((*ptr)->p[i]));
			}
			free(*ptr);
			*ptr = 0;
		}
	}
}

/*
** Function that 'frees' btree
*/

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
