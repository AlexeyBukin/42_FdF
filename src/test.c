/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/20 13:42:30 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				is_line_on_screen(t_line line)
{
	if (line.p1->x > BOUND_X || line.p1->x < 0 ||
			line.p1->y > BOUND_Y || line.p1->y < 0)
	{
		if (line.p2->x > BOUND_X || line.p2->x < 0 ||
				line.p2->y > BOUND_Y || line.p2->y < 0)
		{
			return (0);
		}
	}
	return (1);
}

void			clean_and_ret(t_point ***points, t_node *btree_root)
{
	free_points(points);
	free_btree(btree_root);
	return ;
}

static void		add_lines(t_point ***new_pts, t_node **root, t_point lln, int i)
{
	t_line			l;
	int				j;

	while (++i < lln.x && (j = -1) == -1)
		while (++j < lln.y)
		{
			l.p1 = new_pts[i][j];
			if (j < lln.y - 1)
			{
				l.p2 = new_pts[i][j + 1];
				l.z = (l.p1->z > l.p2->z) ? l.p1->z : l.p2->z;
				if (is_line_on_screen(l))
					if (insert_line_in_btree(l, root) < 0)
						return (clean_and_ret(new_pts, *root));
			}
			if (i < lln.x - 1)
			{
				l.p2 = new_pts[i + 1][j];
				l.z = (l.p1->z > l.p2->z) ? l.p1->z : l.p2->z;
				if (is_line_on_screen(l))
					if (insert_line_in_btree(l, root) < 0)
						return (clean_and_ret(new_pts, *root));
			}
		}
}

void			draw_parallel(t_data *d)
{
	t_point			line_len_and_num;
	t_point			***new_points;
	t_node			*btree_root;
	int				l_n;
	int				l_l;

	new_points = points_dup(d->points, 0, 0, -1);
	if (new_points == NULL || (l_n = -1) != -1)
		return ;
	while (new_points[++l_n] != 0 && (l_l = -1) == -1)
		while (new_points[l_n][++l_l] != 0)
			convert_coords(new_points[l_n][l_l], d->va, d->ha, d->scale);
	btree_root = NULL;
	line_len_and_num.x = l_n;
	line_len_and_num.y = l_l;
	add_lines(new_points, &btree_root, line_len_and_num, -1);
	draw_btree_in_order(d->mlx, d->win_ptr, &btree_root);
	free_points(new_points);
}
