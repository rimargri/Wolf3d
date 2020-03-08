/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:40:26 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 22:21:09 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec2		find_player(t_wolf *w)
{
	t_vec2 p;

	p = (t_vec2){0.0f, 0.0f};
	while ((int)p.x < w->map.w)
	{
		p.y = 0;
		while (p.y < w->map.h)
		{
			if (w->map.line[(int)p.x + (int)p.y * w->map.w] == 'x')
				break ;
			p.y++;
		}
		if (w->map.line[(int)p.x + (int)p.y * w->map.w] == 'x')
			break ;
		p.x++;
	}
	if (w->map.line[(int)p.x + (int)p.y * w->map.w] == 'x')
		w->map.line[(int)p.x + (int)p.y * w->map.w] = ' ';
	else if (w->map.line[(int)p.x + (int)p.y * w->map.w] != 'x')
		p = first_empty_place(w);
	return (p);
}

t_vec2		first_empty_place(t_wolf *w)
{
	t_vec2 p;

	p = (t_vec2){0.0f, 0.0f};
	while (p.x < w->map.w)
	{
		p.y = 0;
		while (p.y < w->map.h)
		{
			if (w->map.line[(int)p.x + (int)p.y * w->map.w] == ' ')
				break ;
			p.y++;
		}
		if (w->map.line[(int)p.x + (int)p.y * w->map.w] == ' ')
			break ;
		p.x++;
	}
	if (!(w->map.line[(int)p.x + (int)p.y * w->map.w] == ' '))
		wolf_error(NO_SPACE_FOR_PLAYER);
	return (p);
}

t_direction	init_move(void)
{
	t_direction move;

	move.forward = FALSE;
	move.back = FALSE;
	move.right = FALSE;
	move.left = FALSE;
	move.camera = 0;
	move.camera_up = 0.0;
	move.jump = FALSE;
	move.jump_h = 0;
	return (move);
}

void		init_player(t_wolf *w)
{
	t_player p;

	p.pos = find_player(w);
	p.look_column_angle.x = 0.0;
	p.look_column_angle.y = 0.0;
	p.move = init_move();
	w->player = p;
}

void		draw_player(t_wolf *w)
{
	w->player.transform.x = w->player.pos.x * rect_w(w->map.w);
	w->player.transform.y = w->player.pos.y * rect_h(w->map.h);
	draw_rect((t_drawrect){w->player.transform,
		get_color((t_color){255, 255, 255})}, 4, 4, &w->layers->d_player);
}
