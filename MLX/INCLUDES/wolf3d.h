/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:41:05 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/20 16:28:37 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //!--------------------------------------------------------
#ifndef WOLF_3D
# define WOLF_3D
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "errors.h"
#include "stb_image.h"

/** *********************************** **/
/** *********************************** **/
/**         libs for reading            **/
/** *********************************** **/
/** *********************************** **/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/** *********************************** **/
/** *********************************** **/
/**         general defines             **/
/** *********************************** **/
/** *********************************** **/

# define WIN_W 1024
# define WIN_H 512
# define FOV M_PI / 3.0
# define FALSE -1

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

typedef struct		s_map
{
	char			*line;
	int				h;
	int				w;
}					t_map;

/** *********************************** **/
/** *********************************** **/
/**         restricted structs          **/
/** *********************************** **/
/** *********************************** **/

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

typedef struct		s_texture
{
	int				*texture;
	int				text_size;
	int				text_cnt;
}					t_texture;

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
	t_map			map;
	t_direction		move;
	int				space_was_pressed;
}					t_wolf;

/** *********************************** **/
/** *********************************** **/
/**         func for rendering          **/
/** *********************************** **/
/** *********************************** **/

void				render_rays(t_wolf *w);
void				render_walls(t_wolf *w);
void				raycast(t_wolf *w, float t, t_vec2 len, int pix);

/** *********************************** **/
/** *********************************** **/
/**            func for mlx             **/
/** *********************************** **/
/** *********************************** **/

t_mlx				init_mlx(void);
int					draw_all_hook(t_wolf *w);
void				check_hooks_loops(t_wolf *wolf);
int					key_unpress(int k, t_wolf *w);
int					key_press(int k, t_wolf *wolf);
int					close_hook(void *param);

/** *********************************** **/
/** *********************************** **/
/**           func for player           **/
/** *********************************** **/
/** *********************************** **/

void				init_player(t_wolf *w);
void				draw_player(t_wolf *w);
void				move_forward(t_wolf *w);
void				move_back(t_wolf *w);
void				move_right(t_wolf *w);
void				move_left(t_wolf *w);
int					check_f(t_wolf *w);
int					check_b(t_wolf *w);
int					check_r(t_wolf *w);
int					check_l(t_wolf *w);
void				player_move(t_wolf *w);

/** *********************************** **/
/** *********************************** **/
/**        primary map rendering        **/
/** *********************************** **/
/** *********************************** **/

void				draw_walls(t_wolf *w);
void				draw_background(t_wolf *w);

/** *********************************** **/
/** *********************************** **/
/**               color                 **/
/** *********************************** **/
/** *********************************** **/

t_color				wall_color(t_map *map, t_vec2 len);
int					get_color(t_color color);

/** *********************************** **/
/** *********************************** **/
/**         general function            **/
/** *********************************** **/
/** *********************************** **/

void    			draw_rect(t_drawrect v, int w, int h, t_mlx mlx);

/** *********************************** **/
/** *********************************** **/
/**            validation               **/
/** *********************************** **/
/** *********************************** **/

t_map				validate(int ac, char **maps);
int					rect_w(int w);
int					rect_h(int h);

// void				texture_main(void);

#endif
