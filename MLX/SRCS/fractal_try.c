//
// Created by Hugor Chau on 2020-02-24.
//

#include "wolf3d.h"

void		image_set_pixel(t_img **image, int x, int y, int color)
{
	int				i;
	t_img			*img;

	x *= 4;
	i = 0;
	img = *image;
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	while (i < 4)
	{
		*(int *)(img->img + ((x + i + y * WIN_W))) = color;
		i++;
	}
}

void	init_fractol(t_draw_fractal **f)
{
	static t_fractal	count = {20, {0.4, 0.1}, {0, 0}, {0, 0}};

	*f = (t_draw_fractal *)malloc(sizeof(t_draw_fractal));
	(*f)->is_mooving = IN;
	(*f)->count = count;

//	(*f)->drawing = lol;
//	(*f)->on = FALSE;
}


//
//
int		julia(t_fractal *julia)
{
	int			iteration;
	t_complex	z;
	double		extra;

	iteration = 0;
	z.x = julia->constant.y;
	z.y = julia->constant.x;
	while (pow(z.x, 2.0) + pow(z.y, 2.0) <= 4
		   && iteration < julia->max_iteration)
	{
		extra = z.x;
		z.x = pow(z.x, 2.0) - pow(z.y, 2.0) + julia->k.x;
		z.y = 2.0 * extra * z.y + julia->k.y;
		iteration++;
	}
	return (iteration);
}
//
//
//void		recalculate(int *first, int *second, int *third, double t)
//{
//	*first = (int)(9 * (1 - t) * pow(t, 3) * 255);
//	*second = (int)(8.5 * pow((1 - t), 3) * t * 255);
//	*third = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
//}

int			fract_get_color(int iteration, int max_iteration)
{
	double		t;
	static int	color_shift;
	int			red;
	int			green;
	int			blue;

	if (iteration == max_iteration)
		return (0xAAFF77FF);
	t = ((double)iteration / (double)max_iteration);
	green = (int)(9 * (1 - t) * pow(t, 3) * 255);
	red = (int)(8.5 * pow((1 - t), 3) * t * 255);
	blue = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color_shift++;
	return (0xCC << 24 | (red) << 16 | green << 8 | blue);
}

/*
**		разбиение на потоки, передача пикселей в следующую функцию
*/

int			get_fractal_img(t_draw_fractal *full)
{
	int				y;
	int				x;

	y = full->start_line;
	while (y < full->finish_line && y < WIN_H)
	{
		full->count.constant.y = 1.0 - y * full->count.cur.y;
		x = 0;
		while (x < WIN_W)
		{
			full->count.constant.x = -1.0 + x * full->count.cur.x;
			image_set_pixel(&full->drawing, x, y,
							fract_get_color(julia(&full->count),
									  full->count.max_iteration));
			x++;
		}
		y++;
	}
	return (0);
}

void		draw_fractal(t_draw_fractal **fractal, t_img *f)
{
	pthread_t		threads[THREADS];
	t_draw_fractal	current[THREADS];
	int				i;

	(*fractal)->count.cur.x = (0.0 + 8.0)
						   / (WIN_W - 1);
	(*fractal)->count.cur.y = (1.0 + 1.0)
						   / (WIN_H - 1);
	(*fractal)->drawing = f;
	i = 0;
	while (i < THREADS)
	{
		current[i] = **fractal;
		current[i].start_line = i * (WIN_H / THREADS);
		current[i].finish_line = (i + 1) * (WIN_H / THREADS);
		pthread_create(&threads[i], NULL,
					   (void *(*)(void *))get_fractal_img, (void *)&current[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
//	f = (*fractal)->drawing;
}
