/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:41:05 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 11:41:44 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //!--------------------------------------------------------
#ifndef WOLF_3D
# define WOLF_3D
//#include "../MinilibX/mlx.h"
#include "prototypes.h"
#include "structs.h"
#include "errors.h"
 #include <mlx.h>
#include <stdlib.h>
#include <math.h>

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
# define TRUE 0
# define TEXTURE_MAX 10

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
# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

/** *********************************** **/
/** *********************************** **/
/**         defines for layers          **/
/** *********************************** **/
/** *********************************** **/

# define COUNT_LAYERS	5
# define NOCOLOR		0xFF000000

/** *********************************** **/
/** *********************************** **/
/**         defines for dementions      **/
/** *********************************** **/
/** *********************************** **/

//исключают друг друга
# define NORM_DEM			18
# define WAVES_DEM			19
# define EARTHQUAKE_DEM		20
//
# define MIRROR_DEM			21
# define FISHEYE_DEM		23
//# define GREEN_THEME		23
# define SCROLL_UP			5
# define SCROLL_DOWN		4

#endif
