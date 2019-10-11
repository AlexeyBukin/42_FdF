/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:06:51 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/11 14:02:30 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == 0)
		return (0);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == 0)
	{
		return (0);
	}
	res = (char*)ft_memcpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}
