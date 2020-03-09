# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 20:07:51 by cvernius          #+#    #+#              #
#    Updated: 2020/03/09 18:05:44 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
RED = \033[38;2;200;30;70m
YELLOW = \033[38;2;200;200;50m
GREEN = \033[38;2;0;200;0m

NAME = wolf3d

SRC_DIR = ./srcs

OBJ_DIR = ./obj

INCL_DIR = ./includes

C_FILES = check_player_move.c clear_wolf.c color.c draw_map.c draw_rect.c \
		  init_layer.c key_press.c load_texture.c main.c render_rays.c \
		  player.c player_move.c validate.c mlx_data.c layers.c fractal.c \
		  modes_for_fun.c mirror_floor.c wolf_error.c types_errors.c \
		  init_textures.c draw_text_back.c  render_walls.c render_texture.c \
		  cardinal_points.c default_textures.c custom_textures.c menu.c \
		  draw_menu.c init_modes.c write_map.c jump.c music.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

MLX_FLAGS = -L ./MinilibX -lm -lmlx -framework OpenGL -framework AppKit

LIBFT_FLAGS = -L libft/ -lft

CFLAGS = -Wall -Wextra -Werror

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	@make -C ./MinilibX
	@make -C ./libft
	@gcc $(RAW_OBJ_FILES) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya peresobralsya  $(PINK)(*≧ω≦*)"

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/*.h
	@gcc $(CFLAGS) -I $(INCL_DIR) -I ./MinilibX -I ./libft -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)
	@rm -rf ./libmlx/*.o
	@rm -rf ./libft/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf ./MinilibX/libmlx.a
	@rm -rf ./libft/libft.a

re: fclean all