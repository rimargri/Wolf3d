/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/27 17:19:15 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int     x_start(t_vec2 offset, t_texture *t)
{
	int		x;
	t_vec2	pix;

	pix.x = offset.x - floor(offset.x + 0.5);
	pix.y = offset.y - floor(offset.y + 0.5);
	x = pix.x * t->size;
	if (fabs(pix.y) > fabs(pix.x))
		x = pix.y * t->size;
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
			w->mlx.img[pix.x + pix.y * WIN_W] = column[y]; 
		y++;
	}
}
