/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:54:41 by hchau             #+#    #+#             */
/*   Updated: 2020/03/08 21:54:47 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	jump(t_wolf *w)
{
	if (w->player.move.jump == STARTED)
	{
		w->player.move.jump_h = w->player.move.jump_h >= NORMAL_HEIGHT ?
				w->player.move.jump_h + 1 : NORMAL_HEIGHT;
	}
	if (w->player.move.jump == 0 || w->player.move.jump == STARTED)
		return ;
	if (w->player.move.jump_h > w->player.move.jump)
	{
		w->player.move.jump_h--;
		w->player.move.camera_up += 0.2;
	}
	else if (w->player.move.camera_up > 0.0 && w->player.move.jump_h != 0)
		w->player.move.camera_up -= 0.2;
	else
	{
		printf("%d\n", w->player.move.jump_h);
		w->player.move.jump_h = 0;
		w->player.move.jump = 0;
	}
}
