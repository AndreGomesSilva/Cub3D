# Basic variables
NAME = Cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
DEV_FLAGS = -g3
RM = rm -rf

# Valgrind with suppressions for MLX42_lib and send the output to leaks.sup file.
LEAKS = valgrind --leak-check=full --show-leak-kinds=all  --suppressions=./suppress.sup #--log-file=leaks.sup

# Directorys
LIBMLX_DIR = ./lib/MLX42
LIBFT_DIR = ./lib/libft/
HEADER = ./include
SRCS_DIR = src/
OBJS_DIR = obj/
DEV_OBJS_DIR = obj/
SRC_DIR_LIB = ./src/lib
INPUT_DIR = input/
DRAW_DIR = draw/
MAP_DIR = map/
GAME_DIR = game/
FREE_DIR = free/
RENDER_DIR = render/
MATH_DIR = math/
MOVEMENT_DIR = movement/
PLAYER_DIR = player/

#Libraries
INC = -I ./include
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Path to the game map
MAP = maps/map.cub

# Files to compile
FILE = \
			 main \
			 $(GAME_DIR)start_game $(GAME_DIR)init_data $(GAME_DIR)game_loop $(GAME_DIR)end_game \
			 $(INPUT_DIR)handle_keymaps \
			 $(PLAYER_DIR)init_player $(PLAYER_DIR)init_gun\
			 $(MOVEMENT_DIR)player_movement $(MOVEMENT_DIR)minimap_player_movement_bonus $(MOVEMENT_DIR)rotate_mouse_bonus \
			 $(DRAW_DIR)draw_rect $(DRAW_DIR)draw_circle $(DRAW_DIR)draw_line $(DRAW_DIR)color $(DRAW_DIR)draw_background \
			 $(RENDER_DIR)render_minimap_bonus $(RENDER_DIR)render_player_minimap_bonus $(RENDER_DIR)render_utils $(RENDER_DIR)render_background  \
			 $(RENDER_DIR)render_scene $(RENDER_DIR)render_texture $(RENDER_DIR)dda_loop $(RENDER_DIR)vertical_line \
			 $(MATH_DIR)rotate_line $(MATH_DIR)math_utils \
			 $(MAP_DIR)get_map $(MAP_DIR)get_map_info $(MAP_DIR)file_validation $(MAP_DIR)print_error $(MAP_DIR)file_validation2 \
			 $(MAP_DIR)bg_validation  $(MAP_DIR)bg_validation_utils $(MAP_DIR)file_validation_utils $(MAP_DIR)border_validation \
			 $(FREE_DIR)handle_free \

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

all: $(NAME)

libmlx:
	@if [ ! -f $(LIBMLX_DIR)/build/libmlx42.a ]; then \
		echo "MLX42 building..."; \
		cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4; \
	else \
		echo "MLX42 already built"; \
	fi

libft:
	@if [ ! -f $(LIBFT) ]; then \
		echo "Libft building..."; \
		make -C $(LIBFT_DIR) -j4; \
	else \
		echo "Libft already built"; \
	fi

$(NAME): libmlx libft $(OBJS)
	@if [ ! -f ./$(NAME) ]; then \
		$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) $(LIBMLX) -o $(NAME); \
	else \
		echo "Cub3D already built"; \
	fi

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)$(GAME_DIR)
	mkdir -p $(OBJS_DIR)$(INPUT_DIR)
	mkdir -p $(OBJS_DIR)$(PLAYER_DIR)
	mkdir -p $(OBJS_DIR)$(DRAW_DIR)
	mkdir -p $(OBJS_DIR)$(MAP_DIR)
	mkdir -p $(OBJS_DIR)$(FREE_DIR)
	mkdir -p $(OBJS_DIR)$(RENDER_DIR)
	mkdir -p $(OBJS_DIR)$(MATH_DIR)
	mkdir -p $(OBJS_DIR)$(MOVEMENT_DIR)

play: libft libmlx
	 @make &&./$(NAME) $(MAP)

val: all
	@$(LEAKS) ./$(NAME) $(MAP)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(LIBMLX_DIR)/build

re: fclean all

.PHONY: all clean fclean re libft mlx
