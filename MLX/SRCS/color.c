/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:45:42 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 19:41:33 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_color(t_color color)
{
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}

t_color	raycast_color(t_raycast r, char *map)
{
	if (map[(int)r.len.x + (int)r.len.y * MAP_W] == '0')					// pirple
		r.color = (t_color){153, 113, 233};
	if (map[(int)r.len.x + (int)r.len.y * MAP_W] == '1')
		r.color = (t_color){227, 176, 229};									// pink
	if (map[(int)r.len.x + (int)r.len.y * MAP_W] == '2')
		r.color = (t_color){92, 147, 255};									// blue
	if (map[(int)r.len.x + (int)r.len.y * MAP_W] == '3')
		r.color = (t_color){176, 229, 193};									// green
	return (r.color);
}
