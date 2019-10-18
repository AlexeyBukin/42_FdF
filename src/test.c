/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/18 20:33:29 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		***points_dup(t_point ***points)
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

t_point		***new_points_as(t_point ***points)
{
	t_point	***p_dup;
	int		line_num;
	int 	line_len;
	int		i;

	if (points == 0)
		return (0);

	line_num = 0;
	while (points[line_num] != 0)
		line_num++;

	p_dup = (t_point ***)malloc(sizeof(t_point **) * (line_num + 1));
	if (p_dup == 0 || line_num < 1)
		return (0);
	p_dup[line_num] = 0;

	line_len = 0;
	while (points[0][line_len] != 0)
		line_len++;

	i = 0;
	while (points[i] != 0)
	{
		p_dup[i] = (t_point **)malloc(sizeof(t_point *) * (line_len + 1));
		if (p_dup[i] == 0)
		{
			free_points(p_dup);
			return (0);
		}
		p_dup[i][line_len] = 0;
		i++;
	}
	return (p_dup);
}

int		is_line_on_screen(t_line line)
{
	int boundX = 1024;
	int boundY = 1024;

	if (line.p1->x > boundX || line.p1->x < 0 || line.p1->y > boundY || line.p1->y < 0)
	{
		if (line.p2->x > boundX || line.p2->x < 0 || line.p2->y > boundY || line.p2->y < 0)
		{
			return (0);
		}
	}
	return (1);
}

int		is_on_screen(t_point *a, t_point *b)
{
	int boundX = 1024;
	int boundY = 1024;

	if (a->x > boundX || a->x < 0 || a->y > boundY || a->y < 0)
	{
		if (b->x > boundX || b->x < 0 || b->y > boundY || b->y < 0)
		{
			return (0);
		}
	}
	return (1);
}

void			clean_points_tree_ret_err(t_point ***points, t_node *btree_root)
{
	free_points(points);
	free_btree(btree_root);
	return ;
}

void		draw_parallel(void *mlx_ptr, void *win_ptr, t_point ***points, double va, double ha, int scale)
{
	t_point		***new_points;
	int			line_num;
	int			line_len;
	int			i;
	int 		j;

	new_points = points_dup(points);
	if (new_points == NULL)
		return ;
	i = 0;
	while (points[i] != 0)
	{
		j = 0;
		while (points[i][j] != 0)
		{
			convert_coords_on_place(new_points[i][j], va, ha, scale);
			j++;
		}
		i++;
	}
	line_len = j;
	line_num = i;

	int minimal_distance = 0;
	int maximal_distance = 0;
	int zero_num = 0;

	t_node			*btree_root = NULL;
	t_line			tmp_for_btree;

	i = 0;
	while (i < line_num)
	{
		j = 0;
		while (j < line_len)
		{
			tmp_for_btree.p1 = new_points[i][j];
			if (j < line_len - 1)
			{
				tmp_for_btree.p2 = new_points[i][j + 1];
				tmp_for_btree.z = (tmp_for_btree.p1->z > tmp_for_btree.p2->z) ?
						tmp_for_btree.p1->z : tmp_for_btree.p2->z;
				if (is_line_on_screen(tmp_for_btree))
					if (insert_line_in_btree(tmp_for_btree, &btree_root) < 0)
						return (clean_points_tree_ret_err(new_points, btree_root));
			}
			if (i < line_num - 1)
			{
				tmp_for_btree.p2 = new_points[i + 1][j];
				tmp_for_btree.z = (tmp_for_btree.p1->z > tmp_for_btree.p2->z) ?
								  tmp_for_btree.p1->z : tmp_for_btree.p2->z;
				if (is_line_on_screen(tmp_for_btree))
					if (insert_line_in_btree(tmp_for_btree, &btree_root) < 0)
						return (clean_points_tree_ret_err(new_points, btree_root));
			}
			j++;
		}
		i++;
	}
	draw_btree_in_order(mlx_ptr, win_ptr, &btree_root);
	free_points(new_points);
}
