/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:56:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/18 23:05:12 by cvernius         ###   ########.fr       */
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

void    draw_rect(t_drawrect dr, int w, int h, t_mlx mlx)
{
    int i;
	int j;
	int color;
	t_ivec2 offset;

	i = 0;
	offset = (t_ivec2){0, 0};
	color = get_color(dr.color);
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			offset.x = dr.firstpix.x + i;
			offset.y = dr.firstpix.y + j;
			if ((offset.x + offset.y * WIN_W) <= (WIN_H * WIN_W) && (offset.x + offset.y * WIN_W) >= 0) 
				mlx.img[offset.x + offset.y * WIN_W] = color;
			j++;
		}
		i++;
	}
}
