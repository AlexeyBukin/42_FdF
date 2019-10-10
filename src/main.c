#include "mlx.h"
#include "libft.h"

#include <stdio.h>

int key_pressed()
{
	return (0);
}

typedef struct		s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				color;
}					t_line;

/*
 * function line(x0, x1, y0, y1)
     int deltax := abs(x1 - x0)
     int deltay := abs(y1 - y0)
     int error := 0
     int deltaerr := deltay
     int y := y0
     int diry := y1 - y0
     if diry > 0
         diry = 1
     if diry < 0
         diry = -1
     for x from x0 to x1
         plot(x,y)
         error := error + deltaerr
         if 2 * error >= deltax
             y := y + diry
             error := error - deltax
 */
void make_drawable_y(t_line *line)
{
	if (line->y1 > line->y2)
	{
		int tmp;
		tmp = line->x1;
		line->x1 = line->x2;
		line->x2 = tmp;

		tmp = line->y1;
		line->y1 = line->y2;
		line->y2 = tmp;
	}
}

void make_drawable_x(t_line *line)
{
	if (line->x1 > line->x2)
	{
		int tmp;
		tmp = line->x1;
		line->x1 = line->x2;
		line->x2 = tmp;

		tmp = line->y1;
		line->y1 = line->y2;
		line->y2 = tmp;
	}
}

void	draw_line_x(void *mlx_ptr, void *win_ptr, t_line l)
{
	printf("drawn as x line\n");
	make_drawable_x(&l);

	int color = l.color;

	int delta_x = ft_abs(l.x2 - l.x1);
	int delta_y = ft_abs(l.y2 - l.y1);

	int error = 0;
	int delta_err = delta_y;

	int dir_y = l.y2 - l.y1;

	dir_y = (dir_y > 0) - (dir_y < 0);

	int x = l.x1;
	int y = l.y1;
	while (x <= l.x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		error += delta_err;
		if (2 * error >= delta_x)
		{
			y += dir_y;
			error = error - delta_x;
		}
		x++;
	}
}

void	draw_line_y(void *mlx_ptr, void *win_ptr, t_line l)
{
	printf("drawn as y line\n");
	make_drawable_y(&l);
	int color = l.color;

	int delta_x = ft_abs(l.x2 - l.x1);
	int delta_y = ft_abs(l.y2 - l.y1);

	int error = 0;
	int delta_err = delta_x;

	int dir_x = l.x2 - l.x1;

	dir_x = (dir_x > 0) - (dir_x < 0);

	int x = l.x1;
	int y = l.y1;
	while (y <= l.y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, l.color);
		error += delta_err;
		if (2 * error >= delta_y)
		{
			x += dir_x;
			error = error - delta_y;
		}
		y++;
	}
}

void	draw_line(void *mlx_ptr, void *win_ptr, t_line l)
{
	double k;

	k = (l.x2 == l.x1) ? 1 : (l.y2 - l.y1 + 0.0) / (l.x2 - l.x1 + 0.0);
	printf("k after: (%f)\n", k);
	if (ft_abs(k) >= 1)
		draw_line_y(mlx_ptr, win_ptr, l);
	else
		draw_line_x(mlx_ptr, win_ptr, l);
}



int main()
{
	void * mlx_ptr = mlx_init();
	void * win_ptr = mlx_new_window(mlx_ptr, 1024, 768, "my new window");


	printf("\n\ngreen: \n");
	t_line green_line;
	green_line.x1 = 50;
	green_line.y1 = 50;
	green_line.x2 = 0;
	green_line.y2 = 75;
	green_line.color = 0x0000FF00;
	draw_line(mlx_ptr, win_ptr, green_line);

	green_line.x1 = 50;
	green_line.y1 = 50;
	green_line.x2 = 0;
	green_line.y2 = 25;
	draw_line(mlx_ptr, win_ptr, green_line);

	green_line.x1 = 50;
	green_line.y1 = 50;
	green_line.x2 = 0;
	green_line.y2 = 50;
	draw_line(mlx_ptr, win_ptr, green_line);

	printf("\n\nblue: \n");
	t_line blue_line;
	blue_line.x1 = 50;
	blue_line.y1 = 50;
	blue_line.x2 = 100;
	blue_line.y2 = 25;
	blue_line.color = 0x000000FF;
	draw_line(mlx_ptr, win_ptr, blue_line);

	blue_line.x1 = 50;
	blue_line.y1 = 50;
	blue_line.x2 = 100;
	blue_line.y2 = 75;
	draw_line(mlx_ptr, win_ptr, blue_line);

	blue_line.x1 = 50;
	blue_line.y1 = 50;
	blue_line.x2 = 100;
	blue_line.y2 = 50;
	draw_line(mlx_ptr, win_ptr, blue_line);

	printf("\n\nred: \n");
	t_line red_line;
	red_line.x1 = 50;
	red_line.y1 = 50;
	red_line.x2 = 75;
	red_line.y2 = 0;
	red_line.color = 0x00FF0000;
	draw_line(mlx_ptr, win_ptr, red_line);

	red_line.x1 = 50;
	red_line.y1 = 50;
	red_line.x2 = 25;
	red_line.y2 = 0;
	draw_line(mlx_ptr, win_ptr, red_line);

	red_line.x1 = 50;
	red_line.y1 = 50;
	red_line.x2 = 50;
	red_line.y2 = 0;
	draw_line(mlx_ptr, win_ptr, red_line);

	printf("\n\nwhite: \n");
	t_line white_line;
	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 75;
	white_line.y2 = 100;
	white_line.color = 0x00FFFFFF;
	draw_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 25;
	white_line.y2 = 100;
	draw_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 51;
	white_line.y2 = 100;
	draw_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 49;
	white_line.y2 = 100;
	draw_line(mlx_ptr, win_ptr, white_line);

	white_line.x1 = 50;
	white_line.y1 = 50;
	white_line.x2 = 50;
	white_line.y2 = 100;
	draw_line(mlx_ptr, win_ptr, white_line);


	win_ptr = 0;
	mlx_loop(mlx_ptr);
	return (0);
}