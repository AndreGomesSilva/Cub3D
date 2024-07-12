# Basic variables
NAME = cub3D
BONUS = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
DEPFLAGS = -MMD -MP
DEV_FLAGS = -g3
LEAKS = valgrind --leak-check=full --show-leak-kinds=all  --suppressions=./suppress.sup #--log-file=leaks.sup

#Libraries
LIB_INC = -I./lib/MLX42/include/MLX42/ -I./lib/libft/include/
INC = -I./cub3d/include/ $(LIB_INC)
INC_BONUS = -I./cub3d_bonus/include/ $(LIB_INC)
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = ./lib/MLX42
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a
LIBMLX_WITH_FLAGS = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

#Map file
MAP = ./maps/map.cub

FILES = src/main.c \
	  $(addprefix src/draw/, draw_background.c draw_circle.c draw_line.c draw_rect.c color.c) \
	  $(addprefix src/free/, handle_free.c) \
	  $(addprefix src/game/, end_game.c game_loop.c init_data.c start_game.c) \
	  $(addprefix src/input/, handle_keymaps.c) \
	  $(addprefix src/map/, bg_validation.c bg_validation_utils.c border_validation.c file_validation.c file_validation2.c file_validation_utils.c get_map.c get_map_info.c print_error.c) \
	  $(addprefix src/math/, math_utils.c rotate_line.c) \
	  $(addprefix src/movement/, minimap_player_movement.c player_movement.c rotate_mouse.c) \
	  $(addprefix src/player/, init_gun.c init_player.c) \
	  $(addprefix src/render/, dda_loop.c render_background.c render_minimap.c render_player_minimap.c render_scene.c render_texture.c render_utils.c vertical_line.c)


SRC = $(addprefix cub3d/, $(addsuffix .c, $(basename $(FILES))))
SRC_BONUS = $(addprefix cub3d_bonus/, $(addsuffix _bonus.c, $(basename $(FILES))))

OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(SRC))))
OBJ_BONUS = $(addprefix obj_bonus/, $(addsuffix .o, $(basename $(SRC_BONUS))))

DEP = $(OBJ:.o=.d)
DEP_BONUS = $(OBJ_BONUS:.o=.d) 

OBJ_DIR = obj/
OBJ_BONUS_DIR = obj_bonus/

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_DIR)%.o:%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

$(OBJ_BONUS_DIR)%.o:%.c | $(OBJ_BONUS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_BONUS) -c $< -o $@
	
-include $(DEP)
-include $(DEP_BONUS)

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

$(BONUS): $(OBJ_BONUS) $(LIBFT) $(LIBMLX)
		$(CC) $(CFLAGS) $(OBJ_BONUS) $(INC_BONUS) $(LIBFT) $(LIBMLX_WITH_FLAGS) -o $(BONUS)

bonus: $(BONUS)

play:
	@make
	./$(NAME) $(MAP)

val:
	@make
	$(LEAKS) ./$(NAME) $(MAP)

clean:
	rm -rf obj
	rm -rf obj_bonus
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(LIBMLX_DIR)/build

re: fclean all

.PHONY: all clean fclean re play val bonus
