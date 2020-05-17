/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:05:00 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 11:29:13 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	text_floor(t_texture *t)
{
	if (!(load_texture("./textures/blacktext.png", t)))
		exit(13);
}

void	text_celling(t_texture *t)
{
	if (!(load_texture("./textures/night_sky0.png", t)))
		exit(13);
}
