/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/18 22:06:00 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	***points_dup(t_point ***points)
{
	t_point	***p_dup;
	int		line_num;
	int		line_len;
	int		i;
	int 	j;

	if (points == 0)
		return (0);
	line_num = 0;
	while (points[line_num] != 0)
		line_num++;
	p_dup = (t_point ***)malloc(sizeof(t_point **) * (line_num + 1));
	if (line_num < 1 || p_dup == 0)
		return (0);
	p_dup[line_num] = 0;
	line_len = 0;
	while (points[0][line_len] != 0)
		line_len++;
	i = 0;
	while (points[i] != 0)
	{
		p_dup[i] = (t_point **)malloc(sizeof(t_point*) * (line_len + 1));
		if (p_dup[i] == 0)
		{
			free_points(p_dup);
			return (0);
		}
		j = 0;
		while (points[i][j] != 0)
		{
			p_dup[i][j] = (t_point *)malloc(sizeof(t_point));
			if (p_dup[i][j] == 0)
			{
				free_points(p_dup);
				return (0);
			}
			*(p_dup[i][j]) = *(points[i][j]);
			j++;
		}
		p_dup[i][j] = 0;
		i++;
	}
	return (p_dup);
}

int		is_line_on_screen(t_line line)
{
	if (line.p1->x > BOUND_X || line.p1->x < 0 || line.p1->y > BOUND_Y || line.p1->y < 0)
	{
		if (line.p2->x > BOUND_X || line.p2->x < 0 || line.p2->y > BOUND_Y || line.p2->y < 0)
		{
			return (0);
		}
	}
	return (1);
}

void	clean_points_tree_ret_err(t_point ***points, t_node *btree_root)
{
	free_points(points);
	free_btree(btree_root);
	return ;
}

void	draw_parallel(void *mlx_ptr, void *win_ptr, t_point ***points, double va, double ha, int scale)
{
	t_point			***new_points;
	t_node			*btree_root;
	t_line			l;
	int				line_num;
	int				line_len;
	int				i;
	int 			j;

	new_points = points_dup(points);
	if (new_points == NULL && (btree_root = NULL) == NULL)
		return ;
	i = -1;
	while (points[++i] != 0 && (j = -1) == -1)
		while (points[i][++j] != 0)
			convert_coords(new_points[i][j], va, ha, scale);
	line_len = j;
	line_num = i;
	btree_root = NULL;
	i = -1;
	while (++i < line_num && (j = -1) == -1)
		while (++j < line_len)
		{
			l.p1 = new_points[i][j];
			if (j < line_len - 1)
			{
				l.p2 = new_points[i][j + 1];
				l.z = (l.p1->z > l.p2->z) ? l.p1->z : l.p2->z;
				if (is_line_on_screen(l))
					if (insert_line_in_btree(l, &btree_root) < 0)
						return (clean_points_tree_ret_err(new_points, btree_root));
			}
			if (i < line_num - 1)
			{
				l.p2 = new_points[i + 1][j];
				l.z = (l.p1->z > l.p2->z) ? l.p1->z : l.p2->z;
				if (is_line_on_screen(l))
					if (insert_line_in_btree(l, &btree_root) < 0)
						return (clean_points_tree_ret_err(new_points, btree_root));
			}
		}
	draw_btree_in_order(mlx_ptr, win_ptr, &btree_root);
	free_points(new_points);
}
