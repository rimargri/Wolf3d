/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/13 23:43:33 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
			mlx_pixel_put(w->mlx.mptr, w->mlx.wptr, i, j, color);
			i++;
		}
		j++;
	}
}

int		rect_w(int w)
{
	return (WIN_W / 2 / w);
}

int		rect_h(int h)
{
	return (WIN_H / h);
}

void	draw_walls(t_wolf *w, t_map map)
{
	int i;
	int j;
	t_ivec2 rect;

	j = 0;
	rect = (t_ivec2){0, 0};
	while (j < map.h)
	{
		i = 0;
		while (i < map.w)
		{
			if (map.line[i + j * map.w] == ' ')
			{
				i++;
				continue;
			}
			rect.x = i * rect_w(map.w); // перевод координат в масштаб окна из масштаба карты
			rect.y = j * rect_h(map.h);
			if (map.line[i + j * map.w] == '0')
				draw_rect(rect, rect_w(map.w), rect_h(map.h), (t_color){153, 113, 233}, w->mlx);		// pirple
			if (map.line[i + j * map.w] == '1')
				draw_rect(rect, rect_w(map.w), rect_h(map.h), (t_color){227, 176, 229}, w->mlx);		// pink
			if (map.line[i + j * map.w] == '2')
				draw_rect(rect, rect_w(map.w), rect_h(map.h), (t_color){92, 147, 255}, w->mlx);		// blue
			if (map.line[i + j * map.w] == '3')
				draw_rect(rect, rect_w(map.w), rect_h(map.h), (t_color){176, 229, 193}, w->mlx);		// green
			i++;
		}
		j++;
	}
}

void	init_player(t_wolf *w)
{
	t_player p;

	p.pos.x = 5;
	p.pos.y = 2;
	w->player.pos = p.pos;
}

void	draw_player(t_wolf *w)
{
	w->player.transform.x = w->player.pos.x * rect_w(w->tmap.w);
	w->player.transform.y = w->player.pos.y * rect_h(w->tmap.h);
	draw_rect(w->player.transform, 6, 6, (t_color){255, 255, 255}, w->mlx);
}
