/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:09:07 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/16 12:09:07 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_line_tree.h"

void			eatline(void)
{
	char	c;

	while ((c = getchar()) != '\n')
		c++;
}

int				main(void)
{
	t_node		*root;
	t_line		key;
	int			choice;

	root = NULL;
	printf("Creation of B tree for M=%d\n", M);
	while (1)
	{
		printf("%p\n", root);
		printf("1.Insert\n");
		printf("2.Enumerate\n");
		printf("3.Quit\n");
		printf("4.Set root to NULL\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		eatline();
		printf("\n");
		if (choice == 1)
		{
			printf("Enter the key : ");
			scanf("%d", &key.z);
			eatline();
			insert(key, &root);
		}
		else if (choice == 2)
		{
			printf("Btree in sorted order is:\n");
			inorder(root);
			root = NULL;
			putchar('\n');
		}
		else if (choice == 3)
		{
			inorder(root);
			return (0);
		}
		else if (choice == 4)
		{
			root = NULL;
		}
		else
		{
			printf("Wrong choice\n");
		}
	}
	return (0);
}
