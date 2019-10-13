/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printables.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:31:00 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/13 21:20:19 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point(t_point p)
{
	printf("point: (x: %d, y: %d, z: %d), color: %d\n", p.x, p.y, p.z, p.col);
}

void	print_point_line(t_point *line, int line_len)
{
	int i;

	i = 0;
	while (i < line_len)
	{
		printf("(%3d : %3d : %3d) - ", line[i].x, line[i].y, line[i].z);
		i++;
	}
	printf("\n");
}

void	print_points(t_point **points, int line_len)
{
	int i;

	i = 0;
	while (points[i] != 0)
	{
		print_point_line(points[i], line_len);
		i++;
	}
}

void	print_colors(t_point **points, int line_len)
{
	int 	j;
	int		i;

	i = 0;
	while (points[i] != 0)
	{
		j = 0;
		printf("0x%08x", points[i][j].col);
		j++;
		while (j < line_len)
		{
			printf(" - 0x%08x", points[i][j].col);
			j++;
		}
		printf("\n");
		i++;
	}
}