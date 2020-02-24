/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/24 22:19:42 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		*texture_column(t_wolf *w, t_texture *t, int text_coord, int column_height)
{
	int img_w;
	int img_h;
	int *column;
	int y = 0;
	t_ivec2 pix;

	img_w = t->size;
	img_h = t->size;
	column = (int*)malloc(sizeof(int) * column_height);
	((column == NULL) ? exit (81) : 1);
	while (y < column_height)
	{
		pix.x = t->size + text_coord;
		pix.y = (y * t->size) / column_height; 
		column[y] = t->texture[pix.x + pix.y * img_w];
		// printf("column[%d]  ==  %d\n", y, column[y]);
		y++;
	}
	return (column);
}
