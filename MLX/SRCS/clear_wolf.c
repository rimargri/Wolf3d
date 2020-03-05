//
// Created by Hugor Chau on 2020-02-22.
//

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
	clear_img(&(*layer)->mask);
	free(*layer);
	layer = NULL;
}
//
//void	clear_textures(t_texture **t)
//{
//
//}

void	clear_wolf(t_wolf **w)
{
	clear_layers(&((*w)->layers));
//	clear_textures((*w)->t);
	free((*w)->map.line);
	(*w)->map.line = NULL;
//	if ((*w)->t != NULL)
//	{
//		free((*w)->t);
//		(*w)->t = NULL;
//	}
	free(*w);
	*w = NULL;
	exit(0);
}