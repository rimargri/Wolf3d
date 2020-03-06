/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 22:15:31 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**		bp			: the number of bits per pixels.
**		size_line	: the size of a line times 4.
**		endian		: the endian - order of bytes (or sometimes bits) within a
**					binary representation of a number.
*/

t_wolf	*init_wolf(t_wolf *wolf, int ac, char **maps)
{
	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	((wolf == NULL) ? (wolf_error(MALLOC_ERROR)) : 1);
	wolf->map = validate(ac, maps);
	wolf->t = init_textures();
	wolf->mlx = init_mlx();
	wolf->dem = init_dem();
	wolf->space_was_pressed = 0;
	return (wolf);
}

int		main(int ac, char **maps)
{
	t_wolf *wolf;

	printf("(*≧ω≦*) Mama, ya sobralsya o7 (*≧ω≦*)\n");
	wolf = NULL;
	wolf = init_wolf(wolf, ac, maps);
	init_player(wolf);
	init_all_img(wolf);
	check_hooks_loops(wolf);
	return (0);
}
