/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:56:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/08 22:11:51 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_pixel(SDL_Renderer *ren, t_color col, int x, int y)
{
	SDL_SetRenderDrawColor(ren, col.r, col.g, col.b, 0xFF);
	SDL_RenderDrawPoint(ren, x, y);	
}

/*
** в ф-цию draw_rect поступает х, у - коорд-ты первого пискеля из всего rect
** Внутри ф-ции мы проходимся по у, х и прибавляем каждый раз
** по единичке(+i; +j), чтобы отрисовать rectngle полностью.
** Т. о. доходим от первого пикселя в левом верхнем углу
** до правого пикселя в нижнем правом - весь rectangle отрисован
*/

void    draw_rect(t_ivec2 frstpix, int w, int h, t_color col, SDL_Renderer *ren)
{
    int i;
	int j;
	t_ivec2 offset;

	i = 0;
	while (i < w)
	{
	    j = 0;
	    while (j < h)
	    {
			offset.x = frstpix.x + i;
			offset.y = frstpix.y + j;
			set_pixel(ren, col, offset.x, offset.y);
	    	j++;
		}
		i++;
	}
}
