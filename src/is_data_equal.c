/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_data_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:24:11 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/20 22:24:11 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function that compares two t_data structs
*/

int		is_data_equal(const t_data *d1, const t_data *d2)
{
	int		res;

	if (d1 == 0 || d2 == 0)
	{
		if (d1 == 0 && d2 == 0)
			return (1);
		return (0);
	}
	res = (d1->va == d2->va);
	res = res && (d1->ha == d2->ha);
	res = res && (d1->scale == d2->scale);
	res = res && (d1->h == d2->h);
	return (res);
}
