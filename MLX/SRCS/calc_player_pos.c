/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:37:47 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 00:06:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_player_pos(t_wolf *w, int k)
{
	// t_vec2	t;
	
	// printf("calc_player_pos-B-column_angle =   %f  \nw->r.player.pos.x == %d\n", w->r.column_angle, w->player.pos.x);
	if (k == KEY_W)
	{
		t_vec2 forward_base = {0.1f, 0.0f};
		t_vec2 forward;
		forward.x = forward_base.x * cos(w->r.player_column_angle) - forward_base.y * sin(w->r.player_column_angle);
		forward.y = forward_base.x * sin(w->r.player_column_angle) + forward_base.y * cos(w->r.player_column_angle);
		w->player.pos.x += forward.x;
		w->player.pos.y += forward.y;
	}
	w->r.player = w->player;
}

	// if (k == KEY_W)
	// {
	// 	w->r.player.pos.x += w->r.v.x;
	// 	w->r.player.pos.y += w->r.v.y;
	// }
	// if (k == KEY_S)
	// {
	// 	w->r.player.pos.x -= w->r.v.x;
	// 	w->r.player.pos.y -= w->r.v.y;
	// }
	// if (k == KEY_D)
	// {
	// 	w->r.player.pos.x += w->r.v.x;
	// 	w->r.player.pos.y = w->r.player.pos.y;
	// }
	// if (k == KEY_A)
	// {
	// 	w->r.player.pos.x -= w->r.v.x;
	// 	w->r.player.pos.y = w->r.player.pos.y;
	// }