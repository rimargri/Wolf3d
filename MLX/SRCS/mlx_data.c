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

void	draw_layers(t_wolf *w)
{
	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->layers->background.iptr, 0, 0);
	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->layers->d_labyrinth.iptr, 0, 0);
	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->layers->d_player.iptr, 0, 0);
	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->layers->map_view.iptr, 0, 0);
}

int		draw_all_hook(t_wolf *w)
{
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	(w->player.move.camera == KEY_ARROW_RIGHT ? w->player.look_column_angle += 0.05 : 1);
	(w->player.move.camera == KEY_ARROW_LEFT ? w->player.look_column_angle -= 0.05 : 1);
	clear_dinamic_img(w->layers);//возникает проблема - придётся чистить лабиринт, чтобы не перерисовывать бэкграунд,
	//на нём остаются старые стены, раньше ты забивала имадж бэкграундом, теперь это у нас отдельный имадж
	player_move(w);
	draw_player(w);
	render_rays(w);
	render_walls(w);
	test_text(w);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	draw_layers(w);
	return (0);
}

void	check_hooks_loops(t_wolf *wolf)
{
	mlx_loop_hook(wolf->mlx.mptr, &draw_all_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 17, 0, &close_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 2, 0, &key_press, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 3, 0, &key_unpress, &wolf->mlx);
	mlx_loop(wolf->mlx.mptr);
}
