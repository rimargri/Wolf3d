/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:36:18 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:39:31 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "structs.h"
# include "wolf3d.h"

/*
** *********************************** **
** *********************************** **
**         func for rendering          **
** *********************************** **
** *********************************** **
*/

void				render_rays(t_wolf *w);
void				render_walls(t_wolf *w);
int					check_distance(t_vec2 len, t_map *map);
void				raycast(t_wolf *w, t_raycast r, int pix, float col_angle);
void				raycast_mode(t_wolf *w, float t, t_vec2 len, int p, int y);
void				render_walls_mode(t_wolf *w);

/*
** *********************************** **
** *********************************** **
**            func for mlx             **
** *********************************** **
** *********************************** **
*/

t_mlx				init_mlx(void);
int					draw_all_hook(t_wolf *w);
void				check_hooks_loops(t_wolf *wolf);
int					key_unpress(int k, t_wolf *w);
int					key_press(int k, t_wolf *wolf);
int					close_hook(void *param);
void				draw_menu(t_wolf *w);
int					click_mouse(int button, int x, int y, t_wolf *w);

/*
** *********************************** **
** *********************************** **
**           func for player           **
** *********************************** **
** *********************************** **
*/

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
void				jump(t_wolf *w);

/*
** *********************************** **
** *********************************** **
**        primary map rendering        **
** *********************************** **
** *********************************** **
*/

void				draw_walls(t_wolf *w);
void				draw_background_on_map(t_wolf *w);
void				draw_texture_on_celling(t_wolf *w, t_texture *t);
void				draw_texture_on_floor(t_wolf *w, t_texture *t);

/*
** *********************************** **
** *********************************** **
**               color                 **
** *********************************** **
** *********************************** **
*/

int					wall_color(t_map *map, t_vec2 len);
int					get_color(t_color color);
int					color_of_wall(char c);
int					choice_color(t_wolf *w, char c);

/*
** *********************************** **
** *********************************** **
**         general functions           **
** *********************************** **
** *********************************** **
*/

void				draw_rect(t_drawrect dr, int w, int h, t_img *d_labyrinth);

/*
** *********************************** **
** *********************************** **
**            validation               **
** *********************************** **
** *********************************** **
*/

t_map				validate(int ac, char **maps);
int					rect_w(int w);
int					rect_h(int h);
void				prepare_map(t_map *map, char *src, int ret);

/*
** *********************************** **
** *********************************** **
**              errors                 **
** *********************************** **
** *********************************** **
*/

void				wolf_error(int	n);
void				write_error(char *reason);
void				arguments_errors(int n);
void				map_errors(int n);
void				player_errors(int n);
void				texture_errors(int n);
void				mlx_errors(int n);
void				malloc_errors(int n);

/*
** *********************************** **
** *********************************** **
**              textures               **
** *********************************** **
** *********************************** **
*/

t_texture			**init_textures(t_wolf *w, char *s);
void				malloc_text(t_texture **t, int count_text, int i);
void				render_texture(t_wolf *wolf, t_texture *t, t_ivec2 offset);
int					load_texture(char *filename, t_texture *t);
int					*texture_column(t_wolf *w, t_texture *t, int text_coord,
															int column_height);
int					color_of_texture(t_wolf *w, char c);
t_texture			*choice_texture(t_wolf *w, char c);
int					x_start(t_vec2 offset, t_texture *t);
int					*scale_column(t_raycast r, int *column, int column_height);
void				full_column_texture(t_wolf *w, int *column,
											int column_height, int current_pix);
t_texture			*choice_drawing_texture(t_wolf *w, t_vec2 len);
t_texture			*cardinal_points(t_wolf *w, t_vec2 len);
t_texture			*special_side(t_wolf *w, t_vec2 len);
void				change_textures(t_wolf *w);
void				text_floor(t_texture *t);
void				text_celling(t_texture *t);
void				text_panelki(t_texture **t);
void				text_evangelion(t_texture **t);
void				text_pepe(t_texture **t);
void				text_memes(t_texture **t);

/*
** *********************************** **
** *********************************** **
**              images                 **
** *********************************** **
** *********************************** **
*/

void				init_all_img(t_wolf *w);
void				put_layer_mask(t_img *image, t_img *mask);
void				put_color_mask(t_img *image, int mask, int x, int y);
void				prepare_static_layers(t_wolf *w);
void				init_fractol(t_draw_fractal **f);
void				change_img_coord(t_img *img, t_ivec2 *begin);
void				draw_fractal(t_draw_fractal **fractal, t_img *f);
void				draw_layers(t_wolf *w);
void				open_menu_image(t_img *image, char *filename,
								int size_x, int size_y);
void				draw_menu(t_wolf *w);
void				change_button_intence(int x, int y, t_wolf *w);
void				prepare_menu_img(t_wolf *w);

/*
** *********************************** **
** *********************************** **
**           modes(dementions)         **
** *********************************** **
** *********************************** **
*/

t_dem				*init_dem(void);
void				get_wolf_with_modes(t_wolf *w);
int					count_intence(int k, int x, int y, t_wolf *w);
void				raycast_mirror(t_wolf *w, float t, t_vec2 len, int pix,
																int y_offset);
void				raycast_modes_text(t_wolf *w, t_raycast r, int pix,
															float column_angle);
void				raycast_mirr_jump(t_wolf *w, t_raycast r, int pix,
															float column_angle);
void				full_column_texture_mirr(t_wolf *w, int *column,
						int column_height, t_ivec2 offset);
int					find_offset(t_raycast r, t_wolf *w);
void				full_column_texture_mode(t_wolf *w, int *column,
						int column_height, t_ivec2 offset);
void				change_music(t_wolf *w);
void				torn_music_on(int x, int y, t_wolf *w);
void				set_modes_false(t_dem *d);
void				change_dems(t_wolf *w, t_mode *mode);

/*
** *********************************** **
** *********************************** **
**          	 clear		           **
** *********************************** **
** *********************************** **
*/

void				clear_texture(t_texture **t);
void				clear_wolf(t_wolf **w);
void				clear_dinamic_img(t_layer *layer);
void				clear_layer(t_img *image);

#endif
