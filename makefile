NAME = Cub3D
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INC = -I ./include
LIBFT_DIR = ./lib/libft/
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = ./lib/MLX42
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADER = ./include
SRCS_DIR = src/
OBJS_DIR = obj/
SRC_DIR_LIB = ./src/lib
INPUT_DIR = input/
DRAW_DIR = draw/
MAP_DIR = map/
INIT_DIR = init/


FILE = \
			 main \
			 $(INIT_DIR)init_game $(INIT_DIR)set_data \
			 $(INPUT_DIR)handle_keymaps \
			 $(DRAW_DIR)draw_rect \
			 $(MAP_DIR)get_map \


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
	mkdir -p $(OBJS_DIR)$(INIT_DIR)
	mkdir -p $(OBJS_DIR)$(INPUT_DIR)
	mkdir -p $(OBJS_DIR)$(DRAW_DIR)
	mkdir -p $(OBJS_DIR)$(MAP_DIR)

play:
	@make re 
	./$(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(LIBMLX_DIR)/build

re: fclean all

.PHONY: all clean fclean re
