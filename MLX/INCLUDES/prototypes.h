/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:36:18 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/06 19:51:28 by cvernius         ###   ########.fr       */
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
int					check_distance(t_vec2 len, t_map *map);
void				raycast(t_wolf *w, t_raycast r, int pix, float column_angle);
void	            raycast_mode(t_wolf *w, float t, t_vec2 len, int pix, int y_offset);
void	            render_walls_mode(t_wolf *w);

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
void				draw_background_on_map(t_wolf *w);
void				draw_texture_on_celling(t_wolf *w, t_texture *t);
void				draw_texture_on_floor(t_wolf *w, t_texture *t);

/** *********************************** **/
/** *********************************** **/
/**               color                 **/
/** *********************************** **/
/** *********************************** **/

int					wall_color(t_map *map, t_vec2 len);
int					get_color(t_color color);
int					color_of_wall(char c);
int					choice_color(t_wolf *w, char c);

/** *********************************** **/
/** *********************************** **/
/**         general functions           **/
/** *********************************** **/
/** *********************************** **/

void    			draw_rect(t_drawrect dr, int w, int h, t_img *d_labyrinth);
void				clear_wolf(t_wolf **w);

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
int					color_of_texture(t_wolf *w, char c);
t_texture           *choice_texture(t_wolf *w, char c);
int					x_start(t_vec2 offset, t_texture *t);
int					*scale_column(t_raycast r, int *column, int column_height);
void				full_column_texture(t_wolf *w, int *column, int column_height, int current_pix);
t_texture			*cardinal_points(t_wolf *w, t_vec2 len);

/** *********************************** **/
/** *********************************** **/
/**              images                 **/
/** *********************************** **/
/** *********************************** **/

void				init_all_img(t_wolf *w);
void				clear_dinamic_img(t_layer *layer);
void				put_layer_mask(t_img *image, t_img *mask);
void				put_color_mask(t_img *image, int mask, int x, int y);
void				clear_layer(t_img *image);
void				prepare_static_layers(t_wolf *w);
void				init_fractol(t_draw_fractal **f);
void				change_img_coord(t_img *img, t_ivec2 *begin);
void				draw_fractal(t_draw_fractal **fractal, t_img *f);
void				draw_layers(t_wolf *w);

/** *********************************** **/
/** *********************************** **/
/**           modes(dementions)         **/
/** *********************************** **/
/** *********************************** **/

t_dem				*init_dem(void);
void				get_wolf_with_modes(t_wolf *w);
int					count_intence(int k, int x, int y, t_wolf *w);
void	            raycast_mirror(t_wolf *w, float t, t_vec2 len, int pix, int y_offset);
void	            raycast_modes_text(t_wolf *w, t_raycast r, int pix, float column_angle);

#endif
