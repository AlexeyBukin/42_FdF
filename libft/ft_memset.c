/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:57:58 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/15 21:28:49 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	uint8_t	*char_buf;
	size_t	i;

	i = 0;
	char_buf = (uint8_t *)buf;
	while (i < count)
	{
		char_buf[i] = (uint8_t)ch;
		i++;
	}
	return (buf);
}
