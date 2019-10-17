/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_of_lines_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:54:58 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/17 16:54:58 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_line_tree.h"

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
	free(ptr);
	g_tabs--;
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
