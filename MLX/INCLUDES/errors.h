/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:18:14 by hchau             #+#    #+#             */
/*   Updated: 2020/02/20 14:25:46 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ERRORS_H
#define MLX_ERRORS_H
/*
**		map errors
*/
void	wolf_error(char *reason);
# define OK					0
# define MAX_MAP			1000000

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
# define MALLOC_ERROR		"wolf3d: memory allocation error.\n"
# define CLOSE_FD_ERROR		"wolf3d: fd close error\n"
# define MAP_IS_FULL		"wolf3d: can't put player on map\n"\
							"please, check if map has any space for him!\n"
#define IMG_ALLOC_ERR		"wolf3d: image allocation error.\n"
#define CANT_OPEN_WINDOW	"wolf3d: can't open window\n"
#define MLX_POINTER			"wolf3d: mlx error: can't initialize mlx-connetcion\n"

#endif