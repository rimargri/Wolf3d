/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:18:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/24 21:55:14 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;
	int		bp;
	int		size_line;
	int		endian;
	
	if (!(mlx.mptr = mlx_init()))
		wolf_error(MLX_POINTER);
	if (!(mlx.wptr = mlx_new_window(mlx.mptr, WIN_W, WIN_H, "WOLF3D\0")))
		wolf_error(CANT_OPEN_WINDOW);
	if (!(mlx.iptr = mlx_new_image(mlx.mptr, WIN_W, WIN_H)))
		wolf_error(IMG_ALLOC_ERR);
	if (!(mlx.img = (int*)mlx_get_data_addr(mlx.iptr, &bp, &size_line, &endian)))
		wolf_error(IMG_ALLOC_ERR);
	return (mlx);
}

int		draw_all_hook(t_wolf *w)
{
	(w->move.camera == KEY_ARROW_RIGHT ? w->player.look_column_angle += 0.05 : 1);
	(w->move.camera == KEY_ARROW_LEFT ? w->player.look_column_angle -= 0.05 : 1);
	player_move(w);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	draw_background(w);
	draw_walls(w);
	draw_player(w);
	render_rays(w);
	render_walls(w);
	// test_text(w);
	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->mlx.iptr, 0, 0);
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
