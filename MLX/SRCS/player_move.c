/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:37:47 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/20 16:01:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	player_move(t_wolf *w)
{
	if (w->player.move.forward != FALSE)
		move_forward(w);
	if (w->player.move.back != FALSE)
		move_back(w);
	if (w->player.move.right != FALSE)
		move_right(w);
	if (w->player.move.left != FALSE)
		move_left(w);
}

void	move_forward(t_wolf *w)
{
	t_vec2 forward_base;
	t_vec2 forward;
	t_vec2 tmp;

//	if (w->layers->map_view.on == TRUE)
//	forward_base = (t_vec2){0.04f, 0.0f};
//	else
		forward_base = (t_vec2){0.04f, 0.0f};
	forward.x = forward_base.x * cos(w->player.look_column_angle.x) -
	forward_base.y * sin(w->player.look_column_angle.x);
	forward.y = forward_base.x * sin(w->player.look_column_angle.x) +
	forward_base.y * cos(w->player.look_column_angle.x);
	tmp.x = w->player.pos.x + forward.x;
	tmp.y = w->player.pos.y + forward.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' '
	&& (int)tmp.x < w->map.w && (int)tmp.y < w->map.h
	&& tmp.x >= 0 && tmp.y >= 0
	&& check_f(w) == 1)
	{
		w->player.pos.x += forward.x;
		w->player.pos.y += forward.y;
	}
}

void	move_back(t_wolf *w)
{
	t_vec2 back_base;
	t_vec2 back;
	t_vec2 tmp;

	back_base = (t_vec2){-0.04f, 0.0f};
	back.x = back_base.x * cos(w->player.look_column_angle.x) -
	back_base.y * sin(w->player.look_column_angle.x);
	back.y = back_base.x * sin(w->player.look_column_angle.x) +
	back_base.y * cos(w->player.look_column_angle.x);
	tmp.x = w->player.pos.x + back.x;
	tmp.y = w->player.pos.y + back.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' '
	&& (int)tmp.x < w->map.w && (int)tmp.y < w->map.h
	&& tmp.x >= 0 && tmp.y >= 0
	&& check_b(w) == 1)
	{
		w->player.pos.x += back.x;
		w->player.pos.y += back.y;
	}
}

void	move_right(t_wolf *w)
{
	t_vec2 right_base;
	t_vec2 right;
	t_vec2 tmp;

	right_base = (t_vec2){0.0f, 0.04f};
	right.x = right_base.x * cos(w->player.look_column_angle.x) -
	right_base.y * sin(w->player.look_column_angle.x);
	right.y = right_base.x * sin(w->player.look_column_angle.x) +
	right_base.y * cos(w->player.look_column_angle.x);
	tmp.x = w->player.pos.x + right.x;
	tmp.y = w->player.pos.y + right.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' '
	&& (int)tmp.x < w->map.w && (int)tmp.y < w->map.h
	&& tmp.x >= 0 && tmp.y >= 0
	&& check_r(w) == 1)
	{
		w->player.pos.x += right.x;
		w->player.pos.y += right.y;
	}
}

void	move_left(t_wolf *w)
{
	t_vec2 left_base;
	t_vec2 left;
	t_vec2 tmp;

	left_base = (t_vec2){0.0f, -0.04f};
	left.x = left_base.x * cos(w->player.look_column_angle.x) -
	left_base.y * sin(w->player.look_column_angle.x);
	left.y = left_base.x * sin(w->player.look_column_angle.x) +
	left_base.y * cos(w->player.look_column_angle.x);
	tmp.x = w->player.pos.x + left.x;
	tmp.y = w->player.pos.y + left.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' '
	&& (int)tmp.x < w->map.w && (int)tmp.y < w->map.h
	&& tmp.x >= 0 && tmp.y >= 0
	&& check_l(w) == 1)
	{
		w->player.pos.x += left.x;
		w->player.pos.y += left.y;
	}
}
