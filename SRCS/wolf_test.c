#include "wolf3d.h"

// int		get_color(t_color color)
// {
// 	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
// }

void    draw_rect(t_color *img, int x, int y, int w, int h, t_color col, SDL_Renderer *renderer)
{
    int i;
	int j;
	t_vec2 offset;

	i = 0;
	while (i < w)
	{
	    j = 0;
	    while (j < h)
	    {
			offset.x = i + x;
			offset.y = j + y;
			img[offset.x + offset.y * IMG_W] = col;
			SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 0xFF);
			SDL_RenderDrawPoint(renderer, offset.x, offset.y);
	    	j++;
		}
		i++;
	}
}

void	test_wolf(t_sdl *sdl)
{
	int i;
	int j;
	int rect_w;
	int rect_h;
	int rect_x;
	int rect_y;
	t_color col;
	t_color *img;

	img = (t_color*)malloc(sizeof(t_color) * WIN_W * WIN_H);
	j = 0;
	rect_w = WIN_W / MAP_W;
	rect_h = WIN_H / MAP_H;
    char map[] = "0000222222220000"\
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
    while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			col.r = (double)(255 * j / WIN_H);
			col.g = (double)(255 * i / WIN_W);
			col.b = 0;
			img[i + j * WIN_W] = col;
			i++;
		}
		j++;
	}
	i = 0;
	j = 0;
	while (j < MAP_H)
	{
		i = 0;
		while (i < MAP_W)
		{
			while (map[i + j * MAP_W] == ' ')
				i++;
			rect_x = i * rect_w;
			rect_y = j * rect_h;
			draw_rect(img, rect_x, rect_y, rect_w, rect_h, (t_color){0, 255, 255}, sdl->renderer);
		}
		j++;
	}
}

int     main(void)
{
	t_sdl *sdl;

	sdl = init_sdl();
	int finished;
	finished = 1;
	printf("before_init\n");
	sdl = init_sdl();
	printf("after_init\n");
	while (finished)
	{
		SDL_PollEvent(&sdl->event);
		if (sdl->event.type == SDL_QUIT)
			finished = 0;
		clear_window_sdl(sdl);
		test_wolf(sdl);
		SDL_RenderPresent(sdl->renderer);
	}
	destroy_sdl(sdl);
	return (0);
}
