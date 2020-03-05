/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 16:11:28 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		rect_w(int w)
{
	return ((WIN_W / 2 / w));
}

int		rect_h(int h)
{
	return (WIN_H / h);
}

void	draw_background_on_map(t_wolf *w)
{
	int x;
	int y;
	int color;

	y = 0;
	color = get_color((t_color){120, 120, 150});
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W / 2)
		{
			if ((x + y * WIN_W) <= (WIN_H * WIN_W) && (x + y * WIN_W) >= 0)
				w->layers->map_view.img[x + y * WIN_W] = color;
			x++;
		}
		y++;
	}
}

void	draw_texture_on_celling(t_wolf *w, t_texture *t)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			w->layers->background.img[x + y * WIN_W] = t->texture[x + y * t->size];
			x++;
		}
		y++;
	}
}

void	draw_texture_on_floor(t_wolf *w, t_texture *t)
{
	int x;
	int y;

	y = WIN_H / 2;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			w->layers->background.img[x + y * WIN_W] = t->texture[x + y * t->size];
			x++;
		}
		y++;
	}
}

void	draw_walls(t_wolf *w)
{
	int			x;
	int			y;
	t_drawrect	dr;

	y = 0;
	dr = (t_drawrect){(t_ivec2){0, 0}, get_color((t_color){0, 0, 0})};
	while (y < w->map.h)
	{
		x = 0;
		while (x < w->map.w)
		{
			if (w->map.line[x + y * w->map.w] == ' ')
			{
				x++;
				continue;
			}
			dr.firstpix.x = x * rect_w(w->map.w);				// перевод координат в масштаб окна из масштаба карты
			dr.firstpix.y = y * rect_h(w->map.h);
			if (w->map.line[x + y * w->map.w] >= '0' && w->map.line[x + y * w->map.w] <= '7')
				dr.color = choice_color(w, w->map.line[x + y * w->map.w]);
			// if (w->map.line[x + y * w->map.w] >= '0' && w->map.line[x + y * w->map.w] <= '3')
			// 	dr.color = color_of_texture(w, w->map.line[x + y * w->map.w]);
			// else if (w->map.line[x + y * w->map.w] >= '4' && w->map.line[x + y * w->map.w] <= '7')
			// 	dr.color = color_of_wall(w->map.line[x + y * w->map.w]);
			else
				dr.color = -1;
			draw_rect(dr, rect_w(w->map.w), rect_h(w->map.h), &w->layers->map_view);
			x++;
		}
		y++;
	}
}
