/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/20 19:56:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

//_FIXX_IF_YOU_WANNA это переделать на background
void	draw_background(t_wolf *w)
{
	int i;
	int j;
	t_color col;
	int color;

	j = 0;
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			col.r = (255 * j / WIN_H);
			col.g = (255 * i / WIN_W);
			col.b = 193;
			color = get_color(col);
			if ((i + j * WIN_W) <= (WIN_H * WIN_W) && (i + j * WIN_W) >= 0)
				w->layers->background.img[i + j * WIN_W] = color;
			i++;
		}
		j++;
	}
}

int		rect_w(int w)
{
	return ((WIN_W / 2 / w));
}

int		rect_h(int h)
{
	return (WIN_H / h);
}

void	draw_walls(t_wolf *w)
{
	int			i;
	int			j;
	t_drawrect	dr;

	j = 0;
	dr = (t_drawrect){(t_ivec2){0, 0}, (t_color){0, 0, 0}};
	while (j < w->map.h)
	{
		i = 0;
		while (i < w->map.w)
		{
			if (w->map.line[i + j * w->map.w] == ' ')
			{
				i++;
				continue;
			}
			dr.firstpix.x = i * rect_w(w->map.w);				// перевод координат в масштаб окна из масштаба карты
			dr.firstpix.y = j * rect_h(w->map.h);
			if (w->map.line[i + j * w->map.w] == '0')
				dr.color = (t_color){153, 113, 233};			// pirple
			else if (w->map.line[i + j * w->map.w] == '1')
				dr.color = (t_color){227, 176, 229};			// pink
			else if (w->map.line[i + j * w->map.w] == '2')
				dr.color = (t_color){92, 147, 255};				// blue
			 else if (w->map.line[i + j * w->map.w] == '3')
				dr.color = (t_color){176, 229, 193};			// green
			else if ((w->map.line[i + j * w->map.w]) == '4')
				dr.color = (t_color){0, 0, 0};					// black
			else if ((w->map.line[i + j * w->map.w]) == '5')
				dr.color = (t_color){240 ,100, 100};			// red
			else if ((w->map.line[i + j * w->map.w]) == '6')
				dr.color = (t_color){240 ,240, 240};			// red
			else if ((w->map.line[i + j * w->map.w]) == '7')
				dr.color = (t_color){100, 150, 100};
			else
				dr.color = (t_color){-1, -1, -1};
			draw_rect(dr, rect_w(w->map.w), rect_h(w->map.h), &w->layers->map_view);
			i++;
		}
		j++;
	}
}
