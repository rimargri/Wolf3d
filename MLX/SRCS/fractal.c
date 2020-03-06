/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:07:41 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 22:07:43 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			fract_get_color(int iteration, int max_iteration)
{
	double			t;
	int				red;
	int				green;
	int				blue;

	if (iteration == max_iteration)
		return (0xAAFF77FF);
	t = ((double)iteration / (double)max_iteration);
	green = (int)(9 * (1 - t) * pow(t, 3) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	red  = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	if (blue % 255 == 0 || blue % 254 == 0 || blue % 253 == 0 || blue % 252 == 0)
		blue += 20;
	return (0xCC << 24 | (red) << 16 | (green) << 8 | (blue));
}

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
}
