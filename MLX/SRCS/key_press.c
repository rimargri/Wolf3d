/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:34 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/13 23:42:28 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int k, t_wolf *w)
{
	(k == KEY_ESC ? exit(0) : 1);
	// (k == KEY_1 ? w->r->vec_dir += 0.0037 : 1);
	(k == KEY_1 ? w->r.vec_dir += 0.1 : 1);
	(k == KEY_2 ? w->r.vec_dir -= 0.1 : 1);
	(k == (KEY_W || KEY_S || KEY_D || KEY_A) ? (calc_player_pos(w, k)) : 1);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	draw_background(w);
	draw_walls(w, w->tmap);
	draw_player(w);
	cast_ray(w->r, w, w->tmap);
	return (0);
}

int		close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
