/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 22:50:46 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		load_texture(char *filename, t_texture *t)
{
	unsigned char *pixmap;
	int nchannels = -1, w, h;
	int i;
	int j = 0;
	t_color c;

	pixmap = stbi_load(filename, &w, &h, &nchannels, 0);
	if (!pixmap)
		exit (11);
	if (nchannels != 4) // Error: the texture must be a 32 bit image
	{
		stbi_image_free(pixmap);
		exit (12);
	}
	t->text_cnt = w / h;
	t->text_size = w / t->text_cnt;
	if (w != h * (int)t->text_cnt) // Error: the texture file must contain N square textures packed horizontally
	{
		stbi_image_free(pixmap);
		exit (13);
	}
	t->texture = malloc(sizeof(int) * w * h);
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

void	texture_main(void)
{
	t_texture	*t;
	// int			*walltext;
	// int walltext_size;
	// int walltext_cnt;
	int	text_id = 4;
	int i = 0;
	int j;

	t = (t_texture*)malloc(sizeof(t_texture));
	if (!(load_texture("../textures/rei_ayanami.png", t)))
		exit(14);
	/** весь остальной код, что етсь в проге **/
	printf("walltext_size = %d\n", t->text_size);
	// while (i < walltext_size)
	// {
	// 	j = 0;
	// 	while (j < walltext_size)
	// 	{
	// 		w->mlx.img[i + j * WIN_W] = walltext[i + text_id * walltext_size + j * walltext_size * walltext_cnt];
	// 		j++;
	// 	}
	// 	i++;
	// }
}
