/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:49:48 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/19 11:48:34 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX_HEIGHT_IN_TILES 60.0

static void		adjust_points(t_point ***points, int len, int num, int max_z)
{
	int		shift_x;
	int		shift_y;
	int		shared_y;
	int		i;
	int		j;

	shift_x = (len % 2 != 1);
	shift_y = (num % 2 != 1);
	i = 0;
	while (points[i] != 0)
	{
		shared_y = (i - (num - 1) / 2) * 2 - shift_y;
		j = 0;
		while (points[i][j] != 0)
		{
			points[i][j]->x = (j - (len - 1) / 2) * 2 - shift_x;
			points[i][j]->y = shared_y;
			points[i][j]->z = max_z == 0 ? 0 : (int)round(
					(points[i][j]->z + 0.0) / max_z * MAX_HEIGHT_IN_TILES);
			j++;
		}
		i++;
	}
}

static void		*return_null(t_point **p_line, t_point ***pts, void *ptr)
{
	free_points(pts);
	free_point_line(p_line);
	free(ptr);
	return (NULL);
}

t_point			***read_points(char *file, t_point ***points, t_point ***new_points, int fd)
{
	t_point			**point_line;
	int				line_num;
	int				line_len;
	int				max_z;
	int				i;

	fd = open(file, O_RDONLY);
	points = (t_point***)malloc(sizeof(t_point**) * 2);
	point_line = read_point_line(fd, &max_z, &line_len);
	if (points == 0 || point_line == 0 || line_len <= 0 || (line_num = 1) != 1)
		return (return_null(point_line, points, 0));
	points[0] = point_line;
	points[1] = 0;
	while ((point_line = read_point_line(fd, &max_z, &i)) != 0 && i > 0)
	{
		new_points = (t_point***)malloc(sizeof(t_point**) * (++line_num + 1));
		if (new_points == NULL || i != line_len)
			return (return_null(point_line, points, new_points));
		i = -1;
		while (points[++i] != 0)
			new_points[i] = points[i];
		new_points[i] = point_line;
		new_points[i + 1] = 0;
		free(points);
		points = new_points;
	}
	free_point_line(point_line);
	if (i < 0)
		return (return_null(0, points, 0));
	adjust_points(points, line_len, line_num, max_z);
	return (points);
}
