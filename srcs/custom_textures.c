/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:04:03 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:08:32 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	text_panelki(t_texture **t)
{
	if (!(load_texture("./textures/panelka_1.png", t[2])))
		exit(13);
	if (!(load_texture("./textures/love_house.png", t[3])))
		exit(13);
	if (!(load_texture("./textures/panelka_2.png", t[4])))
		exit(13);
	if (!(load_texture("./textures/ray.png", t[5])))
		exit(13);
}

void	text_evangelion(t_texture **t)
{
	if (!(load_texture("./textures/ray.png", t[2])))
		exit(13);
	if (!(load_texture("./textures/shinji.png", t[3])))
		exit(13);
	if (!(load_texture("./textures/misato.png", t[4])))
		exit(13);
	if (!(load_texture("./textures/mexa_eva.png", t[5])))
		exit(13);
}

void	text_pepe(t_texture **t)
{
	if (!(load_texture("./textures/pepe_crying.png", t[2])))
		exit(13);
	if (!(load_texture("./textures/pepe_shrug.png", t[3])))
		exit(13);
	if (!(load_texture("./textures/pepe_died.png", t[4])))
		exit(13);
	if (!(load_texture("./textures/pepe_ehidniy.png", t[5])))
		exit(13);
}
