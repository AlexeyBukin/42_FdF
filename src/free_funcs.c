/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:41:41 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/13 21:50:57 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_lines(char **lines)
{
	int 	i;

	i = 0;
	if (lines == 0)
		return ;
	while (lines[i] != 0)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_point_line(t_point **point_line)
{
	int		i;

	if (point_line == 0)
		return ;
	i = 0;
	while(point_line[i] != 0)
	{
		free(point_line[i]);
		i++;
	}
}

void	free_points(t_point ***points)
{
	int 	i;

	if (points == 0)
		return ;
	i = 0;
	while (points[i] != 0)
	{
		//printf("points[i]: %d\n", (int) points[i]);
		//write(1, "1+", 2);
		free_point_line(points[i]);
		i++;
	}
	printf("\n");
	free(points);
}
