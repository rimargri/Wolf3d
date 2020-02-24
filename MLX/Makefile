# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 20:07:51 by cvernius          #+#    #+#              #
#    Updated: 2020/02/21 12:44:58 by cvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### colors #######
PINK = \033[38;2;200;150;200m
BLUE = \033[38;2;200;200;250m
RED = \033[38;2;200;30;70m
YELLOW = \033[38;2;200;200;50m
GREEN = \033[38;2;0;200;0m

NAME = wolf3d

SRC_DIR = ./SRCS

OBJ_DIR = ./OBJ

INCL_DIR = ./INCLUDES

C_FILES = main.c key_press.c draw_rect.c draw_map.c color.c raycast.c \
				render_rays.c player.c player_move.c check_player_move.c \
				validate.c mlx_data.c textures.c load_texture.c layers.c \
				clear_wolf.c

OBJ_FILES = $(C_FILES:.c=.o)

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
# CFLAGS += -g
# CFLAGS += -O2

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)


$(NAME): $(RAW_OBJ_FILES)
	@gcc $(RAW_OBJ_FILES) $(MLX_FLAGS) -o $(NAME)
	@echo "$(PINK)(*≧ω≦*)  $(BLUE)Mama, ya peresobralsya  $(PINK)(*≧ω≦*)"
###### ищем дефайны на задачи первой значимости ######
	@echo "$(RED)RED ALERT:"
	@grep '_FIXX_IMMIDIATLEY' ./**/* | sed '/./=' | sed '/./N; s/\n/ /'
	@echo "$(BLUE)RED ALERT:"
	@grep '//ЗДЕСЬ_MALLOC' ./**/* | sed '/./=' | sed '/./N; s/\n/ /'
###### ищем дефайны на задачи средней значимости ######
	@echo "$(YELLOW)LATER:"
	@grep '_FIXX_LATER' ./**/* | sed '/./=' | sed '/./N; s/\n/ /'
###### ищем дефайны на задачи наименьшей значимости ######
	@echo "$(GREEN)May be one day:"
	@grep '_FIXX_IF_YOU_WANNA' ./**/* | sed '/./=' | sed '/./N; s/\n/ /'
###### ищем дефайны на все задачи мира ######
	@echo "***************************************************************************\n"\
	"*** Flags: *** _FIXX_IMMIDIATLEY *** _FIXX_LATER *** _FIXX_IF_YOU_WANNA ***\n"\
	"***************************************************************************\n\n"\
	"Here are your tasks:\n" > ./FIX_ALL.txt
	@grep '_FIXX_' ./**/* | sed '/./=' | sed '/./N; s/\n/ /' >> ./FIX_ALL.txt

#### К о м п и л я ц и я ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(CFLAGS) -I $(INCL_DIR) -I ./MinilibX -c $< -o $@

clean:
	@rm -rf $(RAW_OBJ_FILES)
	@rm -rf ./libmlx/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf ./MinilibX/libmlx.a

re: fclean all