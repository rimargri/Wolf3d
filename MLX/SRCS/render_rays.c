/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:59:21 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 18:13:57 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_rays(t_wolf *w, int pix)
{
	float	t;
	float	column_angle;
	t_vec2	len;

	t = 0.0f;
	column_angle = w->player.look_column_angle - FOV / 2 + FOV * pix /
														(float)(WIN_W / 2);
	while (t < 23)
	{
		len.x = cos(column_angle) * t + w->player.pos.x; //? Logic
		len.y = sin(column_angle) * t + w->player.pos.y;
		if (len.x > MAP_W || len.y > MAP_H || len.x < 0 || len.y < 0)
		{
			break ;
		}
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
		t += 0.1;
	}
}

void	render_rays(t_wolf *w)
{
	int current_pix;

	current_pix = 0;
	while (current_pix < WIN_W / 2)
	{
		draw_rays(w, current_pix);
		current_pix++;
	}
}
