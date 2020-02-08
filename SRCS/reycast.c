/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:03:09 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/08 23:23:43 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_first_person_view(t_sdl *sdl, float t, int i)
{
	int column_height;
	t_vec2 first_pix;

	column_height = WIN_H / t;
	first_pix = (t_vec2){WIN_W / 2 + i, WIN_H / 2 - column_height / 2};
	draw_rect(first_pix, 1, column_height, (t_color){153, 113, 233}, sdl->renderer);
}

/*
** vec_dir - direction vector
*/

void	cast_ray(t_sdl *sdl, char *map, t_vec2 player)
{
	float vec_dir;
	t_vec2 transform;
	t_fvec2 tmp;
	float t;
	float angle;
	int i;

	vec_dir = 0.5;
	transform = (t_vec2){0, 0};
	tmp = (t_fvec2){0, 0};
	i = 0;
	while (i < WIN_W)
	{
		angle = vec_dir - FOV / 2 + FOV * i / (float) (WIN_W);
		t = 0.0;
		while (t < 20)
		{
			tmp.x = cos(angle) * t + player.x;
			tmp.y = sin(angle) * t + player.y;
			// printf("tmp.x = %f\n tmp.y = %f\n", tmp.x, tmp.y);
			if (map[(int)tmp.x + (int)tmp.y * MAP_W] != ' ') 
				break;
			transform.x = tmp.x * RECT_W;
			transform.y = tmp.y * RECT_H;
			set_pixel(sdl->renderer, (t_color){255, 255, 255}, transform.x, transform.y);
			// if (map[(int)tmp.x + (int)tmp.y * MAP_W] != ' ')
			// {
			// 	draw_first_person_view(sdl, t, i);
			// 	break;
			// }
			t+= 0.01;
		}
		i++;	
	}
}
