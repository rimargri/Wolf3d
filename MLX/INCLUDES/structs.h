/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:38:39 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:43:20 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "wolf3d.h"

/*
** *********************************** **
** *********************************** **
**          general structs            **
** *********************************** **
** *********************************** **
*/

typedef struct			s_ivec2
{
	int					x;
	int					y;
}						t_ivec2;

typedef struct			s_vec2
{

	double				x;
	double				y;
}						t_vec2;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_drawrect
{
	t_ivec2				firstpix;
	int					color;
}						t_drawrect;

typedef struct			s_direction
{
	int					forward;
	int					back;
	int					right;
	int					left;
	float				camera_up;
	int					camera;
	int					jump;
	int					jump_h;
}						t_direction;

/*
** *********************************** **
** *********************************** **
**         restricted structs          **
** *********************************** **
** *********************************** **
*/

typedef struct			s_map
{
	char				*line;
	int					h;
	int					w;
}						t_map;

typedef struct			s_player
{
	t_vec2				pos;
	t_ivec2				transform;
	t_vec2				look_column_angle;
	t_direction			move;
}						t_player;

typedef struct			s_texture
{
	int					*texture;
	int					size;
	int					cnt;
	t_color				average_color;
}						t_texture;

typedef struct			s_load_t
{
	unsigned char		*pixmap;
	int					nchannels;
	int					w;
	int					h;
}						t_load_t;

typedef struct			s_raycast
{
	float				distance;
	t_vec2				len;
	int					wall_color;
	t_texture			*t;
}						t_raycast;

typedef struct			s_img
{
	int					on;
	size_t				pixels;
	void				*mptr;
	void				*iptr;
	int					*img;
	t_ivec2				*begin;
	t_ivec2				*size;
}						t_img;

typedef struct			s_mlx
{
	void				*mptr;
	void				*wptr;
}						t_mlx;

typedef struct			s_mode
{
	int					on;
	int					intence;
}						t_mode;

typedef struct			s_dem
{
	t_mode				*wave;
	t_mode				*quake;
	t_mode				*fisheye;
	t_mode				*mirr;
	t_mode				*norm;
	t_mode				*fract;
}						t_dem;

/*
** *********************************** **
** **********************************  **
**              fractal  		       **
** *********************************** **
** *********************************** **
*/

typedef struct			s_complex
{
	long double			x;
	long double			y;
}						t_complex;

typedef struct			s_fractal
{
	int					max_iteration;
	t_complex			k;
	t_complex			constant;
	t_complex			cur;
	int					color_shift;
}						t_fractal;

typedef struct			s_draw_fractal
{
	int					start_line;
	int					finish_line;
	int					is_mooving;
	t_img				*drawing;
	t_fractal			count;
}						t_draw_fractal;

typedef struct			s_layer
{
	float				draw_shift;
	int					count_layers;
	t_draw_fractal		*d_fractol;
	t_img				d_fractol_draw;
	t_img				d_labyrinth;
	t_img				d_player;
	t_img				map_view;
	t_img				background;
	t_img				mask;
	t_img				menu;
	t_img				menu_button;
	t_img				button_mask;
	t_img				menu_background;
}						t_layer;

typedef struct			s_wolf
{
	t_mlx				mlx;
	t_player			player;
	t_map				map;
	t_layer				*layers;
	t_texture			**t;
	int					text_id;
	t_dem				*dem;
	int					space_was_pressed;
	int					mouse_angle;
}						t_wolf;

#endif
