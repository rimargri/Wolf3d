//
// Created by Hugor Chau on 2020-02-22.
//

#include "wolf3d.h"

void		clear_layer(t_img *image)
{
	size_t	len;

	len = 0;
	while (len < (image)->size)
	{
		(image)->img[len] = NOCOLOR;//выкручиваю альфа на максимум
		len++;
	}
}

void		clear_dinamic_img(t_layer *layer)
{
	clear_layer(&layer->d_labyrinth);
	clear_layer(&layer->d_player);
}

void		prepare_static_layers(t_wolf *w)
{
	clear_layer(&w->layers->map_view);
	draw_walls(w);
	draw_background(w);
}

void		init_img(t_img *img, void *mlx_ptr)
{
	int		bp;
	int		size_line;
	int		endian;

	img->mptr = mlx_ptr;
	if (!(img->iptr = mlx_new_image(img->mptr, WIN_W, WIN_H)))
		wolf_error(IMG_ALLOC_ERR);
	if (!(img->img = (int*)mlx_get_data_addr(img->iptr, &bp, &size_line, &endian)))
		wolf_error(IMG_ALLOC_ERR);
	(img)->size = WIN_W * WIN_H;
}

t_layer		*init_all_img(void *mlx_ptr)
{
	t_layer		*res;

	res = (t_layer *)malloc(sizeof(t_layer));
	res->count_layers = COUNT_LAYERS;
	init_img(&res->d_labyrinth, mlx_ptr);
	init_img(&res->d_player, mlx_ptr);
	init_img(&res->map_view, mlx_ptr);
	init_img(&res->mask, mlx_ptr);
	init_img(&res->background, mlx_ptr);
	return (res);
}
