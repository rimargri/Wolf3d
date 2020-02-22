/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:38:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 12:48:18 by cvernius         ###   ########.fr       */
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
	t_color			color;
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
	t_direction		move;
	float			look_column_angle;
}					t_player;

typedef struct		s_raycast
{
	float			distance;
	t_color			wall_color;
}					t_raycast;

typedef struct		s_texture
{
	int				*texture;
	int				text_size;
	int				text_cnt;
}					t_texture;

typedef struct		s_img
{
	int				on;
	size_t			size;
	void			*mptr;
	void			*iptr;
	int				*img;
	t_ivec2			begin;
}					t_img;

//_FIXX_IMMIDIATLEY: переписать под 2 имаджа - карту и экран
typedef struct		s_mlx
{
	void			*mptr;
	void			*wptr;
//	void			*iptr;
//	int				*img;
}					t_mlx;

//все динамичные изображения я отмечаю как d_, это значит, что их
//необходимо обнулять и переписывать каждый раз после ивентов
typedef struct		s_layer
{
	int				count_layers;	//в wolf.h есть дефайн, здесь просто для наглядности
	t_img			d_labyrinth;
	t_img			d_player;//чтобы не перерисовывать мапу каждый раз
	t_img			map_view;
	t_img			background;

	t_img			mask;//допустим, на фрактал, или для смены цвета/интенсивности ВСЕГО НАХУЙ
//будем расширять здесь до бесконечности - на сколько креатива хватит
}					t_layer;

typedef struct		s_wolf
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_layer			*layers;//все имаджи, где хочешь, там рисуешь
	t_texture		**t;
	int				space_was_pressed;
}					t_wolf;

#endif
