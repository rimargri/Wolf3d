/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:34 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 21:47:54 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** arrow let	-	rotation player on left
** arrow right	-	rotation player on right
**
**		*** move of player ***
**
** key_w		-		move up
** key_s		-		move down
** key_a		-		move_left
** key_d		-		move right
*/

void	player_move(t_wolf *w, int k)
{
	if (k == KEY_W)
		move_forward(w);
	if (k == KEY_S)
		move_back(w);
	if (k == KEY_D)
		move_right(w);
	if (k == KEY_A)
		move_left(w);
}

int		key_press(int k, t_wolf *w)
{
	(k == KEY_ESC ? exit(0) : 1);
	(k == KEY_ARROW_LEFT ? w->player.look_column_angle += 0.1 : 1);
	(k == KEY_ARROW_RIGHT ? w->player.look_column_angle -= 0.1 : 1);
	((k == KEY_W || k == KEY_S || k == KEY_D || k == KEY_A) ? (player_move(w, k)) : 1);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	// printf("key_press---pos.x = %d, pos.y = %d\n", w->player.pos.x, w->player.pos.y);
	draw_background(w);
	draw_walls(w, w->map);
	draw_player(w);
	cast_ray(w, w->map);
	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->mlx.iptr, 0, 0);
	return (0);
}

int		close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
