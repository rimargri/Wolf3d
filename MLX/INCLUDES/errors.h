//
// Created by Hugor Chau on 2020-02-11.
//

#ifndef MLX_ERRORS_H
#define MLX_ERRORS_H
/*
**		map errors
*/
# define OK					0
# define MAX_MAP			10000//не хочу ГНЛ-ить, и не думаю, что
								//поддержка бòльших карт что-то даст,
								//кроме вечного подвисания
# define MISSING_ARG	"wolf3d: missing argument after call\n"\
						"usage: ./wolf3d [file]\n"

# define TOO_MUCH		"wolf3d: too much arguments, expected one\n"\
						"usage: ./wolf3d [file]\n"

# define MAP_SIMB		"wolf3d: map is invalid!\n"\
						"it should consist of only numbers and spaces\n"

# define SHAPE			"wolf3d: map is invalid!\n"\
						"shape of map should remind a square\n"

# define EMPTY			"wolf3d: map is empty!\n"\
						"it should consist of only numbers and spaces\n"

# define NOT_A_FILE		"wolf3d: can't open a map\n"
# define TOO_BIG		"wolf3d: map is too big! try to load another one\n"
# define DIRECTORY_ERR	"wolf3d: map can't be a directory!\n"\
						"wolf3d: please check path\n"


#endif
