/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 12:18:23 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

// int		load_texture(char *filename, t_texture *t);

t_texture	*init_textures(void)
{
	t_texture	*t;
	int			count_text;

	count_text = 1;
	t = (t_texture*)malloc(sizeof(t_texture) * count_text);
	((t == NULL) ? exit(13) : 1);
	if (!(load_texture("./textures/rei_ayanami.png", t[0])))
		exit(14);
	printf("init_textures *** t[0].text_size = %d\n", t[0].text_size);
	return (t);
}

void	test_text(t_wolf *w)
{
	t_ivec2 p = (t_ivec2){32, 32};
	printf("test_text ** w->t[0].text_size = %d\n", w->t[0].text_size);
	render_texture(w, w->t[0], p);
}

void	render_texture(t_wolf *w, t_texture t, t_ivec2 offset)
{
	int 	origin;
	float 	text_id = 0.8;
	t_ivec2 p = (t_ivec2){0, 0};

	printf("render_texture\n");
	printf("text_size = %d\n", t.text_size);
	origin = offset.y;
	while (p.x < t.text_size)
	{
		p.y = 0;
		offset.y = origin;
		while (p.y < t.text_size)
		{
			w->mlx.img[offset.x + offset.y * WIN_W] = t.texture[p.x + (int)text_id * t.text_size + p.y * t.text_size * t.text_cnt];
			p.y++;
			offset.y++;
		}
		p.x++;
		offset.x++;
	}
	printf("the end :c\n");
}

// void	texture_main(t_wolf *w)
// {
// 	t_texture *t;
// 	// t_texture	*rey;
// 	// t_texture	*shinji;
// 	// t_tedture	*me;
// 	int i = 0;
// 	int N = 2;
// 	t_ivec2 p;

// 	t = (t_texture*)malloc(sizeof(t_texture) * N);
// 	p = (t_ivec2){0, 0};
// 	if (!(load_texture("./textures/rei_ayanami.png", &t[0])))
// 		exit(14);
// 	if (!(load_texture("./textures/shinji_crying.png", &t[1])))
// 		exit(15);
// 	/** весь остальной код, что есть в проге **/
// 	// printf("walltext_size = %d\n", rey->text_size);
// 	// printf("walltext_size = %d\n", shinji->text_size);
// 	while (i < N)
// 	{
// 		render_texture(w, &t[i], p);
// 		p.x += 32;
// 		p.y += 32;
// 		i++;
// 	}
// }

// void render_texture(t_wolf *w, t_texture *t, t_ivec2 offset)
// {
// 	float text_id = 0.8;
// 	int i = 0;
// 	int j = 0;

// 	while (i < t->text_size)
// 	{
// 		j = 0;
// 		offset.y = 32;
// 		while (j < t->text_size)
// 		{
// 			w->mlx.img[offset.x + offset.y * WIN_W] = t->texture[i + (int)text_id * t->text_size + j * t->text_size * t->text_cnt];
// 			j++;
// 			offset.y++;
// 		}
// 		i++;
// 		offset.x++;
// 	}
// }
