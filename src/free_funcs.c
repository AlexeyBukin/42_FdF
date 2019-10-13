/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:41:41 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/13 05:14:51 by kcharla          ###   ########.fr       */
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

void	free_points(t_point **points, int line_num)
{
	int 	i;

	line_num++;
	if (points == 0)
		return ;
	i = 0;
	while (points[i] != 0)
	{
		printf("points[i]: %d\n", (int) points[i]);
		write(1, "1+", 2);
		free(points[i]);
		i++;
	}
	printf("\n");
	free(points);
}