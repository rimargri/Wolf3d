/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:07:31 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:50:11 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear_layer(t_img *image)
{
	size_t	len;

	len = 0;
	while (len < (image)->pixels)
	{
		(image)->img[len] = NOCOLOR;
		len++;
	}
}

void		change_img_coord(t_img *img, t_ivec2 *begin)
{
	img->begin->x = begin->x;
	img->begin->y = begin->y;
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
			image->img[i + j * image->size->y] =
					image->img[i + j * image->size->y] | mask;
			j++;
		}
		j = 0;
		i++;
	}
}

// void	put_layer_mask(t_img *image, t_img *mask)
// {
// 	size_t	len;

// 	len = 0;
// 	while (len < (image)->pixels)
// 	{
// 		(image)->img[len] = mask->img[len];
// 		len++;
// 	}
// }

void		should_we_draw_it(t_img *image, void *wptr)
{
	if (image->on == TRUE)
		mlx_put_image_to_window(image->mptr, wptr, image->iptr,
								image->begin->x, image->begin->y);
}

void		draw_layers(t_wolf *w)
{
	should_we_draw_it(&w->layers->background, w->mlx.wptr);
	should_we_draw_it(&w->layers->d_labyrinth, w->mlx.wptr);
	should_we_draw_it(&w->layers->map_view, w->mlx.wptr);
	should_we_draw_it(&w->layers->d_player, w->mlx.wptr);
	should_we_draw_it(&w->layers->menu, w->mlx.wptr);
	should_we_draw_it(&w->layers->menu_button, w->mlx.wptr);
	should_we_draw_it(&w->layers->button_mask, w->mlx.wptr);
	should_we_draw_it(&w->layers->d_fractol_draw, w->mlx.wptr);
}
