/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:13:24 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/18 23:11:53 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_ray(t_wolf *w, int pix)
{
	float	t;
	float	column_angle;
	t_vec2	len;

	t = 0.0f;
	column_angle = w->player.look_column_angle - FOV / 2 + FOV * pix /
														(float)(WIN_W / 2);
	while (t < 23)
		// && w->player.transform.x < WIN_W / 2 && w->player.transform.y < WIN_H
		// && w->player.transform.x >= 0 && w->player.transform.y >= 0)
	{
		len.x = cos(column_angle) * t + w->player.pos.x; //? Logic
		len.y = sin(column_angle) * t + w->player.pos.y;
		w->player.transform.x = len.x * RECT_W;
		w->player.transform.y = len.y * RECT_H;
		if (!w->space_was_pressed && len.x < MAP_W 
								  && len.y < MAP_H
								  && w->player.transform.x < WIN_W / 2
								  && w->player.transform.y < WIN_H
								  && w->player.transform.x >= 0
								  && w->player.transform.y >= 0)
			w->mlx.img[w->player.transform.x + w->player.transform.y * WIN_W]
										= get_color((t_color){255, 255, 255});
		if (w->map[(int)len.x + (int)len.y * MAP_W] != ' ')
				break;
		t += 0.01;
	}
	printf("t = %f\n", t);
	// if (w->map[(int)len.x + (int)len.y * MAP_W] != ' ' && !(t == 23)
		raycast(w, t, len, pix);
}

void	raycast(t_wolf *w, float t, t_vec2 len, int pix)
{
	t_raycast	r;
	int			column_height;
	t_ivec2		firstpix;

	r.distance = t;
	r.wall_color = (t_color)wall_color(w->map, len);
	column_height = (int)(WIN_H / r.distance);
	firstpix.x = (int){WIN_W / 2 + pix};
	firstpix.y = (int){WIN_H / 2 - column_height / 2};
	draw_rect((t_drawrect){firstpix, r.wall_color}, 1, column_height, w->mlx);
}

void	render(t_wolf *w)
{
	int current_pix;

	current_pix = 0;
	while (current_pix < WIN_W / 2)
	{
		draw_ray(w, current_pix);
		current_pix++;
	}
}
