/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:03:09 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 21:25:24 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_view(t_mlx mlx, float t, int i, t_color color)
{
	int column_height;
	t_ivec2 firstpix;
	
	column_height = (int) (WIN_H / t);
	// printf("column_height = %d\n", (int)(WIN_H / t));
	firstpix = (t_ivec2){WIN_W / 2 + i, WIN_H / 2 - column_height / 2};
	draw_rect((t_drawrect){firstpix, color}, 1, column_height, mlx);
}

void	cast_ray(t_wolf *w, char *map)
{
	t_raycast r;

	r = (t_raycast){0, 0, 0, (t_vec2){0.0, 0.0}, (t_ivec2){0, 0}, 0, (t_color){0, 0, 0}};
	while (r.current_pix < WIN_W / 2)
	{
		r.column_angle = w->player.look_column_angle - FOV / 2 + FOV * r.current_pix / (float) (WIN_W / 2);
		r.t = 0.0;
		while (r.t < 23)
		{
			r.len.x = cos(r.column_angle) * r.t + w->player.pos.x; //? Logic
			r.len.y = sin(r.column_angle) * r.t + w->player.pos.y;
			w->player.transform.x = r.len.x * RECT_W;
			w->player.transform.y = r.len.y * RECT_H;
			w->mlx.img[w->player.transform.x + w->player.transform.y * WIN_W] = get_color((t_color){255, 255, 255});	  //? Render
			if (map[(int)r.len.x + (int)r.len.y * MAP_W] != ' ')
			{
				r.color = raycast_color(r, map);
				draw_view(w->mlx, r.t, r.current_pix, r.color); //? Render
				break;
			}
			r.t += 0.1;
		}
		r.current_pix++;	
	}
}
