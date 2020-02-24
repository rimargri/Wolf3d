/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:18:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 13:07:41 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;
	
	if (!(mlx.mptr = mlx_init()))
		wolf_error(MLX_POINTER);
	if (!(mlx.wptr = mlx_new_window(mlx.mptr, WIN_W, WIN_H, "WOLF3D\0")))
		wolf_error(CANT_OPEN_WINDOW);
	return (mlx);
}

void	should_we_draw_it(t_img *image, void *wptr)
{
	if (image->on == TRUE)
		mlx_put_image_to_window(image->mptr, wptr, image->iptr,
				image->begin->x, image->begin->y);
}

void	draw_layers(t_wolf *w)
{
	should_we_draw_it(&w->layers->background, w->mlx.wptr);
	should_we_draw_it(&w->layers->d_labyrinth, w->mlx.wptr);
	should_we_draw_it(&w->layers->d_player, w->mlx.wptr);
	should_we_draw_it(&w->layers->map_view, w->mlx.wptr);
	should_we_draw_it(&w->layers->mask, w->mlx.wptr);
}

void	set_modes_false(t_dem *d)
{
	d->norm->intence = 0;
	d->wave->on = FALSE;
	d->wave->intence = 0;
	d->quake->on = FALSE;
	d->quake->intence = 0;
	d->fisheye->on = FALSE;
	d->fisheye->intence = 0;
	d->mirr->on = FALSE;
	d->mirr->intence = 0;
}

int		draw_all_hook(t_wolf *w)
{
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	(w->player.move.camera == KEY_ARROW_RIGHT ? w->player.look_column_angle.x += 0.05 : 1);
	(w->player.move.camera == KEY_ARROW_LEFT ? w->player.look_column_angle.x -= 0.05 : 1);
	(w->player.move.camera == KEY_ARROW_UP ? w->player.move.camera_up += 0.02 : 0);
	(w->player.move.camera == KEY_ARROW_DOWN ? w->player.move.camera_up -= 0.02 : 0);
	if (w->dem->norm->on == TRUE)
		set_modes_false(w->dem);
	if (w->dem->quake->on != FALSE)
		w->player.look_column_angle.y += 0.01 * w->dem->quake->intence;
	if (w->dem->wave->on != FALSE)
		w->player.look_column_angle.y += 0.03;
	clear_dinamic_img(w->layers);
	player_move(w);
	draw_player(w);
	render_rays(w);
	render_walls(w);
//	test_text(w);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	draw_layers(w);
	return (0);
}

int		count_intence(int k, int x, int y, t_wolf *w)
{
	if (k == SCROLL_UP)
	{
		if (w->dem->quake->on != FALSE)
			w->dem->quake->intence++;
		if (w->dem->wave->on != FALSE)
			w->dem->wave->intence++;
	}
	if (k == SCROLL_DOWN)
	{
		if (w->dem->quake->on != FALSE)
			w->dem->quake->intence--;
		if (w->dem->wave->on != FALSE)
			w->dem->wave->intence--;
	}
	return (0);
}

void	check_hooks_loops(t_wolf *wolf)
{
	mlx_loop_hook(wolf->mlx.mptr, &draw_all_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 17, 0, &close_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 2, 0, &key_press, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 3, 0, &key_unpress, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 4, 0, &count_intence, &wolf->mlx);
	mlx_loop(wolf->mlx.mptr);
}
