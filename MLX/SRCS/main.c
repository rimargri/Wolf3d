/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 22:57:03 by cvernius         ###   ########.fr       */
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

t_direction	init_move(void)
{
	t_direction move;

	move.forward = FAULSE;
	move.back = FAULSE;
	move.right = FAULSE;
	move.left = FAULSE;
	move.camera = 0;
	return (move);
}

int		main(int ac, char **maps)
{
	printf("(*≧ω≦*) Mama, ya sobralsya o7\n");
	t_wolf *wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	((wolf == NULL) ? (exit(98)) : 1);
	// wolf->tmap = validate(ac, maps);
	wolf->mlx = init_mlx();
	wolf->map = get_map();
	wolf->move = init_move();
	wolf->space_was_pressed = 0;
	draw_background(wolf);
	draw_walls(wolf, wolf->map);
	init_player(wolf);
	draw_player(wolf);
	render_rays(wolf);
	render_walls(wolf);
	// texture_main();
	mlx_put_image_to_window(wolf->mlx.mptr, wolf->mlx.wptr, wolf->mlx.iptr, 0, 0);
	hooks_loops_mlx(wolf);
	return (0);
}

	// mlx_hook(mlx->win_ptr, 4, 0, &mouse_hook, mlx);
	// mlx_hook(mlx->win_ptr, 6, 0, &move_hook, mlx);