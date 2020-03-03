/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:18:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/03 21:48:58 by cvernius         ###   ########.fr       */
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
	// if (!(mlx.iptr = mlx_new_image(mlx.mptr, WIN_W, WIN_H)))
	// 	wolf_error(IMG_ALLOC_ERR);
	// if (!(mlx.img = (int*)mlx_get_data_addr(mlx.iptr, &bp, &size_line, &endian)))
	// 	wolf_error(IMG_ALLOC_ERR);
	return (mlx);
}

void	change_wolf(t_wolf *w)
{
	(w->player.move.camera == KEY_ARROW_RIGHT ? w->player.look_column_angle.x += 0.05 : 1);
	(w->player.move.camera == KEY_ARROW_LEFT ? w->player.look_column_angle.x -= 0.05 : 1);
	//__FIXX_IF_YOU_WANNA_подумать о повороте головы
	(w->player.move.camera == KEY_ARROW_UP ? w->player.move.camera_up += 0.02 : 0);
	(w->player.move.camera == KEY_ARROW_DOWN ? w->player.move.camera_up -= 0.02 : 0);
	get_wolf_with_modes(w);
	clear_dinamic_img(w->layers);
}

int		draw_all_hook(t_wolf *w)
{
// 	(w->move.camera == KEY_ARROW_RIGHT ? w->player.look_column_angle += 0.05 : 1);
// 	(w->move.camera == KEY_ARROW_LEFT ? w->player.look_column_angle -= 0.05 : 1);
// 	player_move(w);
// 	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
// 	// draw_texture_on_background(w, w->t[5]);
// 	// draw_background(w);
// 	draw_background_on_map(w);
// 	// draw_floor(w);
// 	draw_texture_on_floor(w, w->t[7]);
// 	// draw_celling(w);
// 	draw_texture_on_celling(w, w->t[5]);
// 	draw_walls(w);
// 	draw_player(w);
// 	render_rays(w);
// 	render_walls(w);
// 	// test_text(w);
// 	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->mlx.iptr, 0, 0);
// 	return (0);
// }

	change_wolf(w);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	player_move(w);
	draw_player(w);
	render_rays(w);
	//с модами
	render_walls_mode(w);
	//без модов
//    render_walls(w);
//	test_text(w);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	draw_layers(w);
	return (0);
}

int		move_player_mouse(int x, int y, t_wolf *w)
{
	static int		prev_x;

	if (prev_x < x)
		w->player.look_column_angle.x += 0.05;
	else if (prev_x > x)
		w->player.look_column_angle.x -= 0.05;
	prev_x = x;
	y = 0;
	x = 0;
	return (0);

}

void	check_hooks_loops(t_wolf *wolf)
{
	mlx_loop_hook(wolf->mlx.mptr, &draw_all_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 17, 0, &close_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 2, 0, &key_press, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 3, 0, &key_unpress, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 4, 0, &count_intence, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 6, 0, &move_player_mouse, &wolf->mlx);
	mlx_loop(wolf->mlx.mptr);
}
