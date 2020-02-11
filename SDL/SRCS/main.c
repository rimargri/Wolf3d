/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/10 16:20:42 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*get_map(void)
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
	return (map);
}

void	create_objects(t_sdl *sdl, char *map)
{
	t_player player;

	background_for_map(sdl);
	walls_on_map(sdl, map);
	player = player_on_map(sdl); //! проинициализировать player в начале т к потом камера будет двигаться -> будут меняться значения
	// printf("player.x = %d\nplayer.y = %d\n", player.x, player.y);
	cast_ray(sdl, map, player);
}

int		main(void)
{
	t_sdl *sdl;
	// int running;
	char *map;

	// running = 1;
	map = get_map();
	sdl = init_sdl();
	while (1)
	{
		clear_window_sdl(sdl);
		create_objects(sdl, map);
		SDL_RenderPresent(sdl->renderer);
		while (SDL_PollEvent(&sdl->event))
		{
			if ((sdl->event.type == SDL_KEYDOWN && sdl->event.key.keysym.sym == SDLK_ESCAPE) ||
														(sdl->event.type == SDL_QUIT))
			{
				destroy_sdl(sdl);
				return (0);
			}
		}
	}
	destroy_sdl(sdl);
	return (0);
}
