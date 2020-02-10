# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 20:07:05 by cvernius          #+#    #+#              #
#    Updated: 2020/02/10 20:07:38 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./SRCS

OBJ_DIR = ./OBJ

INCL_DIR = ./INCLUDES

C_FILES = main.c data_sdl.c drawing.c map_data.c reycast.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

SDLCFLAGS := $(shell sdl2-config --cflags)
SDLLFLAGS := $(shell sdl2-config --libs) -framework OpenGL -framework Cocoa -framework AppKit #$(shell sdl2-config --static-libs)

# SDL_DIR = ./SDL2-2.0.9/

# SDL_INCL = $(SDL_DIR)/include

CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
# CFLAGS += -g
# CFLAGS += -O2

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	gcc $(RAW_OBJ_FILES) $(SDLLFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(CFLAGS) $(SDLCFLAGS) -I $(INCL_DIR) -c $< -o $@

clean:
	rm -rf $(RAW_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all