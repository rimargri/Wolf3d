/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/03 21:42:15 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**		bp			: the number of bits per pixels.
**		size_line	: the size of a line times 4.
**		endian		: the endian - order of bytes (or sometimes bits) within a
**					binary representation of a number.
*/

t_direction	init_move(void)
{
	t_direction move;

	move.forward = FALSE;
	move.back = FALSE;
	move.right = FALSE;
	move.left = FALSE;
	move.camera = 0;
	return (move);
}

int		main(int ac, char **maps)
{
	printf("(*≧ω≦*) Mama, ya sobralsya o7\n");
	t_wolf *wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	((wolf == NULL) ? (wolf_error(MALLOC_ERROR)) : 1);
	wolf->map = validate(ac, maps);
	
	// wolf->mlx = init_mlx();
	// wolf->t = init_textures();
	// // printf("main *** wolf->t = %p\twolf->t[0]->size = %d\n\n", wolf->t, wolf->t[0]->size);
	// wolf->move = init_move();
	// wolf->space_was_pressed = 0;
	// // draw_texture_on_background(wolf, wolf->t[5]);
	// // draw_background(wolf);
	// draw_background_on_map(wolf);
	// // draw_floor(wolf);
	// draw_texture_on_floor(wolf, wolf->t[7]);
	// // draw_celling(wolf);
	// draw_texture_on_celling(wolf, wolf->t[5]);
	// draw_walls(wolf);
	// init_player(wolf);
	// draw_player(wolf);
	// render_rays(wolf);
	// render_walls(wolf);
	// // test_text(wolf);
	// mlx_put_image_to_window(wolf->mlx.mptr, wolf->mlx.wptr, wolf->mlx.iptr, 0, 0);

	wolf->mlx = init_mlx();
	init_all_img(wolf);
	wolf->dem = init_dem();
	wolf->space_was_pressed = 0;
	init_player(wolf);

//	printf("\n%f\n", FOV);
	check_hooks_loops(wolf);
	return (0);
}

	// mlx_hook(mlx->win_ptr, 4, 0, &mouse_hook, mlx);
	// mlx_hook(mlx->win_ptr, 6, 0, &move_hook, mlx);
