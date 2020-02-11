/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:03:09 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/11 20:16:11 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** vec_dir - direction vector
*/

void	draw_first_person_view(t_mlx *mlx, float t, int i)
{
	int column_height;
	t_ivec2 first_pix;

	column_height = (int) (WIN_H / t);
	// printf("column_height = %d\n", (int)(WIN_H / t));
	first_pix = (t_ivec2){WIN_W / 2 + i, WIN_H / 2 - column_height / 2};
	draw_rect(first_pix, 1, column_height, (t_color){153, 113, 233}, mlx);
}

t_reycast	*init_reycast_data(t_reycast *r, t_player player)
{
	r->player = player;
	r->vec_dir = 1.5;
	r->transform = (t_ivec2){0, 0};
	r->len = (t_vec2){0, 0};
	r->current_pix = 0;
	r->color = get_color((t_color){255, 255, 255});
	return (r);
}

void	cast_ray(t_mlx *mlx, char *map, t_player player)
{
	t_reycast	*r;

	r = (t_reycast*)malloc(sizeof(t_reycast));
	r = init_reycast_data(r, player);
	while (r->current_pix < WIN_W / 2)
	{
		r->angle = r->vec_dir - FOV / 2 + FOV * r->current_pix / (float) (WIN_W / 2);
		r->t = 0.0;
		while (r->t < 20)
		{
			r->len.x = cos(r->angle) * r->t + r->player.pos.x;
			r->len.y = sin(r->angle) * r->t + r->player.pos.y;
			r->transform.x = r->len.x * RECT_W;
			r->transform.y = r->len.y * RECT_H;
			mlx_pixel_put(mlx->mptr, mlx->wptr, r->transform.x, r->transform.y, r->color);
			if (map[(int)r->len.x + (int)r->len.y * MAP_W] != ' ')
			{
				draw_first_person_view(mlx, r->t, r->current_pix);
				break;
			}
			r->t += 0.1;
		}
		r->current_pix++;	
	}
}
