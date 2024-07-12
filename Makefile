# Basic variables
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast 
DEPFLAGS = -MMD -MP
DEV_FLAGS = -g3
LEAKS = valgrind --leak-check=full --show-leak-kinds=all  --suppressions=./suppress.sup #--log-file=leaks.sup

#Libraries
INC = -I ./include
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = ./lib/MLX42
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a
LIBMLX_WITH_FLAGS = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

#Map file
MAP = ./maps/map.cub

SRC = src/main.c \
	  $(addprefix src/draw/, draw_background.c draw_circle.c draw_line.c draw_rect.c color.c) \
	  $(addprefix src/free/, handle_free.c) \
	  $(addprefix src/game/, end_game.c game_loop.c init_data.c start_game.c) \
	  $(addprefix src/input/, handle_keymaps.c) \
	  $(addprefix src/map/, bg_validation.c bg_validation_utils.c border_validation.c file_validation.c file_validation2.c file_validation_utils.c get_map.c get_map_info.c print_error.c) \
	  $(addprefix src/math/, math_utils.c rotate_line.c) \
	  $(addprefix src/movement/, minimap_player_movement_bonus.c player_movement.c rotate_mouse_bonus.c) \
	  $(addprefix src/player/, init_gun.c init_player.c) \
	  $(addprefix src/render/, dda_loop.c render_background.c render_minimap_bonus.c render_player_minimap_bonus.c render_scene.c render_texture.c render_utils.c vertical_line.c)

OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(SRC))))

DEP = $(OBJ:.o=.d)

OBJ_DIR = obj/

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

-include $(DEP)

$(LIBMLX):
	@if [ ! -f $(LIBMLX_DIR)/build/libmlx42.a ]; then \
		echo "MLX42 building..."; \
		cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4; \
	else \
		echo "MLX42 already built"; \
	fi

$(LIBFT):
	@if [ ! -f $(LIBFT) ]; then \
		echo "Libft building..."; \
		make -C $(LIBFT_DIR) -j4; \
	else \
		echo "Libft already built"; \
	fi

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
		$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBFT) $(LIBMLX_WITH_FLAGS) -o $(NAME)

play:
	@make
	./$(NAME) $(MAP)

val:
	@make
	$(LEAKS) ./$(NAME) $(MAP)

clean:
	rm -rf obj
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(LIBMLX_DIR)/build

re: fclean all

.PHONY: all clean fclean re play val
