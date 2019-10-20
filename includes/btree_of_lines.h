/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:59:35 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/20 19:56:23 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_OF_LINES_H
# define BTREE_OF_LINES_H

# include "fdf.h"
# define M 22

/*
** n		n < M, number of keys keys in node
** 			will always less than order of B tree1
**
** keys 	array of keys (lines)
** *p[M]	(n+1 pointers will be in use)
*/

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

typedef struct		s_node
{
	int				n;
	t_line			keys[M - 1];
	struct s_node	*p[M];
}					t_node;

int					insert_line_in_btree(t_line key, t_node **root);
int					ins(t_node *r, t_line x, t_line *y, t_node **u);
void				free_btree(t_node *ptr);

void				draw_btree_in_order(void *mlx, void *win, t_node **ptr);

#endif
