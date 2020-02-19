/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:41:05 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/18 20:02:40 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //!--------------------------------------------------------
#ifndef WOLF_3D
# define WOLF_3D
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
//added headers for managing errors
#include "errors.h"
# define WIN_W 1024
# define WIN_H 512
# define MAP_W 16
# define MAP_H 16
# define RECT_W (WIN_W / 2 / MAP_W)
# define RECT_H (WIN_H / MAP_H)
# define FOV M_PI / 3.0

/** *********************************** **/
/** *********************************** **/
/**         defines for mlx             **/
/** *********************************** **/
/** *********************************** **/

# define HEIGHT 900
# define WIDTH 1200
# define KEY_ESC 53
// # define KEY_1 18
// # define KEY_2 19
# define KEY_SPACE 49
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
// # define KEY_ARROW_UP 126
// # define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

typedef struct		s_map
{
	char			*line;
	int				h;
	int				w;
}					t_map;

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

typedef struct		s_drawrect
{
	t_ivec2			firstpix;
	t_color			color;
}					t_drawrect;

typedef struct		s_player
{
	t_vec2			pos;
	t_ivec2			transform;
	float			look_column_angle;
}					t_player;

typedef struct		s_raycast
{
	float			distance;
	t_color			wall_color;
}					t_raycast;

typedef struct		s_mlx
{
	void			*mptr;
	void			*wptr;
	void			*iptr;
	int				*img;
}					t_mlx;

typedef struct		s_wolf
{
	t_mlx			mlx;
	t_player		player;
	char			*map;
	t_map			tmap;
	int				space_was_pressed;
}					t_wolf;

int					key_press(int k, t_wolf *wolf);
int					close_hook(void *param);
void				move_forward(t_wolf *w);
void				move_back(t_wolf *w);
void				move_right(t_wolf *w);
void				move_left(t_wolf *w);
int					get_color(t_color color);
void    			draw_rect(t_drawrect v, int w, int h, t_mlx mlx);
void				draw_background(t_wolf *w);
void				draw_walls(t_wolf *w, char *map);
void				draw_player(t_wolf *w);
void				cast_ray(t_wolf *w, char *map);
void				init_player(t_wolf *w);
void				player_move(t_wolf *w, int k);
t_color				wall_color(char *map, t_vec2 len);
t_map				validate(int ac, char **maps);
void				render(t_wolf *w);
void				raycast(t_wolf *w, float t, t_vec2 len, int pix);
void				draw_view(t_wolf *w, t_raycast r, int pix);

#endif
