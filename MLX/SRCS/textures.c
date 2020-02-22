/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 13:13:35 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	**init_textures(void)
{
	t_texture	**t;
	int			i = 0;
	int			count_text;

	count_text = 1;
	t = (t_texture**)malloc(sizeof(t_texture*) * count_text);
	((t == NULL) ? exit(13) : 1);
	while (i < count_text)
	{
		t[i] = (t_texture*)malloc(sizeof(t_texture));
		((t[i] == NULL) ? exit(13) : 1);
		i++;
	}
	if (!(load_texture("./textures/rei_ayanami.png", t[0])))
		wolf_error(TEXTURE_LOAD);
	// printf("init_textures *** t[0].text_size = %d\n", t[0]->text_size);
	return (t);
}

void	test_text(t_wolf *w)
{
	t_ivec2 p = (t_ivec2){0, 0};
	// printf("test_text *** w->t[0].text_size = %d\n", w->t[0]->text_size);
	render_texture(w, w->t[0], p);
}

void	render_texture(t_wolf *w, t_texture *t, t_ivec2 offset)
{
	int 	origin;
	float 	text_id = 0.8;
	t_ivec2 p = (t_ivec2){0, 0};

	origin = offset.y;
	while (p.x < t->text_size)
	{
		p.y = 0;
		offset.y = origin;
		while (p.y < t->text_size)
		{
			w->layers->d_labyrinth.img[offset.x + offset.y * WIN_W] = t->texture[p.x + (int)text_id * t->text_size + p.y * t->text_size * t->text_cnt];
			p.y++;
			offset.y++;
		}
		p.x++;
		offset.x++;
	}
}
