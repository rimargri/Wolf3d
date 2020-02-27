//
// Created by Hugor Chau on 2020-02-25.
//

#include "wolf3d.h"


void		clear_dinamic_img(t_layer *layer)
{
	clear_layer(&layer->d_labyrinth);
//	clear_layer(&layer->d_player);
	clear_layer(&layer->d_player);
}

void		prepare_static_layers(t_wolf *w)
{
	clear_layer(&w->layers->map_view);
	draw_walls(w);
	draw_background(w);
}

void		change_img_coord(t_img *img, t_ivec2 *begin)
{
	img->begin->x = begin->x;
	img->begin->y = begin->y;
}

void		init_img(t_img *img, void *mlx_ptr, int bul, t_ivec2 *size)
{
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
	img->begin->x = 0;
	img->begin->y = 0;
	img->size->x = size->x;
	img->size->y = size->y;
	img->on = bul;
}

void	init_fractol(t_draw_fractal **f)
{
	static t_fractal	count = {20, {0.4, 0.1}, {0, 0}, {0, 0}, 0};

	*f = (t_draw_fractal *)malloc(sizeof(t_draw_fractal));
	(*f)->is_mooving = IN;
	(*f)->count = count;
}

void		init_all_img(t_wolf *w)
{
	t_layer		*res;

	res = (t_layer *)malloc(sizeof(t_layer));
	res->draw_shift = 0.0;
	res->count_layers = COUNT_LAYERS;
	init_fractol(&res->d_fractol);
	init_img(&res->d_fractol_draw, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->d_labyrinth, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->d_player, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->map_view, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->mask, w->mlx.mptr, FALSE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->background, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	//если нужно по дефолту ставить имадж на других координатах, используй ф-ию (change_img_coord)
	draw_fractal(&res->d_fractol, &res->d_fractol_draw);
	w->layers = res;
	prepare_static_layers(w);
}
