/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:40:26 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 20:53:10 by cvernius         ###   ########.fr       */
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
				break;
			p.y++;
		}
		if (w->map.line[(int)p.x + (int)p.y * w->map.w] == 'x')
			break;
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
				break;
			p.y++;
		}
		if (w->map.line[(int)p.x + (int)p.y * w->map.w] == ' ')
			break;
		p.x++;
	}
	if (!(w->map.line[(int)p.x + (int)p.y * w->map.w] == ' '))
		wolf_error(MAP_IS_FULL);
	return (p);
}

void	init_player(t_wolf *w)
{
	t_player p;

	p.pos = find_player(w);
	p.look_column_angle = 0.0;
	w->player = p;
}

void	draw_player(t_wolf *w)
{
	w->player.transform.x = w->player.pos.x * rect_w(w->map.w);
	w->player.transform.y = w->player.pos.y * rect_h(w->map.h);
	draw_rect((t_drawrect){w->player.transform, (t_color){255, 255, 255}},
															4, 4, w);
}
