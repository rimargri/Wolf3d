/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/20 21:51:57 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int		load_texture(char *filename, t_texture *t)
{
	unsigned char *pixmap;
	int nchannels = -1, w, h;
	int i;
	int j = 0;
	t_color c;

	printf("ya koshka\n");
	pixmap = stbi_load(filename, &w, &h, &nchannels, 0);
	printf("ya koshka\n");
	if (!pixmap)
	{
		printf("!pixmap\n");
		exit (11);
	}
	printf("ya koshka\n");
	if (nchannels != 4) // Error: the texture must be a 32 bit image
	{
		printf("!= 444 xkoshka\n");
		stbi_image_free(pixmap);
		exit (12);
	}
	t->text_cnt = w / h;
	t->text_size = w / t->text_cnt;
	if (w != h * (int)t->text_cnt) // Error: the texture file must contain N square textures packed horizontally
	{
		printf("w != h\n");
		stbi_image_free(pixmap);
		exit (13);
	}
	t->texture = malloc(sizeof(int) * w * h);
	printf("cringe\n");
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			c.r = (int)pixmap[(i + j * w) * 4 + 0];
			c.g = (int)pixmap[(i + j * w) * 4 + 1];
			c.b = (int)pixmap[(i + j * w) * 4 + 2];
			t->texture[i + j * w] = get_color(c);
			i++;
		}
		j++;
	}
	stbi_image_free(pixmap);
	return (1);
}

void	texture_main(t_wolf *w)
{
	t_texture *t;
	// t_texture	*rey;
	// t_texture	*shinji;
	// t_tedture	*me;
	int i = 0;
	int N = 2;
	t_ivec2 p;

	t = (t_texture*)malloc(sizeof(t_texture) * N);
	p = (t_ivec2){0, 0};
	if (!(load_texture("./textures/rei_ayanami.png", &t[0])))
		exit(14);
	if (!(load_texture("./textures/shinji_crying.png", &t[1])))
		exit(15);
	/** весь остальной код, что есть в проге **/
	// printf("walltext_size = %d\n", rey->text_size);
	// printf("walltext_size = %d\n", shinji->text_size);
	while (i < N)
	{
		render_texture(w, &t[i], p);
		p.x += 32;
		p.y += 32;
		i++;
	}
}

void render_texture(t_wolf *w, t_texture *t, t_ivec2 offset)
{
	float text_id = 0.8;
	int i = 0;
	int j = 0;

	while (i < t->text_size)
	{
		j = 0;
		offset.y = 32;
		while (j < t->text_size)
		{
			w->mlx.img[offset.x + offset.y * WIN_W] = t->texture[i + (int)text_id * t->text_size + j * t->text_size * t->text_cnt];
			j++;
			offset.y++;
		}
		i++;
		offset.x++;
	}
}
