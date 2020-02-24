//
// Created by Hugor Chau on 2020-02-22.
//

#include "wolf3d.h"

void		clear_layer(t_img *image)
{
	size_t	len;

	len = 0;
	while (len < (image)->pixels)
	{
		(image)->img[len] = NOCOLOR;//выкручиваю альфа на максимум
		len++;
	}
}

void		put_color_mask(t_img *image, int mask, int x, int y)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (i < x)
	{
		while (j < y)
		{
//			*(int *)(image->img +
//					 ((i + j * image->size->y))) += mask;
			image->img[i + j * image->size->y] = image->img[i + j * image->size->y]  | mask;
//					 		((i + j * image->size->y))) += mask;
			j++;
		}
		j = 0;
		i++;
	}
}

void		put_layer_mask(t_img *image, t_img *mask)
{
	size_t	len;

	len = 0;
	while (len < (image)->pixels)
	{
		(image)->img[len] = mask->img[len];//один имадж на другой накладываю
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

void		init_img(t_img *img, void *mlx_ptr, int bul, t_ivec2 *begin, t_ivec2 *size)
{
	//_FIXX_IMMIDIATLEY в функции 5 аргументов
	int		bp;
	int		size_line;
	int		endian;

	img->mptr = mlx_ptr;
	img->begin = (t_ivec2 *)malloc(sizeof(t_ivec2));
	img->size = (t_ivec2 *)malloc(sizeof(t_ivec2));
	if (!(img->iptr = mlx_new_image(img->mptr, size->x, size->y)))
		wolf_error(IMG_ALLOC_ERR);
	if (!(img->img = (int*)mlx_get_data_addr(img->iptr, &bp, &size_line, &endian)))
		wolf_error(IMG_ALLOC_ERR);
	(img)->pixels = size->x * size->y;
	img->begin->x = begin->x;
	img->begin->y = begin->y;
	img->size->x = size->x;
	img->size->y = size->y;
	img->on = bul;
}

void		init_all_img(t_wolf *w)
{
	t_layer		*res;

	res = (t_layer *)malloc(sizeof(t_layer));
	res->count_layers = COUNT_LAYERS;

	init_fractol(&res->d_fractol);
	init_img(&res->d_fractol_draw, w->mlx.mptr, TRUE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
//	init_img(lol, mlx, TRUE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->d_labyrinth, w->mlx.mptr, TRUE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->d_player, w->mlx.mptr, TRUE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->map_view, w->mlx.mptr, TRUE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->mask, w->mlx.mptr, FALSE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->background, w->mlx.mptr, TRUE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
//	init_img(&res->d_fractol, w->mlx.mptr, FALSE, &(t_ivec2){0, 0}, &(t_ivec2){WIN_W, WIN_H});
	draw_fractal(&res->d_fractol, &res->d_fractol_draw);
	w->layers = res;
	prepare_static_layers(w);
}
