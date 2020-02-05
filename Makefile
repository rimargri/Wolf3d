NAME = wolf3d

# HEADERS = -I.

SRC_DIR = ./SRC

OBJ_DIR = ./OBJ

INCL_DIR = ./INCLUDES

C_FILES = wolf_test.c data_sdl.c

OBJ_FILES = $(C_FILES:.c=.o)

# RAW_C_FILES = $(addprefix $(SRC_DIR)/,$(C_FILES))

RAW_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

SDLCFLAGS := $(shell sdl2-config --cflags)
SDLLFLAGS := $(shell sdl2-config --libs)

CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(RAW_OBJ_FILES)
	gcc -lc --entry main -nostartfiles $(RAW_OBJ_FILES) $(CFLAGS) $(SDLCFLAGS) $(SDLLFLAGS) -I $(INCL_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -lc --entry main -nostartfiles $(CFLAGS) $(SDLCFLAGS) $(SDLLFLAGS) -I $(INCL_DIR) -c $< -o $@

clean:
	rm -rf $(RAW_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all