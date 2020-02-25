/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_help_raycast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:02:33 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/25 23:22:22 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// В какой-то момомент нужно понять, какая именно текстура будет отрисовываться
// возможно, это нужно понять по id

//size_of_texture = x_coord

int     size_of_texture(t_vec2 offset, t_wolf *w, t_texture *t)
{
	int		general_size;
	t_vec2	pix;

	pix.x = offset.x - floor(offset.x + 0.5);
	pix.y = offset.y - floor(offset.y + 0.5);
	printf("pix.x = %f pix.y = %f\n", pix.x, pix.y);
	general_size = pix.x * t->size;
	if (fabs(pix.y) > fabs(pix.x))
		general_size = pix.y * t->size;
	if (general_size < 0)
		general_size += t->size;
	return (general_size);
}

int		*scale_column(t_wolf *w, t_texture *t, int size_texture, int *column, int column_height)
{
	int y = 0;
	while (y < column_height)
	{
		column[y] = w->mlx.img[size_texture + y * WIN_W];
		y++;
	}
	return (column);
}

void	full_column_texture(t_wolf *w, int *column, int column_height, int current_pix)
{
	int y;
	t_ivec2	pix;

	pix.x = current_pix + WIN_W / 2;
	pix.y = 0;
	y = 0;
	while (y < column_height)
	{
		pix.y = y + WIN_H / 2 - column_height / 2;
		if (pix.y >= 0 && pix.y < WIN_H)
			w->mlx.img[pix.x + pix.y * WIN_W] = column[y];		//???????????????????????? WIN_W / 2 
		y++;
	}
}