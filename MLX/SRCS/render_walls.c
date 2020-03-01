/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:49:02 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/01 23:02:55 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_distance(t_vec2 len, t_map *map)
{
	if ((int)len.x >= map->w || (int)len.x < 0 ||
		(int)len.y >= map->h || (int)len.y < 0)
			return (0);
	return (1);
}

void	find_distance(t_wolf *w, int pix)
{
	t_raycast	r;
	float		column_angle;

	r.distance = 0.0f;
	r.len = (t_vec2){0.0f, 0.0f};
	column_angle = w->player.look_column_angle - FOV / 2 + FOV * pix /
														(float)(WIN_W / 2);
	while (r.distance < 100)
	{
		r.len.x = cos(column_angle) * r.distance + w->player.pos.x;
		r.len.y = sin(column_angle) * r.distance + w->player.pos.y;
		if (r.len.x >= w->map.w || r.len.y > w->map.h || r.len.x < 0 || r.len.y < 0)
			break ;
		if (w->map.line[(int)r.len.x + (int)r.len.y * w->map.w] != ' ')
				break;
		r.distance += 0.01;
	}
	raycast(w, r, pix, column_angle);
}

void	raycast(t_wolf *w, t_raycast r, int pix, float column_angle)
{
	int			column_height;
	int			*column;

	column_height = (int)(WIN_H / (r.distance * cos(column_angle - w->player.look_column_angle)));
	// r.t = choice_texture(w, w->map.line[(int)r.len.x + (int)r.len.y * w->map.w]);
	r.t = cardinal_points(w, r.len);
	if (!(r.t) || !(check_distance(r.len, &w->map)))
		return ;
	column = (int*)malloc(sizeof(int) * column_height);
	((column == NULL) ? exit (99) : 1);
	column = scale_column(r, column, column_height);
	full_column_texture(w, column, column_height, pix);
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
