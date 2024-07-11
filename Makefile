# Basic variables
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast 
DEV_FLAGS = -g3

#Libraries
INC = -I ./include
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = ./lib/MLX42
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

libmlx = $(LIBMLX_DIR)/build/libmlx42.a
libft = $(LIBFT_DIR)/libft.a

SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR), \
			main.c \
			bg_validation.c \
			bg_validation_utils.c \
			border_validation.c \
			color.c \
			dda_loop.c \
			draw_background.c \
			draw_circle.c \
			draw_line.c \
			draw_rect.c \
			end_game.c \
			file_validation2.c \
			file_validation.c \
			file_validation_utils.c \
			game_loop.c \
			get_map.c \
			get_map_info.c \
			handle_free.c \
			handle_keymaps.c \
			init_data.c \
			init_gun.c \
			init_player.c \
			math_utils.c \
			minimap_player_movement_bonus.c \
			player_movement.c \
			print_error.c \
			render_background.c \
			render_minimap_bonus.c \
			render_player_minimap_bonus.c \
			render_scene.c \
			render_texture.c \
			render_utils.c \
			rotate_line.c \
			rotate_mouse_bonus.c \
			start_game.c \
			vertical_line.c)


OBJ_DIR = obj/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(libmlx) $(libft) 
	$(CC) $(CFLAGS) $(OBJ_FILES) $(INC) -o $(NAME) $(LIBFT) $(LIBMLX)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

$(libmlx):
	@if [ ! -f $(LIBMLX_DIR)/build/libmlx42.a ]; then \
		echo "MLX42 building..."; \
		cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4; \
	else \
		echo "MLX42 already built"; \
	fi

$(libft):
	@if [ ! -f $(LIBFT) ]; then \
		echo "Libft building..."; \
		make -C $(LIBFT_DIR) -j4; \
	else \
		echo "Libft already built"; \
	fi

clean:
	rm -rf obj
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(LIBMLX_DIR)/build

re: fclean all
