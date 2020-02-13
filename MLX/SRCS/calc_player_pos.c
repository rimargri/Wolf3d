/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:37:47 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/13 23:30:59 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_player_pos(t_wolf *w, int k)
{
	t_vec2	t;

	if (k == KEY_W)
		t = (t_vec2){0.0, 1.0};
	if (k == KEY_S)
		t = (t_vec2){0.0, -1.0};
	if (k == KEY_D)
		t = (t_vec2){1.0, 0.0};
	if (k == KEY_A)
		t = (t_vec2){-1.0, 0.0};
	w->player.pos.x *= t.x;
	w->player.pos.y *= t.y;
	// x = w->r.vec_dir * (180 / PI);
	// if (x >= 270 && x <= 360 && x >= 0 && x <= 90)
	// 	// move right
	// if (x > 90 && x <= 270)
	// 	// move left
	// if (x > 180 && x <= 270)
	// 	// move 	
}
