/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 13:07:48 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**		bp			: the number of bits per pixels.
**		size_line	: the size of a line times 4.
**		endian		: the endian - order of bytes (or sometimes bits) within a
**					binary representation of a number.
*/

//void	put_layers(t_layer *layer)
//{
//	wolf_error("Priv!");
//}

int		main(int ac, char **maps)
{
	printf("(*≧ω≦*) Mama, ya sobralsya o7\n");
	t_wolf *wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	((wolf == NULL) ? (wolf_error(MALLOC_ERROR)) : 1);
	wolf->map = validate(ac, maps);
	wolf->mlx = init_mlx();
	init_all_img(wolf);
//	wolf->t = init_textures();
	wolf->space_was_pressed = 0;
	init_player(wolf);
//	printf("\n%f\n", FOV);
	check_hooks_loops(wolf);
	return (0);
}

	// mlx_hook(mlx->win_ptr, 4, 0, &mouse_hook, mlx);
	// mlx_hook(mlx->win_ptr, 6, 0, &move_hook, mlx);
