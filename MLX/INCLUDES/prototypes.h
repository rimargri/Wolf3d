/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:36:18 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/27 16:53:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_WOLF3D
# define PROTOTYPES_WOLF3D
#include "structs.h"
#include "wolf3d.h"

/** *********************************** **/
/** *********************************** **/
/**         func for rendering          **/
/** *********************************** **/
/** *********************************** **/

void				render_rays(t_wolf *w);
void				render_walls(t_wolf *w);

void				raycast(t_wolf *w, t_raycast r, int pix, float column_angle); // raycast_rexture
// void				raycast(t_wolf *w, float t, t_vec2 len, int pix); //raycast color

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
t_vec2				first_empty_place(t_wolf *w);
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

int					wall_color(t_map *map, t_vec2 len);
int					get_color(t_color color);

/** *********************************** **/
/** *********************************** **/
/**         general functions           **/
/** *********************************** **/
/** *********************************** **/

void    			draw_rect(t_drawrect v, int w, int h, t_wolf *wolf);

/** *********************************** **/
/** *********************************** **/
/**            validation               **/
/** *********************************** **/
/** *********************************** **/

t_map				validate(int ac, char **maps);
int					rect_w(int w);
int					rect_h(int h);

/** *********************************** **/
/** *********************************** **/
/**              textures               **/
/** *********************************** **/
/** *********************************** **/

t_texture			**init_textures(void);
void 				render_texture(t_wolf *wolf, t_texture *t, t_ivec2 offset);
int					load_texture(char *filename, t_texture *t);
int		            *texture_column(t_wolf *w, t_texture *t, int text_coord, int column_height);
// void				test_text(t_wolf *w);
int					color_of_texture(t_wolf *w, char c);
t_texture           *choice_texture(t_wolf *w, char c);
// void               	draw_texture(t_wolf *w, t_vec2 len, t_texture *t, int column_height, int pix);
int					x_start(t_vec2 offset, t_texture *t);
int					*scale_column(t_raycast r, int *column, int column_height);
void				full_column_texture(t_wolf *w, int *column, int column_height, int current_pix);
void				draw_texture_on_background(t_wolf *w, t_texture *t);

#endif