/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:49:48 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/14 17:32:57 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX_HEIGHT_IN_TILES 60.0

static void		adjust_points(t_point ***points, int line_len, int line_num, int max_z)
{
	int 	shift_x;
	int 	shift_y;
	int 	shared_y;
	int		i;
	int 	j;

	shift_x = (line_len % 2 != 1) ;// (line_len % 2 == 1) ? 0 : 1;
	shift_y = (line_num % 2 != 1) ;// (line_num % 2 == 1) ? 0 : 1;

	printf("shift_x: %d, shift_y: %d\n", shift_x, shift_y);

	i = 0;
	while (points[i] != 0)
	{
		shared_y = (i - (line_num - 1) / 2) * 2 - shift_y;
		j = 0;
		while (points[i][j] != 0)
		{
			points[i][j]->x = (j - (line_len - 1) / 2) * 2 - shift_x;
			points[i][j]->y = shared_y;
			points[i][j]->z = max_z == 0 ? 0 : (int) round((points[i][j]->z + 0.0) / max_z * MAX_HEIGHT_IN_TILES);
			j++;
		}
		i++;
	}

	//max_z++;
}

static t_point	*str_to_point(char *str)
{
	t_point		*point;
	char		*pointer;
	int 		height;
	int 		color;

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
	//printf("col: 0x%08x\n", color);
	return (point);
}

static t_point	**read_point_line(int fd, int *max_z, int *line_len)
{
	t_point		**point_line;
	char		**splitted;
	char		*line;
	int 		i;
	//int			line_len;

	int gnl_res;

	line = 0;
	gnl_res = get_next_line(fd, &line);

	//write(1, "enter rpl\n", 10);

	splitted = ft_strsplit(line, ' ');

	if(gnl_res < 0 || splitted == 0)
	{
		printf("read error (4); splitted: %d\n", (int) splitted);
		free(line);
		free_lines(splitted);
		return (0);
	}

	*line_len = 0;
	while (splitted[*line_len] != 0)
		(*line_len)++;
	point_line = (t_point**)malloc(sizeof(t_point *) * (*line_len + 1));

	i = 0;
	while (i < *line_len)
	{
		point_line[i] = str_to_point(splitted[i]);
		if (point_line[i] == 0)
		{
			free_lines(splitted);
			free(line);
			*line_len = -1;
			///TODO return -1
		}
		if (point_line[i]->z > *max_z)
			*max_z = point_line[i]->z;
		i++;
	}
	point_line[i] = 0;

	free(line);
	free_lines(splitted);

	//write(1, "exit rpl\n", 9);
	return (point_line);
}

t_point			***read_points(char *file)
{
	t_point			***points;
	t_point			***new_points;
	t_point			**point_line;

	//t_point			data;

	int				line_num;
	int 			line_len;
	int 			max_z;
	int 			i;

	//printf("like that?\n");
	int fd = open(file, O_RDONLY);
	max_z = 0;
	points = (t_point***)malloc(sizeof(t_point**) * 2);
	point_line = read_point_line(fd, &max_z, &line_len);

	if (points == 0 || point_line == 0 || line_len == 0)
	{
		printf("read error (1); points: %d, pl: %d, ll: %d\n", (int) points, (int) point_line, line_len);

		free(points);
		free(point_line);
		return (0);
	}

	line_num = 1;

	points[0] = point_line;
	points[1] = 0;

	while((point_line = read_point_line(fd, &max_z, &i)) != 0 && i > 0)
	{
		//write(1, "loop\n", 5);
		new_points = (t_point***)malloc(sizeof(t_point**) * (++line_num + 1));

		if (new_points == 0 || i != line_len)
		{
			//write(1, "(1)\n", 4);
			printf("read error (2); np: %d, line_len: %d, i: %d\n", (int) new_points, line_len, i);

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
	//write(1, "after loop\n", 11);

	free(point_line);

	if (i < 0)
	{
		free(points);
		printf("error reading file (1)\n");
		return (0);
		///free, return;
	}

	//printf("\n read_points before adjust, max_z: %d\n", max_z);
	//print_points(new_points);

	adjust_points(points, line_len, line_num, max_z);

	//printf("\n read_points after adjust \n");
	//print_points(new_points);
	//printf("\n");

	//*ret_len = line_len;
	//printf("error (3); wtf\n");
	return (points);
}
