/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:46:55 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/20 14:30:34 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_f(t_wolf *w)
{
	t_vec2 forward_base;
	t_vec2 forward;
	t_vec2 tmp;

	forward_base = (t_vec2){0.19f, 0.0f};
	forward.x = forward_base.x * cos(w->player.look_column_angle) - 
	forward_base.y * sin(w->player.look_column_angle);
	forward.y = forward_base.x * sin(w->player.look_column_angle) + 
	forward_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + forward.x;
	tmp.y = w->player.pos.y + forward.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' ')
		return (1);
	else
		return (0);
}

int		check_b(t_wolf *w)
{
	t_vec2 back_base;
	t_vec2 back;
	t_vec2 tmp;

	back_base = (t_vec2){-0.19f, 0.0f};
	back.x = back_base.x * cos(w->player.look_column_angle) - 
	back_base.y * sin(w->player.look_column_angle);
	back.y = back_base.x * sin(w->player.look_column_angle) + 
	back_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + back.x;
	tmp.y = w->player.pos.y + back.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' ')
		return (1);
	else
		return (0);
}

int		check_r(t_wolf *w)
{
	t_vec2 right_base;
	t_vec2 right;
	t_vec2 tmp;

	right_base = (t_vec2){0.0f, 0.19f};
	right.x = right_base.x * cos(w->player.look_column_angle) - 
	right_base.y * sin(w->player.look_column_angle);
	right.y = right_base.x * sin(w->player.look_column_angle) + 
	right_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + right.x;
	tmp.y = w->player.pos.y + right.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' ')
		return (1);
	else
		return (0);
}

int		check_l(t_wolf *w)
{
	t_vec2 left_base;
	t_vec2 left;
	t_vec2 tmp;

	left_base = (t_vec2){0.0f, -0.19f};
	left.x = left_base.x * cos(w->player.look_column_angle) - 
	left_base.y * sin(w->player.look_column_angle);
	left.y = left_base.x * sin(w->player.look_column_angle) + 
	left_base.y * cos(w->player.look_column_angle);
	tmp.x = w->player.pos.x + left.x;
	tmp.y = w->player.pos.y + left.y;
	if (w->map.line[(int)tmp.x + (int)tmp.y * w->map.w] == ' ')
		return (1);
	else
		return (0);
}
