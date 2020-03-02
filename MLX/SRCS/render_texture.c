/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/02 23:31:01 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int     x_start(t_vec2 offset, t_texture *t, t_vec2 *hit)
{
	int		x;
	t_vec2	pix;

	hit->x = offset.x - floor(offset.x + 0.5);
	hit->y = offset.y - floor(offset.y + 0.5);

	// hit->x = floor(offset.x);		// перевод в локальные координаты
	// hit->y = floor(offset.y);
	// hit->x = hit->x - 0.5;
	// hit->y = hit->y - 0.5;
	// printf("hit->x = %f\n", hit->x);

	// pix.x = offset.x - hit->x; // + offset.x;
	// pix.y = offset.y - hit->y; // + offset.y;
	// hit->x = offset.x + floor(offset.x - 0.5);
	// hit->y = offset.y + floor(offset.y - 0.5);
	x = hit->x * t->size;
	if (fabs(hit->y) > fabs(hit->x))
		x = hit->y * t->size;
	if (x < 0)
		x += t->size;
	return (x);
}

int		*scale_column(t_raycast r, int *column, int column_height)
{
	int y;
	int x;

	y = 0;
	x = x_start(r.len, r.t, &r.hit);
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
