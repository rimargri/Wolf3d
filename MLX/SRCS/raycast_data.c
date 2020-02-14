/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:45:42 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 00:05:49 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_raycast	raycast_data(t_raycast r, t_wolf *w)
{
	r.player = w->player;
	// r.player_column_angle = 1.9;
	r.player_column_angle = r.player.look_column_angle;
	r.transform = (t_ivec2){0, 0};
	r.len = (t_vec2){0, 0};
	r.current_pix = 0;
	return (r);
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

void	init_raycast(t_wolf *wolf)
{
	t_raycast	r;
	
	wolf->r.player_column_angle = 0.0;
	wolf->r = r;
}
