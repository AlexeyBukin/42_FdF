/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:12:10 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/11 14:02:30 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	uint8_t		*tp;

	tp = (uint8_t*)malloc(size);
	if (tp != 0)
	{
		tp = (uint8_t*)ft_bzero(tp, size);
	}
	return (tp);
}
