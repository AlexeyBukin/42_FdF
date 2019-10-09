/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:38:48 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/14 12:10:59 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char c)
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

char		*ft_strtrim(const char *s)
{
	int		i;
	int		j;

	if (s == 0)
		return (0);
	i = 0;
	while (ft_is_whitespace(s[i]))
	{
		i++;
	}
	j = i;
	while (s[j] != '\0')
	{
		j++;
	}
	j--;
	while (ft_is_whitespace(s[j]))
	{
		j--;
	}
	if (j < i)
		return (ft_strnew(0));
	return (ft_strsub(s, i, j - i + 1));
}
