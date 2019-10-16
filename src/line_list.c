/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:29:54 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/14 20:33:08 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	insert_line(t_line **start, t_line *new)
{
	t_line		*temp;

	if (start == 0 || new == 0)
		return ;
	if (*start == 0)
	{
		*start = new;
		return ;
	}
	temp = *start;
	if (new->z <= temp->z)
	{
		new->next = *start;
		(*start)->prev = new;
		*start = new;
		return ;
	}
	temp = *start;
	while((new->z > temp->z) && (temp->next != 0))
	{
		temp = temp->next;
	}
	if (new->z > temp->z)
	{
		temp->next = new;
		new->prev = temp;
		return ;
	}
	new->next = temp;
	new->prev = temp->prev;

	(temp->prev)->next = new;
	temp->prev = new;
}

void	add_line(t_line **start, t_line *new)
{
	if (start == 0 || new == 0)
		return ;
	if (*start == 0)
	{
		*start = new;
		return ;
	}
	(*start)->prev = new;
	new->next = *start;
	*start = new;
}

void	free_line_list(t_line *list)
{
	t_line	*del_me;

	if (list == 0)
		return ;
	while (list->next != 0)
	{
		del_me = list;
		list = list->next;
		free(del_me);
	}
}