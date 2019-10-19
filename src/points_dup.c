/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/19 17:58:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		*return_null(t_point ***p_dup)
{
	free_points(p_dup);
	return (NULL);
}

t_point			***points_dup(t_point ***pts, int l_n, int line_len, int i)
{
	t_point	***p_dup;
	int		j;

	if (pts == NULL)
		return (NULL);
	while (pts[l_n] != 0)
		l_n++;
	if ((p_dup = (t_point***)malloc(sizeof(t_point**) * ++l_n)) == 0)
		return (return_null(p_dup));
	p_dup[l_n - 1] = 0;
	while (pts[0][line_len] != 0)
		line_len++;
	l_n = sizeof(t_point*) * (line_len + 1);
	while (pts[++i] != 0 && (j = -1) == -1)
	{
		if ((p_dup[i] = (t_point **)malloc(l_n)) == 0)
			return (return_null(p_dup));
		while (pts[i][++j] != 0)
			if ((p_dup[i][j] = (t_point *)malloc(sizeof(t_point))) == 0)
				return (return_null(p_dup));
			else
				*(p_dup[i][j]) = *(pts[i][j]);
		p_dup[i][j] = 0;
	}
	return (p_dup);
}
