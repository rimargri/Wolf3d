/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:12:54 by hchau             #+#    #+#             */
/*   Updated: 2020/03/08 22:27:00 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	full_column_texture_mirr(t_wolf *w, int *column,
								int column_height, t_ivec2 offset)
{
	int		y;
	t_ivec2	pix;
	int		mask;
	int		l_y;

	pix.x = w->layers->map_view.on == TRUE ? offset.x + WIN_W / 2 : offset.x;
	mask = (w->dem->mirr->intence * 5) << 24;
	pix.y = column_height;
	l_y = 0;
	y = offset.y;
	while (l_y < offset.y)
	{
		pix.y = l_y + column_height + WIN_H / 2 - column_height / 2;
		if (pix.y >= 0 && pix.y < WIN_H)
			w->layers->d_labyrinth.img[pix.x + pix.y * WIN_W] =
														column[y] | mask;
		y--;
		l_y++;
	}
}

void	full_column_texture_mode(t_wolf *w, int *column,
								int column_height, t_ivec2 offset)
{
	int		y;
	t_ivec2	pix;

	pix.x = w->layers->map_view.on == TRUE ? offset.x + WIN_W / 2 : offset.x;
	pix.y = 0;
	y = 0;
	while (y < column_height)
	{
		pix.y = y + WIN_H / 2 + offset.y - column_height / 2;
		if (pix.y >= 0 && pix.y < WIN_H)
			w->layers->d_labyrinth.img[pix.x + pix.y * WIN_W] = column[y];
		y++;
	}
}

int		find_offset(t_raycast r, t_wolf *w)
{
	float	z;
	float	angle;
	int		y;

	angle = w->player.look_column_angle.y;
	z = r.distance;
	y = r.len.y;
	z = z * cos(angle) * (w->dem->wave->intence) -
			y * sin(angle) * (w->dem->wave->intence);
	y = z * sin(angle) + r.len.x * cos(angle);
	if (w->player.move.jump_h > 0)
		y += w->player.move.camera_up * 50;
	if (w->dem->norm->on == TRUE)
		return (w->player.move.camera_up * 50);
	return (y);
}

void	raycast_mirr(t_wolf *w, t_raycast r, int pix, float column_angle)
{
	t_ivec2		xy_offset;
	int			column_height;
	int			*column;

	xy_offset.y = find_offset(r, w);
	xy_offset.x = pix;
	column_height = (int)(WIN_H / (r.distance *
				cos(column_angle / 2 - w->player.look_column_angle.x / 2)));
	r.t = choice_drawing_texture(w, r.len);
	if (!(r.t) || !(check_distance(r.len, &w->map)))
		return ;
	xy_offset.y = xy_offset.y + 10 > column_height ?
					column_height + 10 : xy_offset.y + 30;
	column = (int*)malloc(sizeof(int) * (xy_offset.y + 1));
	((column == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	column = scale_column(r, column, xy_offset.y + 1);
	full_column_texture_mirr(w, column, column_height, xy_offset);
	free(column);
	column = NULL;
	column = (int*)malloc(sizeof(int) * (column_height + 1));
	((column == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	column = scale_column(r, column, column_height + 1);
	full_column_texture(w, column, column_height, pix);
	free(column);
	column = NULL;
}

void	raycast_modes_text(t_wolf *w, t_raycast r, int pix, float column_angle)
{
	t_ivec2		xy_offset;
	int			column_height;
	int			*column;

	xy_offset.y = find_offset(r, w);
	xy_offset.x = pix;
	column_height = (int)(WIN_H / (r.distance *
			cos(column_angle / 2 - w->player.look_column_angle.x / 2)));
	r.t = choice_drawing_texture(w, r.len);
	if (!(r.t) || !(check_distance(r.len, &w->map)))
		return ;
	if (w->dem->mirr->on == TRUE)
	{
		if (w->player.move.jump_h > 0)
			raycast_mirr_jump(w, r, pix, column_angle);
		else
			raycast_mirr(w, r, pix, column_angle);
		return ;
	}
	column = (int*)malloc(sizeof(int) * column_height);
	((column == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	column = scale_column(r, column, column_height);
	full_column_texture_mode(w, column, column_height, xy_offset);
	free(column);
	column = NULL;
}
