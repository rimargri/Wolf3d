/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:56:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 21:45:13 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** в ф-цию draw_rect поступает х, у - коорд-ты первого пискеля из всего rect
** Внутри ф-ции мы проходимся по у, х и прибавляем каждый раз
** по единичке(+i; +j), чтобы отрисовать rectngle полностью.
** Т. о. доходим от первого пикселя в левом верхнем углу
** до правого пикселя в нижнем правом - весь rectcolumn_angle отрисован
*/

void    draw_rect(t_drawrect dr, int w, int h, t_wolf *wolf)
{
	int i;
	int j;
	int color;
	t_ivec2 offset;

	i = 0;
	offset = (t_ivec2){0, 0};
	if (dr.color.r == 153 && dr.color.g == 113 && dr.color.b == 233) 		// Ayanami Ray
		render_texture(wolf, wolf->t[0], dr.firstpix);
	else if (dr.color.r == 227 && dr.color.g == 176 && dr.color.b == 229) 	// Sad Shinji
		render_texture(wolf, wolf->t[1], dr.firstpix);
	else if (dr.color.r == 92 && dr.color.g == 147 && dr.color.b == 255) 	// Misato Katsuragi
		render_texture(wolf, wolf->t[2], dr.firstpix);
	else if (dr.color.r == 176 && dr.color.g == 229 && dr.color.b == 193) 	// Misato Katsuragi
		render_texture(wolf, wolf->t[3], dr.firstpix);						// Mexa
	else
	{
		color = get_color(dr.color);
		while (i < w)
		{
			j = 0;
			while (j < h)
			{
				offset.x = dr.firstpix.x + i;
				offset.y = dr.firstpix.y + j;
				if ((offset.x + offset.y * WIN_W) <= (WIN_H * WIN_W) && (offset.x + offset.y * WIN_W) >= 0)
					wolf->mlx.img[offset.x + offset.y * WIN_W] = color;
				j++;
			}
			i++;
		}
	}
}
