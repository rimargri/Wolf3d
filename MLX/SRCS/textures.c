/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 21:45:19 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	**init_textures(void)
{
	t_texture	**t;
	int			i = 0;
	int			count_text;

	count_text = 4;
	t = (t_texture**)malloc(sizeof(t_texture*) * count_text);
	((t == NULL) ? exit(13) : 1);
	while (i < count_text)
	{
		t[i] = (t_texture*)malloc(sizeof(t_texture));
		((t[i] == NULL) ? exit(13) : 1);
		i++;
	}
	if (!(load_texture("./textures/rei_ayanami.png", t[0])))
		exit(14);
	if (!(load_texture("./textures/a9ff7837af8a58cbf6642ae954f0c5.png", t[1])))
		exit(13);
	if (!(load_texture("./textures/screen-shot-2020-02-21-at-21-1.png", t[2])))
		exit(13);
	if (!(load_texture("./textures/screen-shot-2020-02-21-at-21-3.png", t[3])))
		exit(13);
	// printf("init_textures *** t[0].text_size = %d\n", t[0]->text_size);
	return (t);
}

void	test_text(t_wolf *w)
{
	t_ivec2 p = (t_ivec2){0, 0};
	printf("test_text *** w->t[0]->text_size = %d\n\
	  *** w->t[0]->text_cnt = %d\n", w->t[0]->text_size, w->t[0]->text_cnt);
	render_texture(w, w->t[0], p);
}

void	render_texture(t_wolf *w, t_texture *t, t_ivec2 offset)
{
	printf("render_texture\n");
	int 	origin_offset;
	float 	text_id = 0.8;
	t_ivec2 p = (t_ivec2){0, 0};

	printf("render_texture *** text_id = %f\n", text_id);
	origin_offset = offset.y;
	while (p.x < t->text_size)
	{
		p.y = 0;
		offset.y = origin_offset;
		while (p.y < t->text_size)
		{
			w->mlx.img[offset.x + offset.y * WIN_W] = t->texture[p.x + (int)text_id * t->text_size + p.y * t->text_size * t->text_cnt];
			p.y++;
			offset.y++;
		}
		p.x++;
		offset.x++;
	}
}
