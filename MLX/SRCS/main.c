/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/18 22:41:51 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*get_map(void)
{
	char *map;
    
	map = (char*)malloc(sizeof(char) * 258);
	map   = "00    2222220000"\
			"                "\
			"       11111   0"\
			"1     0        0"\
			"0     0  1110000"\
			"0     3        0"\
			"0   10000      0"\
			"0   0   11100  0"\
			"0   0   0      0"\
			"0   0   1  00000"\
			"0       1      0"\
			"2       1      0"\
			"0       0      0"\
			"2 3000000      0"\
			"0              0"\
			"2  22222222 0000";
	return (map);
}

/*
**		bp			: the number of bits per pixels.
**		size_line	: the size of a line times 4.
**		endian		: the endian - order of bytes (or sometimes bits) within a
**					binary representation of a number.
*/

t_mlx	init_mlx(void)
{
	t_mlx	mlx;
	int		bp;
	int		size_line;
	int		endian;
	
	mlx.mptr = mlx_init();
	mlx.wptr = mlx_new_window(mlx.mptr, WIN_W, WIN_H, "WOLF3D\0");
	mlx.iptr = mlx_new_image(mlx.mptr, WIN_W, WIN_H);
	mlx.img = (int*)mlx_get_data_addr(mlx.iptr, &bp, &size_line, &endian);
	return (mlx);
}

int		draw_all_hook(t_wolf *w)
{
	(w->direction.camera == KEY_ARROW_RIGHT ? w->player.look_column_angle += 0.05 : 1);
	(w->direction.camera == KEY_ARROW_LEFT ? w->player.look_column_angle -= 0.05 : 1);
	player_move(w, &w->direction);
	mlx_clear_window(w->mlx.mptr, w->mlx.wptr);
	draw_background(w);
	draw_walls(w, w->map);
	draw_player(w);
	render(w);
	mlx_put_image_to_window(w->mlx.mptr, w->mlx.wptr, w->mlx.iptr, 0, 0);
	return (0);
}

int		main(int ac, char **maps)
{
	printf("(*≧ω≦*) Mama, ya sobralsya o7\n");
	t_wolf *wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	((wolf == NULL) ? (exit(98)) : 1);
	wolf->direction.move_r = FAULSE;
	wolf->direction.move_l = FAULSE;
	wolf->direction.move_f = FAULSE;
	wolf->direction.move_b = FAULSE;
	wolf->direction.camera = 0;
	wolf->mlx = init_mlx();
	wolf->map = get_map();
	wolf->space_was_pressed = 0;
	draw_background(wolf);
	draw_walls(wolf, wolf->map);
	init_player(wolf);
	draw_player(wolf);
	render(wolf);
	mlx_put_image_to_window(wolf->mlx.mptr, wolf->mlx.wptr, wolf->mlx.iptr, 0, 0);
	mlx_loop_hook(wolf->mlx.mptr, &test, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 17, 0, &close_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 2, 0, &key_press, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 3, 0, &key_unpress, &wolf->mlx);
	mlx_loop(wolf->mlx.mptr);
	return (0);
}
