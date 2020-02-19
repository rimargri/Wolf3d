/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 22:17:39 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		*load_texture(char *filename, int *texture, size_t &text_size, size_t &text_cnt)
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
	text_cnt = w / h;
	text_size = w / text_cnt;
	if (w != h * (int)text_cnt) // Error: the texture file must contain N square textures packed horizontally
	{
		stbi_image_free(pixmap);
		exit (13);
	}
	texture = malloc(sizeof(int) * w * h);
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			c.r = (int)pixmap[(i + j * w) * 4 + 0];
			c.g = (int)pixmap[(i + j * w) * 4 + 1];
			c.b = (int)pixmap[(i + j * w) * 4 + 2];
			texture[i + j * w] = get_color(c);
			i++;
		}
		j++;
	}
	stbi_image_free(pixmap);
	return (texture);
}

void	texture_main(void)
{
	int *walltext;
	int walltext_size;
	int walltext_cnt;
	int	text_id = 4;
	int i = 0;
	int j;

	if (!(walltext = load_texture("../textures/rei_ayanami.png", walltext, walltext_size, walltext_cnt)))
		exit(14);
	/** весь остальной код, что етсь в проге **/
	printf("walltext_size = %d\n", walltext_size);
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
