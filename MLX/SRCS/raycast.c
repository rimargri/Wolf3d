/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:13:24 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/20 16:59:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//__FIXX_IMMIDEATLEY Непонятный код

#include "wolf3d.h"
#define PUT_SECOND 10

void	find_distance(t_wolf *w, int pix, int w_w, int delim)
{
	float	t;
	t_vec2	column_angle;
	t_vec2	len;
	float	z = 0;
	float	y_offset;

	t = 0.0f;
	column_angle.x = (w->player.look_column_angle.x + w->layers->draw_shift) - FOV / delim + FOV * pix /
														(float)(w_w);
	column_angle.y = w->player.look_column_angle.y;
	while (t < 100)
	{
		z = t;
		len.x = cos(column_angle.x) * z + w->player.pos.x;
		len.y = sin(column_angle.x) * z + w->player.pos.y;
		if (len.x >= w->map.w || len.y > w->map.h || len.x < 0 || len.y < 0)
			break ;
		if (w->map.line[(int)len.x + (int)len.y * w->map.w] != ' ')
				break;
		t += 0.01;
	}
	z = z * cos(column_angle.y) * (w->dem->wave->intence) - len.y * sin(column_angle.y) * (w->dem->wave->intence);
	y_offset = z * sin(column_angle.y) + len.x * cos(column_angle.y);
	if (w->dem->norm->on == FALSE && w->dem->mirr->on != PUT_SECOND)
		raycast(w, t, len, pix, (int)(y_offset) + (w->player.move.camera_up * 300));
	else
		raycast(w, t, len, pix, (w->player.move.camera_up * 300));
}

void	raycast(t_wolf *w, float t, t_vec2 len, int pix, int y_offset)
{
	t_raycast	r;
	int			column_height;
	t_ivec2		firstpix;
	int	wall_w;

	r.distance = t;
	wall_w = w->layers->map_view.on == TRUE ? WIN_W / 2 : WIN_W;
	r.wall_color = (t_color)wall_color(&w->map, len);
	if (r.wall_color.r == -1 && r.wall_color.g == -1 && r.wall_color.b == -1)
		return ;
	column_height = (int)(WIN_H / r.distance);
	firstpix.x = (int){wall_w + pix};
	firstpix.y = (int){WIN_H / 2 - column_height / 2};
	draw_rect((t_drawrect){firstpix, r.wall_color}, 1, column_height, &w->layers->d_labyrinth, y_offset);
}

void	render_walls(t_wolf *w)
{
	int	wall_w;
	int	delim;
	int	move_delim;
	int current_pix;//__FIXX_IMMIDEATLEY чтобы вместиться в норму, можно сделать t_ivec2

	current_pix = 0;
//	if (w->layers->map_view.on == TRUE)
//	{
//	}
	wall_w = w->layers->map_view.on == TRUE ? WIN_W / 2 : WIN_W;
	delim = w->layers->map_view.on == TRUE ? 1 : 2;
	move_delim = w->layers->map_view.on == TRUE ? 2 : 1;
	while (current_pix < wall_w)
	{
		find_distance(w, current_pix, wall_w / delim, move_delim);
		current_pix++;
	}
	if (w->dem->mirr->on != FALSE)
	{
		w->dem->mirr->on = PUT_SECOND;
		current_pix = 0;
		put_color_mask(&w->layers->d_labyrinth, 0xAA000000, WIN_W, WIN_H * 2);
		while (current_pix < wall_w)
		{
			find_distance(w, current_pix, wall_w / delim, move_delim);
			current_pix++;
		}
		w->dem->mirr->on = TRUE;
	}
}
