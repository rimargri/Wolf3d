# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 20:07:05 by cvernius          #+#    #+#              #
#    Updated: 2020/02/14 18:48:30 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./SRCS

OBJ_DIR = ./OBJ

INCL_DIR = ./INCLUDES

C_FILES = main.c data_sdl.c drawing.c map_data.c raycast.c

OBJ_FILES = $(C_FILES:.c=.o)

detected_OS := $(shell uname 2>/dev/null || echo Unknown)
detected_OS := $(patsubst CYGWIN%,Cygwin,$(detected_OS))
detected_OS := $(patsubst MSYS%,MSYS,$(detected_OS))
detected_OS := $(patsubst MINGW%,MSYS,$(detected_OS))

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

SDLCFLAGS := $(shell sdl2-config --cflags)
SDLLFLAGS := $(shell sdl2-config --libs)
ifeq ($(detected_OS),Darwin)        # Mac OS X
    SDLLFLAGS += -framework OpenGL -framework Cocoa -framework AppKit
endif
ifeq ($(detected_OS),Linux)
    SDLLFLAGS += $(shell sdl2-config --static-libs)
endif

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