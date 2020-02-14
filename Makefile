# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 18:58:16 by cvernius          #+#    #+#              #
#    Updated: 2020/02/14 18:48:30 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://m.habr.com/ru/post/439698/

##### try to do default makefile laubching needed library in depends on OS #####

detected_OS := $(shell uname 2>/dev/null || echo Unknown)
detected_OS := $(patsubst CYGWIN%,Cygwin,$(detected_OS))
detected_OS := $(patsubst MSYS%,MSYS,$(detected_OS))
detected_OS := $(patsubst MINGW%,MSYS,$(detected_OS))cflags

NAME = wolf3d

SRC_DIR = SRCS

OBJ_DIR = OBJ

INCL_DIR = INCLUDES

ifeq ($(detected_OS),Darwin)
	SRC_DIR = $(addprefix MLX/,$(SRC_DIR))
	OBJ_DIR = $(addprefix MLX/,$(OBJ_DIR))
	INCL_DIR = $(addprefix MLX/,$(INCL_DIR))
endif

ifeq ($(detected_OS),Linux)
	SRC_DIR = $(addprefix SDL/,$(SRC_DIR))
	OBJ_DIR = $(addprefix SDL/,$(OBJ_DIR))
	INCL_DIR = $(addprefix SDL/,$(INCL_DIR))
endif

C_FILES = main.c drawing.c map_data.c raycast.c

ifeq ($(detected_OS),Linux)
	C_FILES += data_sdl.c
endif

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

# RAW_C_FILES = $(addprefix $(SRCS_DIR)/,$(C_FILES))

ifeq ($(detected_OS),Darwin)        # Mac OS X
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

ifeq ($(detected_OS),Linux)
	SDLCFLAGS := $(shell sdl2-config --cflags)
	SDLLFLAGS := $(shell sdl2-config --libs) $(shell sdl2-config --static-libs)    
endif

CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
# CFLAGS += -g
# CFLAGS += -O2

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)

	ifeq ($(detected_OS),Darwin)
		gcc $(RAW_OBJ_FILES) $(MLX_FLAGS) -o $(NAME)
	endif
	ifeq ($(detected_OS),Linux)   
		gcc $(RAW_OBJ_FILES) $(SDLLFLAGS) -o $(NAME)
	endif

						#############################
						#### К о м п и л я ц и я ####
						#############################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c

	ifeq ($(detected_OS),Darwin)
		gcc $(CFLAGS) -I $(INCL_DIR) -c $< -o $@
	endif
	ifeq ($(detected_OS),Linux)
		gcc $(CFLAGS) $(SDLCFLAGS) -I $(INCL_DIR) -c $< -o $@
	endif
	
clean:
	rm -rf $(RAW_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all