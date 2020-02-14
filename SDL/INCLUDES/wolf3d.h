/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:41:05 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/15 00:05:49 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //!--------------------------------------------------------
#ifndef WOLF_3D
# define WOLF_3D
#include <SDL.h>
#include <stdlib.h>
#include <math.h>
# define WIN_W 1024
# define WIN_H 512
# define MAP_W 16
# define MAP_H 16
# define RECT_W (WIN_W / MAP_W)
# define RECT_H (WIN_H / MAP_H)
# define FOV M_PI / 3.0

typedef struct  	s_ivec2
{
    int         	x;
    int         	y;
}               	t_ivec2;

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct  	s_color
{
    int         	r;
    int         	g;
    int         	b;
}               	t_color;

typedef struct		s_player
{
	t_ivec2			pos;
	t_ivec2			transform;
}					t_player;

typedef struct		s_raycast
{
	float			player_column_angle;
	float			column_angle;
	float			t;
	t_player		player;
	t_vec2			len;
	t_ivec2			transform;
	int				current_pix;
}					t_raycast;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}					t_sdl;

t_sdl		*init_sdl(void);
void		destroy_sdl(t_sdl *sdl);
void		clear_window_sdl(t_sdl *sdl);
void		wolf_test(t_sdl *sdl, char *map);
void		set_pixel(SDL_Renderer *ren, t_color col, int x, int y);
void    	draw_rect(t_ivec2 v, int w, int h, t_color col, SDL_Renderer *renderer);
void		background_for_map(t_sdl *sdl);
void		walls_on_map(t_sdl *sdl, char *map);
t_player	player_on_map(t_sdl *sdl);
void		cast_ray(t_sdl *sdl, char *map, t_player player);

#endif
