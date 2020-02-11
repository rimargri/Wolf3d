/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:03:09 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/10 15:42:14 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_first_person_view(t_sdl *sdl, float t, int i)
{
	int column_height;
	t_ivec2 first_pix;

	column_height = WIN_H / t;
	first_pix = (t_ivec2){WIN_W / 2 + i, WIN_H / 2 - column_height / 2};
	draw_rect(first_pix, 1, column_height, (t_color){153, 113, 233}, sdl->renderer);
}

/*
** vec_dir - direction vector
*/

void	cast_ray(t_sdl *sdl, char *map, t_player player)
{
	t_reycast	r;

	r.player = player;

	// while (vec_dir < 360.0)
	// {
		r.vec_dir = 1.5;
		r.transform = (t_ivec2){0, 0};
		r.len = (t_vec2){0, 0};
		r.curent_pix = 0;
		while (r.curent_pix < WIN_W / 2)
		{
			r.angle = r.vec_dir - FOV / 2 + FOV * r.curent_pix / (float) (WIN_W);
			r.t = 0.0;
			while (r.t < 20)
			{
				r.len.x = cos(r.angle) * r.t + player.x;
				r.len.y = sin(r.angle) * r.t + player.y;
				r.transform.x = r.len.x * RECT_W;
				r.transform.y = r.len.y * RECT_H;
				set_pixel(sdl->renderer, (t_color){255, 255, 255}, r.transform.x, r.transform.y);
				if (map[(int)r.len.x + (int)r.len.y * MAP_W] != ' ')
				{
					draw_first_person_view(sdl, t, i);
					break;
				}
				r.t+= 0.1;
			}
			r.curent_pix++;	
		}
		// vec_dir++;
	// }
}
