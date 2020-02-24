/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:59:05 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/24 22:00:15 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// void	test_text(t_wolf *w)
// {
// 	t_ivec2 p = (t_ivec2){0, 0};
// 	// printf("test_text *** w->t[0]->text_size = %d\n\
// 	//   *** w->t[0]->text_cnt = %d\n", w->t[0]->text_size, w->t[0]->text_cnt);
// 	render_texture(w, w->t[0], p);
// }

// // рендер текстуры на нужное место на экране, без извращений

// void	render_texture(t_wolf *w, t_texture *t, t_ivec2 offset)
// {
// 	int 	origin_offset;
// 	t->text_id = 0.8;
// 	t_ivec2 p = (t_ivec2){0, 0};

// 	printf("render_texture *** text_id = %f\n", t->text_id);
// 	origin_offset = offset.y;
// 	while (p.x < t->text_size)
// 	{
// 		p.y = 0;
// 		offset.y = origin_offset;
// 		while (p.y < t->text_size)
// 		{
// 			w->mlx.img[offset.x + offset.y * WIN_W] = t->texture[p.x + (int)t->text_id * t->text_size + p.y * t->text_size * t->text_cnt];
// 			printf("\n\n%d\n", t->texture[p.x + (int)t->text_id * t->text_size + p.y * t->text_size * t->text_cnt]);
// 			p.y++;
// 			offset.y++;
// 		}
// 		p.x++;
// 		offset.x++;
// 	}
// }
