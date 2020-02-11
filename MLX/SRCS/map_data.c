/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/11 20:09:36 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	background_for_map(t_mlx *mlx)
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
			col.b = 200;
			color = get_color(col);
			mlx_pixel_put(mlx->mptr, mlx->wptr, i, j, color);
			i++;
		}
		j++;
		if (j % 100 == 0)
			printf("j %d\n", j);
	}
}

void	walls_on_map(t_mlx *mlx, char *map)
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
			draw_rect(rect, RECT_W, RECT_H, (t_color){153, 113, 233}, mlx);
			i++;
		}
		j++;
	}
}

t_player	player_on_map(t_mlx *mlx)
{
	t_player p;

	p.pos.x = 5;
	p.pos.y = 2;
	p.transform.x = p.pos.x * RECT_W;
	p.transform.y = p.pos.y * RECT_H;
	draw_rect(p.transform, 6, 6, (t_color){255, 255, 255}, mlx);
	return (p);
}
