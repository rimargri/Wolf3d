/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:03:09 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/10 21:44:42 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_first_person_view(t_mlx *mlx, float t, int i)
{
	int column_height;
	t_ivec2 first_pix;

	column_height = (int) (WIN_H / t);
	printf("column_height = %d\n", (int)(WIN_H / t));
	first_pix = (t_ivec2){WIN_W / 2 + i, WIN_H / 2 - column_height / 2};
	draw_rect(first_pix, 1, column_height, (t_color){153, 113, 233}, mlx);
}

/*
** vec_dir - direction vector
*/

void	cast_ray(t_mlx *mlx, char *map, t_ivec2 player)
{
	float vec_dir;
	t_ivec2 transform;
	t_vec2 tmp;
	float t;
	float angle;
	int i;
	int color = get_color((t_color){255, 255, 255});

	printf("I'm on cast_ray\n");
	vec_dir = 1.5;
	transform = (t_ivec2){0, 0};
	tmp = (t_vec2){0, 0};
	i = 0;

	while (i < WIN_W / 2)
	{
		angle = vec_dir - FOV / 2 + FOV * i / (float) (WIN_W / 2);
		t = 0.0;
		while (t < 20)
		{
			tmp.x = cos(angle) * t + player.x;
			tmp.y = sin(angle) * t + player.y;
			transform.x = tmp.x * RECT_W;
			transform.y = tmp.y * RECT_H;
			mlx_pixel_put(mlx->mptr, mlx->wptr, transform.x, transform.y, color);
			if (map[(int)tmp.x + (int)tmp.y * MAP_W] != ' ')
			{
				printf("nyaaa\n");
				draw_first_person_view(mlx, t, i);
				break;
			}
			t+= 0.1;
		}
		i++;	
	}
}
