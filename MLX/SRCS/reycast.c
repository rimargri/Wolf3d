/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:03:09 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/13 23:39:36 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** vec_dir - direction vector
** move clockwise
*/

void	draw_view(t_mlx mlx, float t, int i, t_color color)
{
	int column_height;
	t_ivec2 first_pix;

	column_height = (int) (WIN_H / t);
	// printf("column_height = %d\n", (int)(WIN_H / t));
	first_pix = (t_ivec2){WIN_W / 2 + i, WIN_H / 2 - column_height / 2};
	draw_rect(first_pix, 1, column_height, color, mlx);
}

t_reycast	raycast_data(t_reycast r, t_wolf *w)
{
	r.player = w->player;
	// r.vec_dir = 1.9;
	r.transform = (t_ivec2){0, 0};
	r.len = (t_vec2){0, 0};
	r.current_pix = 0;
	return (r);
}

t_color	reycast_color(t_reycast r, t_map map)
{
	if (map.line[(int)r.len.x + (int)r.len.y * map.w] == '0')					// pirple
		r.color = (t_color){153, 113, 233};
	if (map.line[(int)r.len.x + (int)r.len.y * map.w] == '1')
		r.color = (t_color){227, 176, 229};									// pink
	if (map.line[(int)r.len.x + (int)r.len.y * map.w] == '2')
		r.color = (t_color){92, 147, 255};									// blue
	if (map.line[(int)r.len.x + (int)r.len.y * map.w] == '3')
		r.color = (t_color){176, 229, 193};									// green
	return (r.color);
}

void	init_reycast(t_wolf *wolf)
{
	t_reycast	r;
	
	wolf->r.vec_dir = 0.0;
	wolf->r = r;
}

void	cast_ray(t_reycast r, t_wolf *w, t_map map)
{
	r = raycast_data(r, w);
	while (r.current_pix < WIN_W / 2)
	{
		r.angle = r.vec_dir - FOV / 2 + FOV * r.current_pix / (float) (WIN_W / 2);
		r.t = 0.0;
		while (r.t < 20)
		{
			r.len.x = cos(r.angle) * r.t + r.player.pos.x; //? Logic
			r.len.y = sin(r.angle) * r.t + r.player.pos.y;
			r.transform.x = r.len.x * RECT_W;
			r.transform.y = r.len.y * RECT_H;
			mlx_pixel_put(w->mlx.mptr, w->mlx.wptr, r.transform.x, r.transform.y, get_color((t_color){255, 255, 255})); //? Render
			if (map.line[(int)r.len.x + (int)r.len.y * map.w] != ' ')
			{
				r.color = reycast_color(r, map);
				draw_view(w->mlx, r.t, r.current_pix, r.color); //? Render
				break;
			}
			r.t += 0.1;
		}
		r.current_pix++;	
	}
}
