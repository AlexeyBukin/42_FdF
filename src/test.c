/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:49 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/14 23:14:35 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_stuff(void *mlx_ptr, void *win_ptr, double va, double ha, int scale)
{

	t_point red_dot = {4, 4, 0, 0x00FF0000};
	red_dot = convert_coords(red_dot, va, ha, scale);

	t_point green_dot = {-4, -4, 0, 0x0000FF00};
	green_dot = convert_coords(green_dot, va, ha, scale);

	t_point blue_dot = {-4, 4, 0, 0x000000FF};
	blue_dot = convert_coords(blue_dot, va, ha, scale);

	t_point pink_dot = {4, -4, 0, 0x00FF00FF};
	pink_dot = convert_coords(pink_dot, va, ha, scale);

	t_point white_dot = {0, 0,10, 0x00FFFFFF};
	white_dot = convert_coords(white_dot, va, ha, scale);

	t_line l1 = {&red_dot, &green_dot, 0, 0, 0};
	t_line l2 = {&green_dot, &blue_dot, 0, 0, 0};
	t_line l3 = {&blue_dot, &pink_dot, 0, 0, 0};
	t_line l4 = {&pink_dot, &red_dot, 0, 0, 0};
	t_line l5 = {&pink_dot, &green_dot, 0, 0, 0};
	t_line l6 = {&red_dot, &blue_dot, 0, 0, 0};

	t_line w1 = {&white_dot, &green_dot, 0, 0, 0};
	t_line w2 = {&white_dot, &red_dot, 0, 0, 0};
	t_line w3 = {&white_dot, &blue_dot, 0, 0, 0};
	t_line w4 = {&white_dot, &pink_dot, 0, 0, 0};

	draw_simple_line(mlx_ptr, win_ptr, l1);
	draw_simple_line(mlx_ptr, win_ptr, l2);
	draw_simple_line(mlx_ptr, win_ptr, l3);
	draw_simple_line(mlx_ptr, win_ptr, l4);
	draw_simple_line(mlx_ptr, win_ptr, l5);
	draw_simple_line(mlx_ptr, win_ptr, l6);

	draw_simple_line(mlx_ptr, win_ptr, w1);
	draw_simple_line(mlx_ptr, win_ptr, w2);
	draw_simple_line(mlx_ptr, win_ptr, w3);
	draw_simple_line(mlx_ptr, win_ptr, w4);

//	///0x00888080
//	t_point grey_dot = {300, 300, 0, 0x00AAAAAA};
//	t_point red_dot_2 = {350, 350, 0, 0x00FFFFFF};
//	t_line blend_line = {&grey_dot, &red_dot_2};
//	draw_simple_line(mlx_ptr, win_ptr, blend_line);
}

t_point		***points_dup(t_point ***points)
{
	t_point	***p_dup;
	int		line_num;
	int		line_len;
	int		i;
	int 	j;

	if (points == 0)
		return (0);

	line_num = 0;
	while (points[line_num] != 0)
		line_num++;

	p_dup = (t_point ***)malloc(sizeof(t_point **) * (line_num + 1));

	if (line_num < 1 || p_dup == 0)
		return (0);

	p_dup[line_num] = 0;


	line_len = 0;
	while (points[0][line_len] != 0)
		line_len++;
	i = 0;
	while (points[i] != 0)
	{
		p_dup[i] = (t_point **)malloc(sizeof(t_point*) * (line_len + 1));
		if (p_dup[i] == 0)
		{
			free_points(p_dup);
			return (0);
		}
		j = 0;
		while (points[i][j] != 0)
		{
			p_dup[i][j] = (t_point *)malloc(sizeof(t_point));
			if (p_dup[i][j] == 0)
			{
				free_points(p_dup);
				return (0);
			}
			*p_dup[i][j] = *points[i][j];
			j++;
		}
		p_dup[i][j] = 0;
		i++;
	}
	return (p_dup);
}

t_point		***new_points_as(t_point ***points)
{
	t_point	***p_dup;
	int		line_num;
	int 	line_len;
	int		i;

	if (points == 0)
		return (0);

	line_num = 0;
	while (points[line_num] != 0)
		line_num++;

	p_dup = (t_point ***)malloc(sizeof(t_point **) * (line_num + 1));
	if (p_dup == 0 || line_num < 1)
		return (0);
	p_dup[line_num] = 0;

	line_len = 0;
	while (points[0][line_len] != 0)
		line_len++;

	i = 0;
	while (points[i] != 0)
	{
		p_dup[i] = (t_point **)malloc(sizeof(t_point *) * (line_len + 1));
		if (p_dup[i] == 0)
		{
			free_points(p_dup);
			return (0);
		}
		p_dup[i][line_len] = 0;
		i++;
	}
	return (p_dup);
}

int		is_on_screen(t_point *a, t_point *b)
{
	int boundX = 1024;
	int boundY = 1024;

	if (a->x > boundX || a->x < 0 || a->y > boundY || a->y < 0)
	{
		if (b->x > boundX || b->x < 0 || b->y > boundY || b->y < 0)
		{
			return (0);
		}
	}
	return (1);
}

void		draw_parallel(void *mlx_ptr, void *win_ptr, t_point ***points, double va, double ha, int scale)
{
	t_point		***new_points;
	int			line_num;
	int			line_len;
	int			i;
	int 		j;


	t_point blue_dot = {512, 0, 0, 0x000000FF};
	t_point blue_dot_2 = {512, 1024, 0, 0x000000FF};

	t_point blue_dot_3 = {0, 512, 0, 0x000000FF};
	t_point blue_dot_4 = {1024, 512, 0, 0x000000FF};

	t_line b1 = {&blue_dot, &blue_dot_2, 0, 0, 0};
	t_line b2 = {&blue_dot_3, &blue_dot_4, 0, 0, 0};

	draw_simple_line(mlx_ptr, win_ptr, b1);
	draw_simple_line(mlx_ptr, win_ptr, b2);


	clock_t t2, t3;
	t2 = clock();


	new_points = points_dup(points);
	if (new_points == 0)
		return ;

//	printf("\n");
//	print_points(new_points);
//	printf("\n");

	//printf("\nbefore conv:\n");
	//print_points(new_points);

	clock_t t0, t1;
	t0 = clock();

	i = 0;
	while (points[i] != 0)
	{
		j = 0;
		while (points[i][j] != 0)
		{
			convert_coords_on_place(new_points[i][j], va, ha, scale);
			//*new_points[i][j] = convert_coords(*new_points[i][j], va, ha, scale);
			j++;
		}
		i++;
	}

	t1 = clock() - t0;
	printf("\t\t(time: %f), converted : draw_parallel\n", ((double)t1)/CLOCKS_PER_SEC);


	line_len = j;
	line_num = i;

	//printf("\nafter conv:\n");
	//print_colors(new_points);
	//print_points(new_points);
	//printf("\n");

	t_line	*line_list = 0;


	t_line	*tmp = 0;

	int minimal_distance = 0;
	int maximal_distance = 0;
	int zero_num = 0;

	i = 0;
	while (i < line_num)
	{
		j = 0;
		while (j < line_len)
		{
			if (j < line_len - 1)
			{
				if ( is_on_screen(new_points[i][j], new_points[i][j+1]) )
				{
					tmp = (t_line*)malloc(sizeof(t_line));
					if (tmp == 0)
					{
						free_points(new_points);
						free_line_list(line_list);
						return ;
					}
					tmp->p1 = new_points[i][j];
					tmp->p2 = new_points[i][j+1];

					/// tmp->z = (tmp->p1->z > tmp->p2->z) ? tmp->p1->z : tmp->p2->z;
					tmp->z = tmp->p1->z;

					///delete me
					if (tmp->z > maximal_distance)
						maximal_distance = tmp->z;
					if (tmp->z < minimal_distance)
						minimal_distance = tmp->z;
					if (tmp->z == 0)
						zero_num++;

					tmp->next = 0;
					tmp->prev = 0;

					add_line(&line_list, tmp);
					//insert_line(&line_list, tmp);
				}
			}
			if (i < line_num - 1)
			{
				if ( is_on_screen(new_points[i][j], new_points[i + 1][j]) )
				{
					tmp = (t_line*)malloc(sizeof(t_line));
					if (tmp == 0)
					{
						free_points(new_points);
						free_line_list(line_list);
						return ;
					}
					tmp->p1 = new_points[i][j];
					tmp->p2 = new_points[i + 1][j];

					/// tmp->z = (tmp->p1->z > tmp->p2->z) ? tmp->p1->z : tmp->p2->z;
					tmp->z = tmp->p1->z;

					///delete me
					if (tmp->z > maximal_distance)
						maximal_distance = tmp->z;
					if (tmp->z < minimal_distance)
						minimal_distance = tmp->z;
					if (tmp->z == 0)
						zero_num++;

					tmp->next = 0;
					tmp->prev = 0;

					add_line(&line_list, tmp);
					//insert_line(&line_list, tmp);
				}
			}
			j++;
		}
		i++;
	}

	printf("\nmin: %d, max: %d, zero_num: %d\n\n", minimal_distance, maximal_distance, zero_num);
	t3 = clock() - t2;
	printf("\t\t(time: %f), before_render : draw_parallel\n", ((double)t3)/CLOCKS_PER_SEC);

	//t_line	*line_list_old = line_list;

	if (line_list != 0)
	{
		draw_simple_line(mlx_ptr, win_ptr, *line_list);
		while(line_list->next!= 0)
		{
			line_list = line_list->next;
			draw_simple_line(mlx_ptr, win_ptr, *line_list);
		}
	}

//	line_list = line_list_old;
//
//	if (line_list != 0)
//	{
//		draw_simple_line(mlx_ptr, win_ptr, *line_list);
//		while(line_list->next!= 0)
//		{
//			line_list = line_list->next;
//			draw_simple_line(mlx_ptr, win_ptr, *line_list);
//		}
//	}
//
//	line_list = line_list_old;
//
//	if (line_list != 0)
//	{
//		draw_simple_line(mlx_ptr, win_ptr, *line_list);
//		while(line_list->next!= 0)
//		{
//			line_list = line_list->next;
//			draw_simple_line(mlx_ptr, win_ptr, *line_list);
//		}
//	}

	t3 = clock() - t2;
	printf("\t\t(time: %f) : draw_parallel\n", ((double)t3)/CLOCKS_PER_SEC);

//	t_point red_dot = convert_coords(points[0][0], va, ha, scale);
//	t_point red_dot_2 = convert_coords(points[0][1], va, ha, scale);
//	t_point red_dot_3 = convert_coords(points[0][2], va, ha, scale);
//
//	t_point green_dot = convert_coords(points[1][0], va, ha, scale);
//
//	t_line l1 = {&red_dot, &red_dot_2};
//	t_line l2 = {&red_dot_2, &red_dot_3};
//	t_line l3 = {&red_dot, &green_dot};
//
//	draw_simple_line(mlx_ptr, win_ptr, l1);
//	draw_simple_line(mlx_ptr, win_ptr, l3);
//	draw_simple_line(mlx_ptr, win_ptr, l2);

}
