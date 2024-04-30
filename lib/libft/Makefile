# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angomes- <angomes-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 19:52:35 by angomes-          #+#    #+#              #
#    Updated: 2024/04/30 17:31:57 by angomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
INC = -I ./include
RM = rm -rf

FILES =\
	ft_strlen \
	ft_memcpy \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_strlcpy \
	ft_strncmp \
	ft_tolower \
	ft_toupper \
	ft_isprint \
	ft_atoi	\
	ft_strlcat \
	ft_memmove \
	ft_memset \
	ft_memcmp \
	ft_memchr \
	ft_strchr \
	ft_strrchr \
	ft_strnstr \
	ft_bzero \
	ft_strdup \
	ft_calloc \
	ft_substr \
	ft_strjoin \
	ft_striteri \
	ft_strmapi \
	ft_itoa \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_strtrim	\
	ft_split \
	ft_lstnew_bonus \
	ft_lstadd_front_bonus \
	ft_lstsize_bonus \
	ft_lstlast_bonus \
	ft_lstadd_back_bonus \
	ft_lstdelone_bonus \
	ft_lstclear_bonus \
	ft_lstiter_bonus \
	ft_lstmap_bonus \

OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
