/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:37:47 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 21:32:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_forward(t_wolf *w)
{
	t_vec2 forward_base;
	t_vec2 forward;

	forward_base = (t_vec2){0.1f, 0.0f};
	forward.x = forward_base.x * cos(w->player.look_column_angle) - 
	forward_base.y * sin(w->player.look_column_angle);
	forward.y = forward_base.x * sin(w->player.look_column_angle) + 
	forward_base.y * cos(w->player.look_column_angle);
	w->player.pos.x += forward.x;
	w->player.pos.y += forward.y;
}

void	move_back(t_wolf *w)
{
	t_vec2 back_base;
	t_vec2 back;

	back_base = (t_vec2){-0.1f, 0.0f};
	back.x = back_base.x * cos(w->player.look_column_angle) - 
	back_base.y * sin(w->player.look_column_angle);
	back.y = back_base.x * sin(w->player.look_column_angle) + 
	back_base.y * cos(w->player.look_column_angle);
	w->player.pos.x += back.x;
	w->player.pos.y += back.y;
}

void	move_right(t_wolf *w)
{
	t_vec2 right_base;
	t_vec2 right;

	right_base = (t_vec2){0.0f, 0.1f};
	right.x = right_base.x * cos(w->player.look_column_angle) - 
	right_base.y * sin(w->player.look_column_angle);
	right.y = right_base.x * sin(w->player.look_column_angle) + 
	right_base.y * cos(w->player.look_column_angle);
	w->player.pos.x += right.x;
	w->player.pos.y += right.y;
}

void	move_left(t_wolf *w)
{
	t_vec2 left_base;
	t_vec2 left;

	left_base = (t_vec2){0.0f, -0.1f};
	left.x = left_base.x * cos(w->player.look_column_angle) - 
	left_base.y * sin(w->player.look_column_angle);
	left.y = left_base.x * sin(w->player.look_column_angle) + 
	left_base.y * cos(w->player.look_column_angle);
	w->player.pos.x += left.x;
	w->player.pos.y += left.y;
}
