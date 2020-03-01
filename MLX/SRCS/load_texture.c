/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:13:21 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/01 19:31:26 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

t_texture	**init_textures(void)
{
	t_texture	**t;
	int			i = 0;
	int			count_text;

	count_text = 9;
	t = (t_texture**)malloc(sizeof(t_texture*) * count_text);
	((t == NULL) ? exit(13) : 1);
	while (i < count_text)
	{
		t[i] = (t_texture*)malloc(sizeof(t_texture));
		((t[i] == NULL) ? exit(13) : 1);
		t[i]->id = i;
		i++;
	}

				/** *********************************** **/
				/** *********************************** **/
				/**            evangelion               **/
				/** *********************************** **/
				/** *********************************** **/


	// if (!(load_texture("./textures/rei_ayanami.png", t[0])))
	// 	exit(13);
	// // if (!(load_texture("./textures/ray.png", t[0])))
	// // 	exit(13);
	// if (!(load_texture("./textures/a9ff7837af8a58cbf6642ae954f0c5.png", t[1])))
	// 	exit(13);
	// if (!(load_texture("./textures/screen-shot-2020-02-21-at-21-1.png", t[2])))
	// 	exit(13);
	// if (!(load_texture("./textures/screen-shot-2020-02-21-at-21-3.png", t[3])))
	// 	exit(13);
	// if (!(load_texture("./textures/pepe.png", t[4])))
	// 	exit(13);

				/** *********************************** **/
				/** *********************************** **/
				/**            panelki                  **/
				/** *********************************** **/
				/** *********************************** **/

	if (!(load_texture("./textures/panelka_1.png", t[0])))
		exit(13);
	if (!(load_texture("./textures/love_house.png", t[1])))
		exit(13);
	if (!(load_texture("./textures/panelka_2.png", t[2])))
		exit(13);
	if (!(load_texture("./textures/ray.png", t[3])))
		exit(13);
	if (!(load_texture("./textures/pepe.png", t[4])))
		exit(13);
	if (!(load_texture("./textures/night_sky_3.png", t[5])))
		exit(13);
	if (!(load_texture("./textures/carpet.png", t[6])))
		exit(13);
	if (!(load_texture("./textures/blacktext.png", t[7])))
		exit(13);
	if (!(load_texture("./textures/planet_surface.png", t[8])))
		exit(13);
	// printf("init_textures *** t[6].text_size = %d\n", t[6]->size);
	return (t);
}

int		load_texture(char *filename, t_texture *t)
{
	t_load_t	load_texture;
	t_ivec2		pix;
	t_color 	c;

	pix = (t_ivec2){0, 0};
	load_texture.pixmap = stbi_load(filename, &load_texture.w, &load_texture.h, &load_texture.nchannels, 0);
	if (!load_texture.pixmap)
	{
		printf("!pixmap\n");
		exit (11);
	}
	if (load_texture.nchannels != 4) // Error: the texture must be a 32 bit image
	{
		printf("nchannels != 4\n");
		stbi_image_free(load_texture.pixmap);
		exit (12);
	}
	t->cnt = load_texture.w / load_texture.h;
	t->size = load_texture.w / t->cnt;
	// if (w != h * (int)t->cnt) // Error: the texture file must contain N square textures packed horizontally
	// {
	// 	printf("w != h * (int)t->text_cnt\n");
	// 	stbi_image_free(pixmap);
	// 	exit (13);
	// }
	t->texture = (int*)malloc(sizeof(int) * load_texture.w * load_texture.h);
	while (pix.y < load_texture.h)
	{
		pix.x = 0;
		while (pix.x < load_texture.w)
		{
			c.r = (int)load_texture.pixmap[(pix.x + pix.y * load_texture.w) * 4 + 0];
			c.g = (int)load_texture.pixmap[(pix.x + pix.y * load_texture.w) * 4 + 1];
			c.b = (int)load_texture.pixmap[(pix.x + pix.y * load_texture.w) * 4 + 2];
			t->texture[pix.x + pix.y * load_texture.w] = get_color(c);
			pix.x++;
		}
		pix.y++;
	}
	stbi_image_free(load_texture.pixmap);
	return (1);
}
