/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:13:21 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 21:22:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int		check_pixmap(t_load_t load_t)
{
	if (!load_t.pixmap)
		wolf_error(TEXTURE_LOAD);
	return (1);
}

int		check_nchannels(t_load_t load_t)
{
	if (load_t.nchannels != 4)
	{
		stbi_image_free(load_t.pixmap);
		wolf_error(TEXTURE_CHANNELS);
	}
	return (1);
}

void	init_one_texture(t_load_t load_t, t_texture *t)
{
	t->cnt = load_t.w / load_t.h;
	t->size = load_t.w / t->cnt;
	t->texture = (int*)malloc(sizeof(int) * load_t.w * load_t.h);
	(t->texture == NULL ? wolf_error(MALLOC_ERROR) : 1);
}

int		load_texture(char *filename, t_texture *t)
{
	t_load_t	load_t;
	t_ivec2		pix;
	t_color		c;

	pix = (t_ivec2){0, 0};
	load_t.pixmap = stbi_load(filename, &load_t.w, &load_t.h,
													&load_t.nchannels, 0);
	if (!check_pixmap(load_t) && !check_nchannels(load_t))
		return (0);
	init_one_texture(load_t, t);
	while (pix.y < load_t.h)
	{
		pix.x = 0;
		while (pix.x < load_t.w)
		{
			c.r = (int)load_t.pixmap[(pix.x + pix.y * load_t.w) * 4 + 0];
			c.g = (int)load_t.pixmap[(pix.x + pix.y * load_t.w) * 4 + 1];
			c.b = (int)load_t.pixmap[(pix.x + pix.y * load_t.w) * 4 + 2];
			t->texture[pix.x + pix.y * load_t.w] = get_color(c);
			pix.x++;
		}
		pix.y++;
	}
	stbi_image_free(load_t.pixmap);
	return (1);
}
