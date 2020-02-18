/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/18 21:32:35 by cvernius         ###   ########.fr       */
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
			if ((i + j * WIN_W) <= (WIN_H * WIN_W) && (i + j * WIN_W) >= 0) 
				w->mlx.img[i + j * WIN_W] = color;
			i++;
		}
		j++;
	}
}

void	draw_walls(t_wolf *w, char *map)
{
	int			i;
	int			j;
	t_drawrect	dr;

	j = 0;
	dr = (t_drawrect){(t_ivec2){0, 0}, (t_color){0, 0, 0}};
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
			dr.firstpix.x = i * RECT_W; // перевод координат в масштаб окна из масштаба карты
			dr.firstpix.y = j * RECT_H;
			if (map[i + j * MAP_W] == '0')
				dr.color = (t_color){153, 113, 233};			// pirple
			if (map[i + j * MAP_W] == '1')
				dr.color = (t_color){227, 176, 229};			// pink
			if (map[i + j * MAP_W] == '2')
				dr.color = (t_color){92, 147, 255};				// blue
			if (map[i + j * MAP_W] == '3')
				dr.color = (t_color){176, 229, 193};			// green
			draw_rect(dr, RECT_W, RECT_H, w->mlx);		
			i++;
		}
		j++;
	}
}
