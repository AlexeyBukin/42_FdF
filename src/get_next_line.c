/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:25:50 by kcharla           #+#    #+#             */
/*   Updated: 2019/09/21 20:50:29 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		get_last_buf(char **line, char **last_buf)
{
	char		*buf;

	buf = *last_buf;
	if (buf != 0)
	{
		buf = ft_strchr(*last_buf, (int)'\n');
		if (buf != 0)
		{
			buf[0] = '\0';
			*line = ft_strdup(*last_buf);
			if (*line == 0)
				return (-1);
			*last_buf = &buf[1];
			return (1);
		}
		else
		{
			if ((*line = ft_strdup(*last_buf)) == 0)
				return (-1);
			return (0);
		}
	}
	else if ((*line = ft_strdup("")) == 0)
		return (-1);
	return (0);
}

static int		one_if(char **line, char **last_buf, char *buf)
{
	char	*old_line;
	char	*pointer;

	old_line = *line;
	pointer = ft_strchr(buf, (int)'\n');
	if (pointer != 0)
	{
		pointer[0] = '\0';
		*line = ft_strjoin(old_line, buf);
		free(old_line);
		if (*line == 0)
			return (-1);
		ft_strcpy(*last_buf, &pointer[1]);
		return (1);
	}
	*line = ft_strjoin(old_line, buf);
	*last_buf[0] = '\0';
	free(old_line);
	if (*line == 0)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				one_if_res;
	int				val;
	static char		last_bufs[255][BUFF_SIZE + 1];
	char			*pointer;
	char			buf[BUFF_SIZE + 1];

	pointer = last_bufs[fd];
	if (fd < 0 || fd > 65535 || line == 0 || (read(fd, last_bufs[fd], 0) < 0))
		return (-1);
	if ((val = get_last_buf(line, &pointer)) != 0)
		return (val + (ft_strcpy(last_bufs[fd], pointer) == 0));
	while ((val = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[val] = '\0';
		one_if_res = one_if(line, &pointer, buf);
		if (one_if_res != 0)
			return (one_if_res);
		else if (val < BUFF_SIZE)
			return (1);
	}
	last_bufs[fd][0] = '\0';
	if (*line == 0 || val < 0)
		return (-1);
	return ((ft_strcmp(*line, "") == 0) ? 0 : 1);
}
