/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 14:40:10 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** hit->x, hit->y check it in cardinal_points
** if its not nessesary, remove part "hit" from struct in structs.h
*/

int     x_start(t_vec2 len, t_texture *t)
{
	int		x;
	t_vec2	hit;

	hit.x = floor(len.x + 0.5f);
	hit.y = floor(len.y + 0.5f);
	hit.x = len.x - hit.x;
	hit.y = len.y - hit.y;
	x = hit.x * t->size;
	if (fabs(hit.y) > fabs(hit.x))
		x = hit.y * t->size;
	if (x < 0)
		x += t->size;
	return (x);
}

int		*scale_column(t_raycast r, int *column, int column_height)
{
	int y;
	int x;

	y = 0;
	x = x_start(r.len, r.t);
	while (y < column_height)
	{
		// ?? MODE "matrix": 
		// column[y] = r.t->texture[x + y * WIN_W];
		column[y] = r.t->texture[x + (y * r.t->size / column_height) * r.t->size];
		y++;
	}
	return (column);
}

void	full_column_texture(t_wolf *w, int *column, int column_height, int current_pix)
{
	int		y;
	t_ivec2	pix;

	pix.x = current_pix + WIN_W / 2;
	pix.y = 0;
	y = 0;
	while (y < column_height)
	{
		pix.y = y + WIN_H / 2 - column_height / 2;
		if (pix.y >= 0 && pix.y < WIN_H)
			// w->mlx.img[pix.x + pix.y * WIN_W] = column[y]; 
			w->layers->d_labyrinth.img[pix.x + pix.y * WIN_W] = column[y];
		y++;
	}
}
