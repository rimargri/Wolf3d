/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:39:23 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:46:47 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		clear_dinamic_img(t_layer *layer)
{
	clear_layer(&layer->d_labyrinth);
	clear_layer(&layer->d_player);
}

void		prepare_static_layers(t_wolf *w)
{
	int		x;

	x = 0;
	clear_layer(&w->layers->map_view);
	draw_background_on_map(w);
	draw_texture_on_floor(w, w->t[0]);
	draw_texture_on_celling(w, w->t[1]);
	open_menu_image(&w->layers->menu_button,
			"./textures/menu_butt.xpm", 150, 57);
	open_menu_image(&w->layers->button_mask,
			"./textures/menu_butt.xpm", 150, 57);
	open_menu_image(&w->layers->menu,
			"./textures/EVA.xpm", WIN_W, WIN_W);
	open_menu_image(&w->layers->music_button,
			"./textures/music.xpm", 150, 57);
	open_menu_image(&w->layers->music_mask,
			"./textures/music.xpm", 150, 57);
	put_color_mask(&w->layers->button_mask, 0x55000000, 57, 150);
	put_color_mask(&w->layers->music_mask, 0x55000000, 57, 65);
	prepare_menu_img(w);
	draw_walls(w);
}

void		init_img(t_img *img, void *mlx_ptr, int bul, t_ivec2 *size)
{
	int		bp;
	int		size_line;
	int		endian;

	img->mptr = mlx_ptr;
	img->begin = (t_ivec2 *)malloc(sizeof(t_ivec2));
	(img->begin == NULL ? wolf_error(MALLOC_ERROR) : 1);
	img->size = (t_ivec2 *)malloc(sizeof(t_ivec2));
	(img->size == NULL ? wolf_error(MALLOC_ERROR) : 1);
	if (!(img->iptr = mlx_new_image(img->mptr, size->x, size->y)))
		wolf_error(IMG_ALLOC_ERR);
	if (!(img->img =
			(int*)mlx_get_data_addr(img->iptr, &bp, &size_line, &endian)))
		wolf_error(IMG_ALLOC_ERR);
	(img)->pixels = size->x * size->y;
	img->begin->x = 0;
	img->begin->y = 0;
	img->size->x = size->x;
	img->size->y = size->y;
	img->on = bul;
}

void		init_fractol(t_draw_fractal **f)
{
	static t_fractal	count = {20, {0.4, 0.1}, {0, 0}, {0, 0}, 0};

	*f = (t_draw_fractal *)malloc(sizeof(t_draw_fractal));
	(*f == NULL ? wolf_error(MALLOC_ERROR) : 1);
	(*f)->is_mooving = IN;
	(*f)->count = count;
}

void		init_all_img(t_wolf *w)
{
	t_layer		*res;

	res = (t_layer *)malloc(sizeof(t_layer));
	(res == NULL ? wolf_error(MALLOC_ERROR) : 1);
	res->draw_shift = 0.0;
	res->count_layers = COUNT_LAYERS;
	init_fractol(&res->d_fractol);
	init_img(&res->d_fractol_draw, w->mlx.mptr,
			FALSE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->d_labyrinth, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->d_player, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->map_view, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->menu, w->mlx.mptr, FALSE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->background, w->mlx.mptr, TRUE, &(t_ivec2){WIN_W, WIN_H});
	init_img(&res->menu_button, w->mlx.mptr, FALSE, &(t_ivec2){150, 57});
	init_img(&res->button_mask, w->mlx.mptr, TRUE, &(t_ivec2){150, 57});
	init_img(&res->music_button, w->mlx.mptr, FALSE, &(t_ivec2){150, 57});
	init_img(&res->music_mask, w->mlx.mptr, TRUE, &(t_ivec2){150, 57});
	w->layers = res;
	prepare_static_layers(w);
	change_img_coord(&res->menu_button, &(t_ivec2){WIN_W - 155, 5});
	change_img_coord(&res->button_mask, &(t_ivec2){WIN_W - 155, 5});
	change_img_coord(&res->music_button, &(t_ivec2){WIN_W - 105, WIN_H - 90});
	change_img_coord(&res->music_mask, &(t_ivec2){WIN_W - 105, WIN_H - 90});
	change_img_coord(&res->menu, &(t_ivec2){WIN_W / 2, 0});
}
