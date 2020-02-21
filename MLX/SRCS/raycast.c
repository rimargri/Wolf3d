/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:13:24 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 20:53:19 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	find_distance(t_wolf *w, int pix)
{
	float	t;
	float	column_angle;
	t_vec2	len;

	t = 0.0f;
	column_angle = w->player.look_column_angle - FOV / 2 + FOV * pix /
														(float)(WIN_W / 2);
	while (t < 100)
	{
		len.x = cos(column_angle) * t + w->player.pos.x; //? Logic
		len.y = sin(column_angle) * t + w->player.pos.y;
		if (len.x >= w->map.w || len.y > w->map.h || len.x < 0 || len.y < 0)
			break ;
		if (w->map.line[(int)len.x + (int)len.y * w->map.w] != ' ')
				break;
		t += 0.01;
	}
	raycast(w, t, len, pix);
}

void	raycast(t_wolf *w, float t, t_vec2 len, int pix)
{
	t_raycast	r;
	int			column_height;
	t_ivec2		firstpix;

	r.distance = t;
	r.wall_color = (t_color)wall_color(&w->map, len);
	if (r.wall_color.r == -1 && r.wall_color.g == -1 && r.wall_color.b == -1)
		return ;
	column_height = (int)(WIN_H / r.distance);
	firstpix.x = (int){WIN_W / 2 + pix};
	firstpix.y = (int){WIN_H / 2 - column_height / 2};
	draw_rect((t_drawrect){firstpix, r.wall_color}, 1, column_height, w);
}

void	render_walls(t_wolf *w)
{
	int current_pix;

	current_pix = 0;
	while (current_pix < WIN_W / 2)
	{
		find_distance(w, current_pix);
		current_pix++;
	}
}
