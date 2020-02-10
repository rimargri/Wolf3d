/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:56:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/10 20:57:20 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

/*
** в ф-цию draw_rect поступает х, у - коорд-ты первого пискеля из всего rect
** Внутри ф-ции мы проходимся по у, х и прибавляем каждый раз
** по единичке(+i; +j), чтобы отрисовать rectngle полностью.
** Т. о. доходим от первого пикселя в левом верхнем углу
** до правого пикселя в нижнем правом - весь rectangle отрисован
*/

void    draw_rect(t_ivec2 frstpix, int w, int h, t_color col, t_mlx *mlx)
{
    int i;
	int j;
	int color;
	t_ivec2 offset;

	i = 0;
	color = get_color(col);
	while (i < w)
	{
	    j = 0;
	    while (j < h)
	    {
			offset.x = frstpix.x + i;
			offset.y = frstpix.y + j;
			mlx_pixel_put(mlx->mptr, mlx->wptr, offset.x, offset.y, color);
	    	j++;
		}
		i++;
	}
}
