/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:37:47 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/18 22:41:05 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

	//!! ДОБАВИТЬ ограничение на выход из карты, если там дырка, а не стена

void	move_forward(t_wolf *w)
{
	t_vec2 forward_base;
	t_vec2 forward;
	t_vec2 tmp;

	forward_base = (t_vec2){0.05f, 0.0f};
	forward.x = forward_base.x * cos(w->player.look_column_angle) - 
	forward_base.y * sin(w->player.look_column_angle);
	forward.y = forward_base.x * sin(w->player.look_column_angle) + 
	forward_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + forward.x;
	tmp.y = w->player.pos.y + forward.y;
	// printf("(int)tmp.x + (int)tmp.y * MAP_W ==  %d\n", (int)tmp.x + (int)tmp.y * MAP_W);
	// printf("w->player.pos.x = %f\n", w->player.pos.x);
	if (w->map[(int)tmp.x + (int)tmp.y * MAP_W] == ' ' && ((int)tmp.x < MAP_W) && ((int)tmp.y < MAP_H)
	&& (tmp.x >= 0) && (tmp.y >= 0)) // && )
	{
		w->player.pos.x += forward.x;
		w->player.pos.y += forward.y;
	}
	// printf("%d\n", w->map[(int)tmp.x + (int)tmp.y * MAP_W] == ' ');
}

void	move_back(t_wolf *w)
{
	t_vec2 back_base;
	t_vec2 back;
	t_vec2 tmp;

	back_base = (t_vec2){-0.05f, 0.0f};
	back.x = back_base.x * cos(w->player.look_column_angle) - 
	back_base.y * sin(w->player.look_column_angle);
	back.y = back_base.x * sin(w->player.look_column_angle) + 
	back_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + back.x;
	tmp.y = w->player.pos.y + back.y;
	if (w->map[(int)tmp.x + (int)tmp.y * MAP_W] == ' ' && ((int)tmp.x < MAP_W) && ((int)tmp.y < MAP_H)
	&& (tmp.x >= 0) && (tmp.y >= 0)) // && )
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

	right_base = (t_vec2){0.0f, 0.05f};
	right.x = right_base.x * cos(w->player.look_column_angle) - 
	right_base.y * sin(w->player.look_column_angle);
	right.y = right_base.x * sin(w->player.look_column_angle) + 
	right_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + right.x;
	tmp.y = w->player.pos.y + right.y;
	if (w->map[(int)tmp.x + (int)tmp.y * MAP_W] == ' ' && ((int)tmp.x < MAP_W) && ((int)tmp.y < MAP_H)
	&& (tmp.x >= 0) && (tmp.y >= 0)) // && )
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

	left_base = (t_vec2){0.0f, -0.05f};
	left.x = left_base.x * cos(w->player.look_column_angle) - 
	left_base.y * sin(w->player.look_column_angle);
	left.y = left_base.x * sin(w->player.look_column_angle) + 
	left_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + left.x;
	tmp.y = w->player.pos.y + left.y;
	if (w->map[(int)tmp.x + (int)tmp.y * MAP_W] == ' ' && ((int)tmp.x < MAP_W) && ((int)tmp.y < MAP_H)
	&& (tmp.x >= 0) && (tmp.y >= 0)) // && )
	{
		w->player.pos.x += left.x;
		w->player.pos.y += left.y;
	}
}
