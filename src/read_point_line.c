/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:49:48 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/19 11:31:06 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void		*return_null(char *line, char **splitted, int *l_l, int l_l_v)
{
	free_lines(splitted);
	free(line);
	if (l_l != 0)
		*l_l = l_l_v;
	return (NULL);
}

t_point			**read_point_line(int fd, int *max_z, int *line_len)
{
	t_point		**p_line;
	char		**splitted;
	char		*line;
	int			gnl_res;
	int			i;

	*max_z = 0;
	gnl_res = get_next_line(fd, &line);
	splitted = ft_strsplit(line, ' ');
	if (gnl_res < 0 || splitted == 0 || (*line_len = 0))
		return (return_null(line, splitted, line_len, -1));
	while (splitted[*line_len] != 0)
		(*line_len)++;
	if ((p_line = (t_point**)malloc(sizeof(t_point *) * (*line_len + 1))) == 0)
		return (return_null(line, splitted, line_len, -1));
	i = -1;
	while (++i < *line_len)
		if ((p_line[i] = str_to_point(splitted[i])) == NULL)
			return (return_null(line, splitted, line_len, -1));
		else if (p_line[i]->z > *max_z)
			*max_z = p_line[i]->z;
	p_line[i] = 0;
	free(line);
	free_lines(splitted);
	return (p_line);
}
