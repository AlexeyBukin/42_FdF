/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:41:04 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/11 14:02:30 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		return (1);
	}
	else if (c == '\r' || c == '\v' || c == '\f')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		negative;

	negative = 1;
	res = 0;
	i = 0;
	while (ft_is_blank(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * negative);
}
