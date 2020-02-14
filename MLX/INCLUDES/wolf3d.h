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
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
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
# define KEY_1 18
# define KEY_2 19
# define KEY_SPACE 49
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

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
	t_vec2			pos;
	t_ivec2			transform;
	float			look_column_angle;
}					t_player;

typedef struct		s_raycast
{
	float			player_column_angle;
	float			column_column_angle;
	float			t;
	t_player		player;
	t_vec2			len;
	t_ivec2			transform;
	int				current_pix;
	t_color			color;
}					t_raycast;

// typedef struct s_raycast {
// 	float distance;
// 	t_color wall_color;
// } t_raycast;

typedef struct		s_mlx
{
	void			*mptr;
	void			*wptr;
}					t_mlx;

typedef struct		s_wolf
{
	t_mlx			mlx;
	// t_raycast		r;
	t_player		player;
	char			*map;
}					t_wolf;

int					key_press(int k, t_wolf *wolf);
int					close_hook(void *param);
int					get_color(t_color color);
void				create_objects(t_wolf *w);
void    			draw_rect(t_ivec2 v, int w, int h, t_color col, t_mlx mlx);
void				draw_background(t_wolf *w);
void				draw_walls(t_wolf *w, char *map);
void				draw_player(t_wolf *w);
void				cast_ray(t_raycast r, t_wolf *w, char *map);
void				init_raycast(t_wolf *wolf);
void				init_player(t_wolf *w);
void				calc_player_pos(t_wolf *w, int k);
void				init_raycast(t_wolf *wolf);
t_color	raycast_color(t_raycast r, char *map);
t_raycast	raycast_data(t_raycast r, t_wolf *w);

#endif
