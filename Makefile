NAME = wolf3d

# HEADERS = -I.

SRC_DIR = ./SRCS

OBJ_DIR = ./OBJ

INCL_DIR = ./INCLUDES

C_FILES = main.c wolf_test.c data_sdl.c draw_rectangle.c

OBJ_FILES = $(C_FILES:.c=.o)

# RAW_C_FILES = $(addprefix $(SRC_DIR)/,$(C_FILES))

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

SDLCFLAGS := $(shell sdl2-config --cflags)
SDLLFLAGS := $(shell sdl2-config --libs) -framework OpenGL -framework Cocoa -framework AppKit #$(shell sdl2-config --static-libs)

CFLAGS = -Wall -Wextra
# -Werror
CFLAGS += -O3

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