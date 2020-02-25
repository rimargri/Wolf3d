/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_25_02_20.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:49:02 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/25 23:21:38 by cvernius         ###   ########.fr       */
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
                // continue;
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
	r.wall_color = wall_color(&w->map, len);
	((r.wall_color == -1) ? (exit(99)) : 1);
	column_height = (int)(WIN_H / (r.distance * cos(column_angle - w->player.look_column_angle)));
    printf("col_height = %d\n", column_height);
	texture = choice_texture(w, w->map.line[(int)len.x + (int)len.y * w->map.w]);
	printf("texture->id = %d\tsize = %d\n", texture->id, texture->size);
	size_texture = size_of_texture(len, w, texture);
	printf("size_texture = %d\n", size_texture);
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