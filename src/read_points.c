/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:49:48 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/18 19:43:01 by kcharla          ###   ########.fr       */
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

static t_point	*str_to_point(char *str)
{
	t_point		*point;
	char		*pointer;
	int			height;
	int			color;

	color = 0x00FFFFFF;
	point = (t_point*)malloc(sizeof(t_point));
	if ((pointer = ft_strchr(str, ',')) != 0)
	{
		*pointer = '\0';
		pointer++;
		color = atouhi(pointer);
	}
	height = ft_atoi(str);
	point->x = 0;
	point->y = 0;
	point->z = height;
	point->col = color;
	return (point);
}

static t_point	**read_point_line(int fd, int *max_z, int *line_len)
{
	t_point		**point_line;
	char		**splitted;
	char		*line;
	int			gnl_res;
	int 		i;

	line = 0;
	gnl_res = get_next_line(fd, &line);
	splitted = ft_strsplit(line, ' ');
	if (gnl_res < 0 || splitted == 0)
	{
		free(line);
		free_lines(splitted);
		return (0);
	}
	*line_len = 0;
	while (splitted[*line_len] != 0)
		(*line_len)++;
	point_line = (t_point**)malloc(sizeof(t_point *) * (*line_len + 1));
	if (point_line == NULL)
	{
		free_lines(splitted);
		free(line);
		*line_len = -1;
		return (NULL);
	}
	i = 0;
	while (i < *line_len)
	{
		point_line[i] = str_to_point(splitted[i]);
		if (point_line[i] == NULL)
		{
			free_lines(splitted);
			free(line);
			*line_len = -1;
			return (NULL);
		}
		if (point_line[i]->z > *max_z)
			*max_z = point_line[i]->z;
		i++;
	}
	point_line[i] = 0;
	free(line);
	free_lines(splitted);
	return (point_line);
}

t_point			***read_points(char *file)
{
	t_point			***points;
	t_point			***new_points;
	t_point			**point_line;
	int				line_num;
	int				line_len;
	int				max_z;
	int				i;
	int				fd;

	fd = open(file, O_RDONLY);
	max_z = 0;
	points = (t_point***)malloc(sizeof(t_point**) * 2);
	point_line = read_point_line(fd, &max_z, &line_len);
	if (points == 0 || point_line == 0 || line_len <= 0)
	{
		free(points);
		free(point_line);
		return (0);
	}
	line_num = 1;
	points[0] = point_line;
	points[1] = 0;
	while ((point_line = read_point_line(fd, &max_z, &i)) != 0 && i > 0)
	{
		new_points = (t_point***)malloc(sizeof(t_point**) * (++line_num + 1));
		if (new_points == 0 || i != line_len)
		{
			free(new_points);
			free(point_line);
			free_points(points);
			return (0);
		}
		i = 0;
		while (points[i] != 0)
		{
			new_points[i] = points[i];
			i++;
		}
		new_points[i] = point_line;
		new_points[i + 1] = 0;
		free(points);
		points = new_points;
	}
	free(point_line);
	if (i < 0)
	{
		free(points);
		return (0);
	}
	adjust_points(points, line_len, line_num, max_z);
	return (points);
}
