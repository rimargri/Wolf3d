/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:13:24 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/20 16:59:08 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	find_distance(t_wolf *w, int pix)
{
	float	t;
	t_vec2	column_angle;
	t_vec2	len;
	float	z = 0;
	float	y_offset;

	t = 0.0f;
	column_angle.x = w->player.look_column_angle.x - FOV / 2 + FOV * pix /
														(float)(WIN_W / 2);
	column_angle.y = w->player.look_column_angle.y;
//	y_offset = w->player.look_column_angle.y * 50;
//	if (column_angle.y < 0.0)
//		column_angle.y *= -1;
//	if (column_angle.y < 0.1)
//		column_angle.y = 0.1;
	while (t < 100)
	{
		//это вращение по y
		//x
		z = t;
		len.x = /*   x //t// * cos(y-угол) + z (1) * sin(y-угол) */ cos(column_angle.x) * z + w->player.pos.x; //? Logic
		//z
		len.y = /*   x //t// * sin(y-угол) + z * cos(у-угол) */ sin(column_angle.x) * z + w->player.pos.y;

//		printf("z1  = %f, z2 = %f\n", (len.x - t * cos(column_angle.x)) / sin(column_angle.x),
//			   	   	   	   	   	   	   (len.y + t * sin(column_angle.x)) / cos(column_angle.x));
//		len.x = cos(column_angle.x) * t + w->player.pos.x; //? Logic
//		len.y = len.y * (-1) * sin(column_angle.y) + w->player.pos.y;
//		len.x = len.x * (-1) * sin(column_angle.y) + w->player.pos.y;

//		//вращение по x
		if (len.x >= w->map.w || len.y > w->map.h || len.x < 0 || len.y < 0)
			break ;
		if (w->map.line[(int)len.x + (int)len.y * w->map.w] != ' ')
				break;
		t += 0.01;
	}
	z = z * cos(column_angle.y) * 20 - len.y * sin(column_angle.y) * 20;
	y_offset = z * sin(column_angle.y) + len.x * cos(column_angle.y) * 20;
//	if (column_angle.y > 6.28319 || column_angle.y * -1 < -6.28319)
//	{
//		z =  z * sin(column_angle.y) + z * cos(6.28317) * 20 - len.y * sin(6.28317) * 20;
//		y_offset += len.x * cos(6.28317) * 20;
//	}
//	t += column_angle.y;
//	printf("z1  = %f, z2 = %f\n", (len.x - t * cos(column_angle.x)) / sin(column_angle.x),
//		   (len.y + t * sin(column_angle.x)) / cos(column_angle.x));
//	y_offset = len.y * sin(column_angle.x) + len.y * cos(column_angle.y);
//	if (column_angle.y < 0.005)
//		raycast(w, t, len, pix, (int)(0));
//	else
	raycast(w, t, len, pix, (int)(y_offset));
}

void	raycast(t_wolf *w, float t, t_vec2 len, int pix, int y_offset)
{
	t_raycast	r;
	int			column_height;
	t_ivec2		firstpix;

	r.distance = t;
	r.wall_color = (t_color)wall_color(&w->map, len);
	if (r.wall_color.r == -1 && r.wall_color.g == -1 && r.wall_color.b == -1)
		return ;
	column_height = (int)(WIN_H / r.distance);
	firstpix.x = (int){WIN_W / 2 + pix};
	firstpix.y = (int){WIN_H / 2 - column_height / 2};
	draw_rect((t_drawrect){firstpix, r.wall_color}, 1, column_height, &w->layers->d_labyrinth, y_offset);
}

void	render_walls(t_wolf *w)
{
	int current_pix;

	current_pix = 0;
	while (current_pix < WIN_W / 2)
	{
		find_distance(w, current_pix);
		current_pix++;
	}
}
