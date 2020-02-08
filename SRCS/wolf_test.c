/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/08 19:37:34 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	background_for_map(t_sdl *sdl)
{
	int i;
	int j;
	t_color col;

	j = 0;
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			col.r = (255 * j / WIN_H);
			col.g = (255 * i / WIN_W);
			col.b = 200;
			set_pixel(sdl->renderer, col, i, j);
			i++;
		}
		j++;
		printf("j %d\n", j);
	}
}

void	walls_on_map(t_sdl *sdl, char *map)
{
	int i;
	int j;
	t_vec2 rect;

	j = 0;
	rect = (t_vec2){0, 0};
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
			draw_rect(rect, RECT_W, RECT_H, (t_color){153, 113, 233}, sdl->renderer);
			i++;
		}
		j++;
	}
}
