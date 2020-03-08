/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:18:14 by hchau             #+#    #+#             */
/*   Updated: 2020/03/06 23:06:14 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
#define ERRORS_H
# define OK					0
# define MAX_MAP			1000000

/** *********************************** **/
/** *********************************** **/
/**         map is invalid	            **/
/** *********************************** **/
/** *********************************** **/

# define MISSING_ARG		"wolf3d: missing argument after call\n"\
							"usage: ./wolf3d [file]\n"
# define TOO_MUCH			"wolf3d: too much arguments, expected one\n"\
							"usage: ./wolf3d [file]\n"
# define MAP_SIMB			"wolf3d: map is invalid!\n"\
							"it should consist of only numbers and spaces\n"
# define SHAPE				"wolf3d: map is invalid!\n"\
							"shape of map should remind a square\n"
# define EMPTY				"wolf3d: map is empty!\n"\
							"it should consist of only numbers and spaces\n"
# define NOT_A_FILE			"wolf3d: can't open a map\n"
# define TOO_BIG			"wolf3d: map is too big! try to load another one\n"
# define DIRECTORY_ERR		"wolf3d: map can't be a directory!\n"\
							"wolf3d: please check path\n"
# define CLOSE_FD_ERROR		"wolf3d: fd close error\n"
# define NO_SPACE_FOR_PLAYER	"wolf3d: can't put player on map\n"\
							"please, check if map has any space for him!\n"
# define EXNTRA_X			"wolf3d: too much of \"x\" characters on map.\n"\
							"Game wrote for one player only. Please remove\n"\
							"extra position-indificators or delete them all.\n"

/** *********************************** **/
/** *********************************** **/
/**         texture errors	            **/
/** *********************************** **/
/** *********************************** **/

#define TEXTURE_LOAD		"wolf3d: can't load texture. Please, check the path.\n"\
							"Your image should be written in jpeg, pmg or bmp format.\n"
#define TEXTURE_CHANNELS	"wolf3d: can't load texture. Color channels conflict.\n"

/** *********************************** **/
/** *********************************** **/
/**         malloc errors	            **/
/** *********************************** **/
/** *********************************** **/

# define MALLOC_ERROR		"wolf3d: memory allocation error.\n"

/** *********************************** **/
/** *********************************** **/
/**         mlx errors		            **/
/** *********************************** **/
/** *********************************** **/

#define CANT_OPEN_WINDOW	"wolf3d: can't open window\n"
#define MLX_POINTER			"wolf3d: mlx error: can't initialize mlx-connetcion\n"
#define IMG_ALLOC_ERR		"wolf3d: image allocation error.\n"

#endif
