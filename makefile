NAME = Cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I ./include

SRCS_DIR = src/

OBJS_DIR = obj/
SRC_DIR_LIB = ./src/lib
LIBFT_DIR = ./libft/libft.a
LIBMLX_DIR = ./lib/MLX42
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADER = ./include

FILE = \
			 main \

OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(LIBMLX_DIR)/build

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
