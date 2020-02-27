/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:38:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/27 14:08:49 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_WOLF3D
# define STRUCTS_WOLF3D
#include "wolf3d.h"

/** *********************************** **/
/** *********************************** **/
/**          general structs            **/
/** *********************************** **/
/** *********************************** **/

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
	int				color;
}					t_drawrect;

typedef struct		s_direction
{
	int				forward;
	int				back;
	int				right;
	int				left;
	int				camera;
}					t_direction;

/** *********************************** **/
/** *********************************** **/
/**         restricted structs          **/
/** *********************************** **/
/** *********************************** **/

typedef struct		s_map
{
	char			*line;
	int				h;
	int				w;
}					t_map;

typedef struct		s_player
{
	t_vec2			pos;
	t_ivec2			transform;
	float			look_column_angle;
}					t_player;

typedef struct		s_texture
{
	int				*texture;
	int				size;
	int				cnt;
	int				id;
}					t_texture;

typedef struct		s_load_t
{
	unsigned char 	*pixmap;
	int 			nchannels;
	int 			w;
	int 			h;
}					t_load_t;

typedef struct		s_raycast
{
	float			distance;
	t_vec2			len;
	// int				wall_color;
	t_texture		*t;
}					t_raycast;

typedef struct		s_mlx
{
	void			*mptr;
	void			*wptr;
	void			*iptr;
	int				*img;
}					t_mlx;

// typedef struct		s_image
// {
// 	void			*iptr;
// 	int				*img;
// }					t_image;

typedef struct		s_wolf
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_direction		move;
	t_texture		**t;
	int				space_was_pressed;
}					t_wolf;

#endif
