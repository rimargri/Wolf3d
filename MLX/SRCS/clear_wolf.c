/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_wolf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:35:09 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 22:02:39 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear_img(t_img *image)
{
	size_t		i;
	size_t		huitaya;

	i = 0;
	huitaya = WIN_W * WIN_H;
	while (i < huitaya)
	{
		image->img[i] = '\0';
		i++;
	}
	mlx_destroy_image(image->mptr, image->img);
	free(image->begin);
	image->begin = NULL;
	free(image->size);
	image->size = NULL;
}

void	clear_layers(t_layer **layer)
{
	clear_img(&(*layer)->d_labyrinth);
	clear_img(&(*layer)->d_player);
	clear_img(&(*layer)->map_view);
	clear_img(&(*layer)->background);
	free(*layer);
	layer = NULL;
}

void	clear_wolf(t_wolf **w)
{
	clear_layers(&((*w)->layers));
	free((*w)->map.line);
	(*w)->map.line = NULL;
	if ((*w)->t != NULL)
	{
		free((*w)->t);
		(*w)->t = NULL;
	}
	free(*w);
	*w = NULL;
	exit(0);
}

void	clear_texture(t_texture **t)
{
	int i;

	i = 2;
	while (i < 6)
	{
		free(t[i]->texture);
		free(t[i]);
		t[i] = NULL;
		i++;
	}
}
