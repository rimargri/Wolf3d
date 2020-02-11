/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:41:05 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/11 20:10:44 by cvernius         ###   ########.fr       */
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
# define KEY_SPACE 49
# define KEY_A 0
# define KEY_D 2
# define KEY_W 1
# define KEY_S 13

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

typedef struct		s_reycast
{
	float			vec_dir;
	float			angle;
	float			t;
	t_player		player;
	t_vec2			len;
	t_ivec2			transform;
	int				current_pix;
	int				color;
}					t_reycast;

typedef struct		s_mlx
{
	void			*mptr;
	void			*wptr;
    char            *map;
}					t_mlx;

int					key_press(int k, t_mlx *mlx);
int					close_hook(void *param);
int					get_color(t_color color);
void				create_objects(t_mlx *mlx);
void    			draw_rect(t_ivec2 v, int w, int h, t_color col, t_mlx *mlx);
void				background_for_map(t_mlx *mlx);
void				walls_on_map(t_mlx *mlx, char *map);
t_player			player_on_map(t_mlx *mlx);
void				cast_ray(t_mlx *mlx, char *map, t_player player);

#endif
