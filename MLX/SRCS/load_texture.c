/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:13:21 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 12:51:46 by cvernius         ###   ########.fr       */
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

	// printf("ya koshka\n");
	pixmap = stbi_load(filename, &w, &h, &nchannels, 0);
	// printf("ya koshka\n");
	if (!pixmap)
	{
		printf("!pixmap\n");
		exit (11);
	}
	// printf("ya koshka\n");
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
	t->texture = (int*)malloc(sizeof(int) * w * h);
	// printf("cringe\n");
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
