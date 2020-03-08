/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:49:02 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 22:47:30 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_distance(t_vec2 len, t_map *map)
{
	if ((int)len.x >= map->w || (int)len.x < 0 ||
		(int)len.y >= map->h || (int)len.y < 0 ||
		map->line[(int)len.x + (int)len.y * map->w] == ' ')
		return (0);
	return (1);
}

void	find_distance(t_wolf *w, int pix, int w_w, int delim)
{
	t_raycast	r;
	float		column_angle;

	r.distance = 0.0f;
	r.len = (t_vec2){0.0f, 0.0f};
	column_angle = (w->player.look_column_angle.x + w->layers->draw_shift)
									- FOV / delim + FOV * pix / (float)(w_w);
	while (r.distance < 100)
	{
		r.len.x = cos(column_angle) * r.distance + w->player.pos.x;
		r.len.y = sin(column_angle) * r.distance + w->player.pos.y;
		if (r.len.x >= w->map.w || r.len.y > w->map.h || r.len.x < 0 ||
															r.len.y < 0)
			break ;
		if (w->map.line[(int)r.len.x + (int)r.len.y * w->map.w] != ' ')
			break ;
		r.distance += 0.02;
	}
	if (w->dem->norm->on != TRUE)
		raycast_modes_text(w, r, pix, column_angle);
	else
		raycast(w, r, pix, column_angle);
}

void	raycast(t_wolf *w, t_raycast r, int pix, float column_angle)
{
	int			column_height;
	int			*column;

	column_height = (int)(WIN_H / (r.distance *
				cos(column_angle / 2 - w->player.look_column_angle.x / 2)));
	r.t = cardinal_points(w, r.len);
	if (!(r.t) || !(check_distance(r.len, &w->map)))
		return ;
	column = (int*)malloc(sizeof(int) * column_height);
	((column == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	column = scale_column(r, column, column_height);
	full_column_texture(w, column, column_height, pix);
}

void	render_walls(t_wolf *w)
{
	int current_pix;
	int	wall_w;
	int	delim;
	int	move_delim;

	current_pix = 0;
	wall_w = w->layers->map_view.on == TRUE ? WIN_W / 2 : WIN_W;
	delim = w->layers->map_view.on == TRUE ? 1 : 2;
	move_delim = w->layers->map_view.on == TRUE ? 2 : 1;
	while (current_pix < wall_w)
	{
		find_distance(w, current_pix, wall_w / delim, move_delim);
		current_pix++;
	}
}
