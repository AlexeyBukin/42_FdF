/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:59:35 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/17 20:43:44 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_TREE_OF_LINES_H
# define B_TREE_OF_LINES_H

# include "fdf.h"
# define M 22

/*
** n		n < M, number of keys keys in node
** 			will always less than order of B tree1
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

int					insert_line_in_btree(t_line key, t_node **root);
int					ins(t_node *r, t_line x, t_line *y, t_node **u);
void				free_btree(t_node *ptr);
void				eatline(void);
void				print_btree_in_order(t_node *ptr);

void				draw_btree_in_order(void *mlx_ptr, void *win_ptr, t_node **ptr);

#endif
