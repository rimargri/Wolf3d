# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 20:07:51 by cvernius          #+#    #+#              #
#    Updated: 2020/02/18 20:36:43 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./SRCS

OBJ_DIR = ./OBJ

INCL_DIR = ./INCLUDES

C_FILES = main.c key_press.c draw_rect.c draw_map.c color.c render.c \
		player.c player_move.c validate.c \

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
# CFLAGS += -g
# CFLAGS += -O2

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)


$(NAME): $(RAW_OBJ_FILES)
	@gcc $(RAW_OBJ_FILES) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[38;2;200;150;200m (*≧ω≦*) \033[38;2;200;200;250m \
	Mama, ya peresobralsya \033[38;2;200;150;200m (*≧ω≦*)"

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(CFLAGS) -I $(INCL_DIR) -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all