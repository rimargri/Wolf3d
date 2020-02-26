/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/26 22:16:24 by cvernius         ###   ########.fr       */
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

void	draw_background(t_wolf *w)
{
	int x;
	int y;
	t_color col;
	int color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			col.r = (255 * y / WIN_H);
			col.g = (255 * x / WIN_W);
			col.b = 193;
			color = get_color(col);
			if ((x + y * WIN_W) <= (WIN_H * WIN_W) && (x + y * WIN_W) >= 0) 
				w->mlx.img[x + y * WIN_W] = color;
			x++;
		}
		y++;
	}
}

// void	draw_texture_on_background(t_wolf *w, t_texture *t)
// {
// 	int x;
// 	int y;
// 	int i;

// 	x = 0;
// 	while (x < WIN_W)
// 	{
// 		y = 0;
// 		while (y < WIN_H)
// 		{
// 			w->mlx.img[x + y * WIN_W] = t->texture[];
// 			y++;
// 		}
// 		x++;
// 	}
// }


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
			if (w->map.line[x + y * w->map.w] >= '0' && w->map.line[x + y * w->map.w] <= '3')
				dr.color = color_of_texture(w, w->map.line[x + y * w->map.w]);
			else if ((w->map.line[x + y * w->map.w]) == '4')
				dr.color = get_color((t_color){0, 0, 0});					// black
			else if ((w->map.line[x + y * w->map.w]) == '5')
				dr.color = get_color((t_color){240, 100, 100});				// red
			else if ((w->map.line[x + y * w->map.w]) == '6')
				dr.color = get_color((t_color){240, 240, 240});				// gray
			else if ((w->map.line[x + y * w->map.w]) == '7')
				dr.color = get_color((t_color){100, 150, 100});
			else
				dr.color = get_color((t_color){-1, -1, -1});
			draw_rect(dr, rect_w(w->map.w), rect_h(w->map.h), w);
			x++;
		}
		y++;
	}
}
