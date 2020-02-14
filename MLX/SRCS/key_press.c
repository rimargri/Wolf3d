/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:34 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 00:05:49 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int k, t_wolf *w)
{
	(k == KEY_ESC ? exit(0) : 1);
	// (k == KEY_1 ? w->r->player_column_angle += 0.0037 : 1);
	(k == KEY_2 ? w->r.player_column_angle += 0.1 : 1);
	(k == KEY_1 ? w->r.player_column_angle -= 0.1 : 1);
	// printf("key_press---pos.x = %d, pos.y = %d\n", w->player.pos.x, w->player.pos.y);
	((k == KEY_W || k == KEY_S || k == KEY_D || k == KEY_A) ? (calc_player_pos(w, k)) : 1);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	// printf("key_press---pos.x = %d, pos.y = %d\n", w->player.pos.x, w->player.pos.y);
	draw_background(w);
	draw_walls(w, w->map);
	draw_player(w);
	cast_ray(w->r, w, w->map);
	return (0);
}

int		close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
