/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:41:41 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/12 23:49:18 by kcharla          ###   ########.fr       */
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

void	free_points(t_point **points)
{
	int 	i;

	i = 0;
	if (points == 0)
		return ;
	while (points[i] != 0)
	{
		free(points[i]);
	}
	free(points);
}