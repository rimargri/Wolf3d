/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:49:02 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/26 22:55:49 by cvernius         ###   ########.fr       */
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
	raycast(w, t, len, pix, column_angle);
}

void	raycast(t_wolf *w, float t, t_vec2 len, int pix, float column_angle)
{
	t_raycast	r;
	int			column_height;
	t_texture	*texture;
	int			size_texture;
	int			*column;

	r.distance = t;
	r.wall_color = color_of_texture(w, w->map.line[(int)len.x + (int)len.y * w->map.w]);
	if (r.wall_color == -1 || !(check_distance(len, &w->map)))
		return ;
	column_height = (int)(WIN_H / (r.distance * cos(column_angle - w->player.look_column_angle)));
	texture = choice_texture(w, w->map.line[(int)len.x + (int)len.y * w->map.w]);
	if (!(texture) || !(check_distance(len, &w->map)))
		return ;
	size_texture = size_of_texture(len, w, texture);
	column = (int*)malloc(sizeof(int) * column_height);
	((column == NULL) ? exit (99) : 1);
	column = scale_column(w, texture, size_texture, column, column_height);
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
