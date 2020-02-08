#include "wolf3d.h"

t_sdl	*init_sdl(void)
{
	t_sdl *sdl;

	printf("1ya tut\n");
	sdl = (t_sdl*)malloc(sizeof(t_sdl));
	printf("%p\n", sdl);
	SDL_Init(SDL_INIT_VIDEO);
	printf("2ya tut\n");
	sdl->window = SDL_CreateWindow("WOLF3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
	if (!sdl->window)
		exit(98);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
	if (!sdl->renderer)
		exit(97);
	sdl->event = (SDL_Event){0};
	return (sdl);
}

void	destroy_sdl(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}

void	clear_window_sdl(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 0xFF); // задание цвета фона
    SDL_RenderClear(sdl->renderer);
}
