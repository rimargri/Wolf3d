/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:34 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 19:09:17 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**
** key_space	-		show radar or no
**
**		*** move of player ***
**
** arrow let	-		rotation player on left
** arrow right	-		rotation player on right
** key_w		-		move up
** key_s		-		move down
** key_a		-		move_left
** key_d		-		move right
*/

void	player_move(t_wolf *w, t_direction *direction)
{
	if (direction->move_f != FAULSE)
		move_forward(w);
	if (direction->move_b != FAULSE)
		move_back(w);
	if (direction->move_r != FAULSE)
		move_right(w);
	if (direction->move_l != FAULSE)
		move_left(w);
}

int		key_unpress(int k, t_wolf *w)
{
	if (k == KEY_ARROW_RIGHT)
		w->direction.camera = 0;
	else if (k == KEY_ARROW_LEFT)
		w->direction.camera = 0;
	else
	{
		w->direction.move_l = k == KEY_A ? FAULSE : w->direction.move_l;
		w->direction.move_r = k == KEY_D ? FAULSE : w->direction.move_r;
		w->direction.move_f = k == KEY_W ? FAULSE : w->direction.move_f;
		w->direction.move_b = k == KEY_S ? FAULSE : w->direction.move_b;
	}
	return (0);
}

int		key_press(int k, t_wolf *w)
{
	(k == KEY_ESC ? exit(0) : 1);

	if (k == KEY_W)
		w->direction.move_f = KEY_W;
	else if (k == KEY_S)
		w->direction.move_b = KEY_S;
	else if (k == KEY_D)
		w->direction.move_r = KEY_D;
	else if (k == KEY_A)
		w->direction.move_l = KEY_A;
	else if  (k == KEY_ARROW_RIGHT)
		w->direction.camera = KEY_ARROW_RIGHT;
	else if (k == KEY_ARROW_LEFT)
		w->direction.camera = KEY_ARROW_LEFT;
	else if (k == KEY_SPACE)
			w->space_was_pressed = !(w->space_was_pressed);
	return (0);
}

int		close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
