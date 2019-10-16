/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:59:35 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/16 19:47:51 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_line_tree.h"

int				insert(t_line key, t_node **root)
{
	t_node		*uproot;
	t_node		*newnode;
	t_line		up_key;
	int			value;

	value = ins(*root, key, &up_key, &newnode);
	if (value == 1)
	{
		uproot = (*root);
		*root = (t_node*)malloc(sizeof(t_node));
		if (*root == NULL)
		{
			clean(uproot);
			return (0);
		}
		(*root)->n = 1;
		(*root)->keys[0] = up_key;
		(*root)->p[0] = uproot;
		(*root)->p[1] = newnode;
	}
	return (value >= 0);
}

int				search_pos(t_line key, t_line *key_arr, int n)
{
	int			pos;

	pos = 0;
	while (pos < n && key.z >= key_arr[pos].z)
		pos++;
	return (pos);
}

int				func1(int n, t_line new_key, t_node *new_ptr, t_node *ptr)
{
	int			i;
	int			pos;

	pos = search_pos(new_key, ptr->keys, n);
	i = n;
	while (i > pos)
	{
		ptr->keys[i] = ptr->keys[i - 1];
		ptr->p[i + 1] = ptr->p[i];
		i--;
	}
	ptr->keys[pos] = new_key;
	ptr->p[pos + 1] = new_ptr;
	++ptr->n;
	return (0);
}

int				func2(t_node *ptr, t_line key, t_node **l_ptr, t_line *last_key)
{
	t_node		*new_ptr;
	t_line		new_key;
	int			pos;
	int			i;

	pos = search_pos(key, ptr->keys, ptr->n);
	if ((i = ins(ptr->p[pos], key, &new_key, &new_ptr)) != 1)
		return (i);
	if (ptr->n < M - 1)
		return (func1(ptr->n, new_key, new_ptr, ptr));
	*last_key = (pos == M - 1) ? new_key : *last_key;
	*l_ptr = (pos == M - 1) ? new_ptr : *l_ptr;
	if (pos != M - 1 && (i = M - 1))
	{
		*last_key = ptr->keys[M - 2];
		*l_ptr = ptr->p[M - 1];
		while (--i > pos)
		{
			ptr->keys[i] = ptr->keys[i - 1];
			ptr->p[i + 1] = ptr->p[i];
		}
		ptr->keys[pos] = new_key;
		ptr->p[pos + 1] = new_ptr;
	}
	return (3);
}

int				ins(t_node *ptr, t_line key, t_line *up_key, t_node **newnode)
{
	t_node		*new_ptr;
	t_node		*last_ptr;
	t_line		last_key;
	int			pos;
	int			i;

	*newnode = (ptr == NULL) ? NULL : *newnode;
	*up_key = (ptr == NULL) ? key : *up_key;
	if (ptr == NULL)
		return (1);
	i = func2(ptr, key, &last_ptr, &last_key);
	if (i != 3)
		return (i);
	pos = (M - 1) / 2;
	(*up_key) = ptr->keys[pos];
	(*newnode) = (t_node*)malloc(sizeof(t_node));
	ptr->n = pos;
	(*newnode)->n = M - 1 - pos;
	i = 0;
	while (i < (*newnode)->n)
	{
		(*newnode)->p[i] = ptr->p[i + pos + 1];
		if (i < (*newnode)->n - 1)
			(*newnode)->keys[i] = ptr->keys[i + pos + 1];
		else
			(*newnode)->keys[i] = last_key;
		i++;
	}
	(*newnode)->p[(*newnode)->n] = last_ptr;
	return (1);
}

void			inorder(t_node *ptr)
{
	static int	g_tabs;
	int			t;
	int			i;

	g_tabs++;
	if (ptr != 0)
		if (ptr->n >= 1)
		{
			i = -1;
			while (++i < ptr->n)
			{
				inorder(ptr->p[i]);
				t = -1;
				while (++t < g_tabs)
					printf("\t");
				printf("%d\n", ptr->keys[i].z);
			}
			if (ptr->n >= i)
				inorder(ptr->p[i]);
		}
	free(ptr);
	g_tabs--;
}

void			clean(t_node *ptr)
{
	int			i;

	if (ptr != 0)
	{
		if (ptr->n >= 1)
		{
			i = 0;
			while (i < ptr->n)
			{
				clean(ptr->p[i]);
				i++;
			}
			if (ptr->n >= i)
			{
				clean(ptr->p[i]);
			}
		}
		free(ptr);
	}
}
