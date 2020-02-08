/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/08 19:37:43 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_test(t_sdl *sdl)
{
	char *map;
    
	map = (char*)malloc(sizeof(char) * 258);
	map   = "0000222222220000"\
			"1              0"\
			"1      11111   0"\
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
			"0 0000000      0"\
			"0              0"\
			"0002222222200000";
	background_for_map(sdl);
	walls_on_map(sdl, map);
}

int		main(void)
{
	t_sdl *sdl;
	int running;

	running = 1;
	sdl = init_sdl();
	while (running)
	{
		SDL_PollEvent(&sdl->event);
		if (sdl->event.type == SDL_QUIT)
			running = 0;
		clear_window_sdl(sdl);
		wolf_test(sdl);
		SDL_RenderPresent(sdl->renderer);
	}
	destroy_sdl(sdl);
	return (0);
}
