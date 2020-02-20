/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:34 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 22:36:19 by cvernius         ###   ########.fr       */
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

void	player_move(t_wolf *w, t_direction *move)
{
	if (move->forward != FAULSE)
		move_forward(w);
	if (move->back != FAULSE)
		move_back(w);
	if (move->right != FAULSE)
		move_right(w);
	if (move->left != FAULSE)
		move_left(w);
}

int		key_unpress(int k, t_wolf *w)
{
	if (k == KEY_ARROW_RIGHT)
		w->move.camera = 0;
	else if (k == KEY_ARROW_LEFT)
		w->move.camera = 0;
	else
	{
		w->move.left = k == KEY_A ? FAULSE : w->move.left;
		w->move.right = k == KEY_D ? FAULSE : w->move.right;
		w->move.forward = k == KEY_W ? FAULSE : w->move.forward;
		w->move.back = k == KEY_S ? FAULSE : w->move.back;
	}
	return (0);
}

int		key_press(int k, t_wolf *w)
{
	(k == KEY_ESC ? exit(0) : 1);

	if (k == KEY_W)
		w->move.forward = KEY_W;
	else if (k == KEY_S)
		w->move.back = KEY_S;
	else if (k == KEY_D)
		w->move.right = KEY_D;
	else if (k == KEY_A)
		w->move.left = KEY_A;
	else if  (k == KEY_ARROW_RIGHT)
		w->move.camera = KEY_ARROW_RIGHT;
	else if (k == KEY_ARROW_LEFT)
		w->move.camera = KEY_ARROW_LEFT;
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
