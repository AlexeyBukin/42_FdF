/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:49:48 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/21 18:47:29 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX_HEIGHT_IN_TILES 10.0

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
			points[i][j]->z = (max_z == 0) ? 0 : (int)round(
					(points[i][j]->z + 0.0) / max_z * MAX_HEIGHT_IN_TILES);
			j++;
		}
		i++;
	}
}

static void		*return_null(t_point **p_line, t_point ***pts)
{
	(void)pts;
	(void)p_line;
	return (NULL);
}

static int		inside_loop(t_point ****points, int *line_num, t_point **p_line)
{
	t_point		***new_points;
	int			i;

	if (points == NULL)
		return (-1);
	new_points = (t_point***)malloc(sizeof(t_point**) * (++(*line_num) + 1));
	if (new_points == NULL || *points == NULL)
		return (-1);
	i = -1;
	while ((*points)[++i] != 0)
		new_points[i] = (*points)[i];
	new_points[i] = p_line;
	new_points[i + 1] = 0;
	free(*points);
	*points = new_points;
	return (1);
}

t_point			***read_points(char *file, t_point ***points, int fd, int max_z)
{
	t_point			**point_line;
	int				line_num;
	int				line_len;
	int				i;

	fd = open(file, O_RDONLY);
	points = (t_point***)malloc(sizeof(t_point**) * 2);
	point_line = read_point_line(fd, &max_z, &line_len, NULL);
	if (points == 0 || point_line == 0 || line_len <= 0 || (line_num = 1) != 1)
		return (return_null(point_line, points));
	points[0] = point_line;
	points[1] = 0;
	while ((point_line = read_point_line(fd, &max_z, &i, NULL)) != 0 && i > 0)
	{
		if (i != line_len)
			return (return_null(point_line, points));
		if (inside_loop(&points, &line_num, point_line) < 0)
			return (return_null(point_line, points));
	}
	free_point_line(point_line);
	if (i < 0)
		return (return_null(0, points));
	adjust_points(points, line_len, line_num, max_z);
	return (points);
}
