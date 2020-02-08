#ifndef WOLF_3D
# define WOLF_3D
#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
# define W 512
# define H 512
# define WIN_W 512
# define WIN_H 512
# define MAP_W 16
# define MAP_H 16
// # define RECT_W (WIN_W / MAP_W)
// # define RECT_H (WIN_H / MAP_H)
# define IMG_W WIN_W

typedef struct  	s_vec2
{
    int         	x;
    int         	y;
}               	t_vec2;

typedef struct  	s_color
{
    int         	r;
    int         	g;
    int         	b;
}               	t_color;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}					t_sdl;


t_sdl	*init_sdl(void);
// void	init_sdl(t_sdl *sdl);
void	destroy_sdl(t_sdl *sdl);
void	clear_window_sdl(t_sdl *sdl);

#endif
