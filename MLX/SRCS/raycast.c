/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:13:24 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/25 20:57:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_texture(t_wolf *w, t_vec2 len, t_texture *t, int column_height, int current_pix)
{
	t_vec2		hit;
	int			x_textcoord;
	int			*column;
	t_ivec2		pix;
	int			y = -1;

	printf("я в отрисовке текстур и прмвда пытаюсь их отрисовать!!!!\n");
	pix = (t_ivec2){0, 0};
	hit.x = len.x - floor(len.x + 0.5);
	hit.y = len.y - floor(len.y + 0.5);
	x_textcoord = (int)hit.x * t->size;
	if (fabs(hit.y) > fabs(hit.x))
		x_textcoord = hit.y * t->size;
	if (x_textcoord < 0)
		x_textcoord += t->size;

	column = texture_column(w, t, x_textcoord, column_height);
	pix.x = WIN_W / 2 + current_pix;
	while (++y < column_height)
	{
		// printf("я в цикле  y < column_height\n");
		pix.y = y + WIN_H / 2 - column_height / 2;
		// printf("pix.y = %d\n", pix.y);
		// printf("y == %d\n", y);
		if (pix.y < 0 || pix.y >= (int)WIN_H)
			continue;
		w->mlx.img[pix.x + pix.y * WIN_W] = column[y];
		// printf("w->mlx.img[pix.x + pix.y * WIN_W] = %d\n", w->mlx.img[pix.x + pix.y * WIN_W]);
		// y++;
	}
	sleep(3);
}

void	find_distance(t_wolf *w, int pix)
{
	float	t;
	float	column_angle;
	t_vec2	len;

	t = 0.0f;
	column_angle = w->player.look_column_angle - FOV / 2 + FOV * pix /
														(float)(WIN_W / 2);
	while (t < 100)
	{
		len.x = cos(column_angle) * t + w->player.pos.x; //? Logic
		len.y = sin(column_angle) * t + w->player.pos.y;
		if (len.x >= w->map.w || len.y > w->map.h || len.x < 0 || len.y < 0)
			break ;
		if (w->map.line[(int)len.x + (int)len.y * w->map.w] != ' ')
			// break;
			continue;
		t += 0.01;
	}
	raycast(w, t, len, pix, column_angle);
}

void	raycast(t_wolf *w, float t, t_vec2 len, int pix, int column_angle)
{
	t_raycast	r;
	int			column_height;

	// printf("w->text_id = %d\n", w->text_id);
	r.distance = t;
	r.texture = choice_texture(w, w->map.line[(int)len.x + (int)len.y * w->map.w]);
	printf("%s\n", r.texture->id);
	// printf("texture_size = %d\n", r.texture->text_size);
	column_height = (int)(WIN_H / (r.distance * cos(column_angle - w->player.look_column_angle)));
	// printf("col_height = %d\n", column_height);
	printf("сейчас зайду в рисовку текстур\n");
	draw_texture(w, len, r.texture, column_height, pix);
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
