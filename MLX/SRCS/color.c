/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:45:42 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 20:34:27 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

t_color	wall_color(t_map *map, t_vec2 len)
{
	t_color c;

	if ((int)len.x >= map->w || (int)len.x < 0 ||
			(int)len.y >= map->h || (int)len.y < 0)
		return ((t_color){-1, -1, -1});
	if (map->line[(int)len.x + (int)len.y * map->w] == '0')					// purple
		c = (t_color){153, 113, 233};
	else if (map->line[(int)len.x + (int)len.y * map->w] == '1')
		c = (t_color){227, 176, 229};									// pink
	else if (map->line[(int)len.x + (int)len.y * map->w] == '2')
		c = (t_color){92, 147, 255};									// blue
	else if ((map->line[(int)len.x + (int)len.y * map->w]) == '3')
		c = (t_color){176, 229, 193};									// green
	else if ((map->line[(int)len.x + (int)len.y * map->w]) == '4')
		c = (t_color){0, 0, 0};											// black
	else if ((map->line[(int)len.x + (int)len.y * map->w]) == '5')
		c = (t_color){240 ,100, 100};									// red
	else if ((map->line[(int)len.x + (int)len.y * map->w]) == '6')
		c = (t_color){240 ,240, 240};									// red
	else if ((map->line[(int)len.x + (int)len.y * map->w]) == '7')
		c = (t_color){100, 150, 100};
	else
		c = (t_color){-1, -1, -1};
	return ((t_color)c);
}
