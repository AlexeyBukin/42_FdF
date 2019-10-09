/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:28:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/16 14:38:36 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	i = 0;
	res = ft_strdup(s);
	if (res == 0)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}
