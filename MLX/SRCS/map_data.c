/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/14 23:13:38 by cvernius         ###   ########.fr       */
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

void	draw_walls(t_wolf *w, char *map)
{
	int i;
	int j;
	t_ivec2 rect;

	j = 0;
	rect = (t_ivec2){0, 0};
	while (j < MAP_H)
	{
		i = 0;
		while (i < MAP_W)
		{
			if (map[i + j * MAP_W] == ' ')
			{
				i++;
				continue;
			}
			rect.x = i * RECT_W; // перевод координат в масштаб окна из масштаба карты
			rect.y = j * RECT_H;
			if (map[i + j * MAP_W] == '0')
				draw_rect(rect, RECT_W, RECT_H, (t_color){153, 113, 233}, w->mlx);		// pirple
			if (map[i + j * MAP_W] == '1')
				draw_rect(rect, RECT_W, RECT_H, (t_color){227, 176, 229}, w->mlx);		// pink
			if (map[i + j * MAP_W] == '2')
				draw_rect(rect, RECT_W, RECT_H, (t_color){92, 147, 255}, w->mlx);		// blue
			if (map[i + j * MAP_W] == '3')
				draw_rect(rect, RECT_W, RECT_H, (t_color){176, 229, 193}, w->mlx);		// green
			i++;
		}
		j++;
	}
}

void	init_player(t_wolf *w)
{
	t_player p;

	w->player = p;
	w->player.pos.x = 5;
	w->player.pos.y = 2;
}

void	draw_player(t_wolf *w)
{
	printf("draw_player---w->player.pos.x = %d\n", w->player.pos.x);
	w->player.transform.x = w->player.pos.x * RECT_W;
	w->player.transform.y = w->player.pos.y * RECT_H;
	draw_rect(w->player.transform, 6, 6, (t_color){255, 255, 255}, w->mlx);
}
