/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:54:41 by hchau             #+#    #+#             */
/*   Updated: 2020/03/08 21:54:47 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		find_offset_jump(t_raycast r, t_wolf *w)
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
	y += w->player.move.camera_up * 5;
	return (y);
}

static void		get_first_part(t_wolf *w, t_raycast r,
								t_ivec2 xy_offset, float column_angle)
{
	int		column_height;
	int		*column;

	column_height = (int)(WIN_H / (r.distance *
			cos(column_angle / 2 - w->player.look_column_angle.x / 2)));
	column = (int*)malloc(sizeof(int) * (column_height + 1));
	((column == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	column = scale_column(r, column, column_height + 1);
	full_column_texture_mode(w, column, column_height, xy_offset);
	free(column);
	column = NULL;
}

void			raycast_mirr_jump(t_wolf *w, t_raycast r,
									int pix, float column_angle)
{
	t_ivec2		xy_offset;
	int			column_height;
	int			*column;

	xy_offset.y = find_offset(r, w);
	xy_offset.x = pix;
	r.t = choice_drawing_texture(w, r.len);
	if (!(r.t) || !(check_distance(r.len, &w->map)))
		return ;
	column_height = (int)(WIN_H / (r.distance *
			cos(column_angle / 2 - w->player.look_column_angle.x / 2)));
	get_first_part(w, r, xy_offset, column_angle);
	xy_offset.y = find_offset_jump(r, w);
	xy_offset.y = xy_offset.y + 10 > column_height ?
			column_height + 10 : xy_offset.y + 30;
	column = (int*)malloc(sizeof(int) * (xy_offset.y + 1));
	((column == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	column = scale_column(r, column, xy_offset.y + 1);
	column_height += w->player.move.camera_up * 100;
	full_column_texture_mirr(w, column, column_height, xy_offset);
	free(column);
	column = NULL;
}

void			jump(t_wolf *w)
{
	if (w->player.move.jump == STARTED)
	{
		w->player.move.jump_h = w->player.move.jump_h >= NORMAL_HEIGHT ?
				w->player.move.jump_h + 1 : NORMAL_HEIGHT;
	}
	if (w->player.move.jump == 0 || w->player.move.jump == STARTED)
		return ;
	if (w->player.move.jump_h > w->player.move.jump)
	{
		w->player.move.jump_h--;
		w->player.move.camera_up += 0.2;
	}
	else if (w->player.move.camera_up > 0.0 && w->player.move.jump_h != 0)
		w->player.move.camera_up -= 0.2;
	else
	{
		w->player.move.jump_h = 0;
		w->player.move.jump = 0;
	}
}
