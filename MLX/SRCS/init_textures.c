/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:43:11 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 21:15:11 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	**malloc_text(void)
{
	t_texture	**t;
	int			i = 0;
	int			count_text;

	count_text = 9;
	t = (t_texture**)malloc(sizeof(t_texture*) * count_text);
	((t == NULL) ? wolf_error(MALLOC_ERROR) : 1);
	while (i < count_text)
	{
		t[i] = (t_texture*)malloc(sizeof(t_texture));
		((t[i] == NULL) ? wolf_error(MALLOC_ERROR) : 1);
		t[i]->id = i;
		i++;
	}
	return (t);
}

t_texture	**init_textures(void)
{
	t_texture	**t;

	t = malloc_text();
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
	if (!(load_texture("./textures/night_sky0.png", t[5])))
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
