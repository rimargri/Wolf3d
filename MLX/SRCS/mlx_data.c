/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 22:18:12 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:57:35 by cvernius         ###   ########.fr       */
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

void	change_wolf(t_wolf *w)
{
	jump(w);
	(w->player.move.camera == KEY_ARROW_RIGHT ?
								w->player.look_column_angle.x += 0.05 : 1);
	(w->player.move.camera == KEY_ARROW_LEFT ?
								w->player.look_column_angle.x -= 0.05 : 1);
	(w->player.move.camera == KEY_ARROW_UP ?
								w->player.move.camera_up += 0.02 : 0);
	(w->player.move.camera == KEY_ARROW_DOWN ?
								w->player.move.camera_up -= 0.02 : 0);
	get_wolf_with_modes(w);
	clear_dinamic_img(w->layers);
}

int		draw_all_hook(t_wolf *w)
{
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	change_wolf(w);
	player_move(w);
	draw_player(w);
	render_rays(w);
	render_walls(w);
	draw_layers(w);
	if (w->layers->menu.on == TRUE)
		draw_menu(w);
	return (0);
}

int		move_player_mouse(int x, int y, t_wolf *w)
{
	static int		prev_x;
	int				param;

	if (x > WIN_W - 155 && x < WIN_W - 5 && y > 5 && y < 62)
	{
		w->layers->menu_button.on = TRUE;
		w->layers->button_mask.on = FALSE;
	}
	else
	{
		w->layers->menu_button.on = FALSE;
		w->layers->button_mask.on = TRUE;
	}
	if (w->mouse_angle == FALSE)
		return (0);
	param = y;
	if (prev_x < x)
		w->player.look_column_angle.x += 0.05 * (float)abs(prev_x - x) * 0.1;
	else if (prev_x > x)
		w->player.look_column_angle.x -= 0.05 * (float)abs(prev_x - x) * 0.1;
	prev_x = x;
	return (0);
}

void	check_hooks_loops(t_wolf *wolf)
{
	mlx_loop_hook(wolf->mlx.mptr, &draw_all_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 17, 0, &close_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 2, 0, &key_press, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 3, 0, &key_unpress, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 4, 0, &count_intence, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 5, 0, &click_mouse, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 6, 0, &move_player_mouse, &wolf->mlx);
	mlx_loop(wolf->mlx.mptr);
}
