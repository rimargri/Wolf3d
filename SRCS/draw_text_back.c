/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:39:56 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 22:06:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_texture_on_celling(t_wolf *w, t_texture *t)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			w->layers->background.img[x + y * WIN_W] =
												t->texture[x + y * t->size];
			x++;
		}
		y++;
	}
}

void	draw_texture_on_floor(t_wolf *w, t_texture *t)
{
	int x;
	int y;

	y = WIN_H / 2;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			w->layers->background.img[x + y * WIN_W] =
												t->texture[x + y * t->size];
			x++;
		}
		y++;
	}
}
