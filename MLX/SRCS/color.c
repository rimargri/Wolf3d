/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:45:42 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 19:05:22 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

t_color	wall_color(char *map, t_vec2 len)
{
	t_color c;

	if (map[(int)len.x + (int)len.y * MAP_W] == '0')					// pirple
		c = (t_color){153, 113, 233};
	else if (map[(int)len.x + (int)len.y * MAP_W] == '1')
		c = (t_color){227, 176, 229};									// pink
	else if (map[(int)len.x + (int)len.y * MAP_W] == '2')
		c = (t_color){92, 147, 255};									// blue
	else if (map[(int)len.x + (int)len.y * MAP_W] == '3')
		c = (t_color){176, 229, 193};									// green
	else
		return (t_color){0, 0, 0};
	return ((t_color)c);
}
