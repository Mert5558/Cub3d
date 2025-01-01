# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 11:49:16 by amecani           #+#    #+#              #
#    Updated: 2025/01/01 16:32:51 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.silent:

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm 
LIBFT = includes/libft/libft.a
GNL = includes/GetNextLine/GNL.a

SRCS = src/main.c src/parsing/parser.c src/parsing/parser_file.c src/parsing/parser_color.c src/parsing/parser_map.c\
	   src/parsing/parser_utils.c\
	   src/parsing/parser_utils2.c\
	   src/parsing/parser_map_utils.c\

OBJS = $(SRCS:.c=.o)

MLX_URL = https://github.com/codam-coding-college/MLX42.git 
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a
MLX = ./MLX42/build/libmlx42.a
INCLUDE = -I./includes/libft -I./includes -I./MLX42

all: $(NAME)

$(LIBFT):
	@make -C includes/libft

$(GNL):
	@make -C includes/GetNextLine

$(NAME): $(MLX) $(OBJS) $(LIBFT) $(GNL)
	@$(CC) $(CFLAGS) $(MLX) $(MLX_FLAGS) $(LIBFT) $(GNL) $(OBJS) -o $(NAME) $(INCLUDE)

$(MLX):
	@if [ ! -d "MLX42" ]; then \
		git clone $(MLX_URL) && \
		cd MLX42 && cmake -B build && cmake --build build -j4; \
	fi

clean :
	@make -C includes/libft clean
	@make -C includes/GetNextLine clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C includes/libft fclean
	@make -C includes/GetNextLine fclean
	@rm -rf $(OBJECTS)
	@rm -rf $(NAME)
	@rm -rf ./MLX42

re: fclean all

re: fclean all

.PHONY: all clean fclean re