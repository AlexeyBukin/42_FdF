/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:59:35 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/16 17:09:58 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LINE_TREE_H
# define B_LINE_TREE_H

# include <stdio.h>
# include <stdlib.h>

# define M 4

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				col;
}					t_point;

typedef struct		s_line
{
	t_point			*p1;
	t_point			*p2;
	int				z;
}					t_line;

/*
** n		n < M, number of keys keys in node
** 			will always less than order of B tree
**
** keys 	array of keys (lines)
** *p[M]	(n+1 pointers will be in use)
*/

typedef struct		s_node
{
	int				n;
	t_line			keys[M - 1];
	struct s_node	*p[M];
}					t_node;

int					insert(t_line key, t_node **root);
int					ins(t_node *r, t_line x, t_line *y, t_node **u);
void				clean(t_node *ptr);
void				eatline(void);
void				print_btree_in_order(t_node *ptr);

#endif




//if (n < M - 1)
//{
//pos = search_pos(new_key, ptr->keys, n);
//i = n;												//n
//while (i > pos)
//{
//ptr->keys[i] = ptr->keys[i - 1];
//ptr->p[i + 1] = ptr->p[i];
//i--;
//}
//ptr->keys[pos] = new_key;
//ptr->p[pos + 1] = new_ptr;
//++ptr->n;
//return (status_success);
//}