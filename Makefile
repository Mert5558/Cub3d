# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 11:49:16 by disilva           #+#    #+#              #
#    Updated: 2025/01/04 13:54:06 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.silent:

NAME = cub3D

CC = cc
INCLUDE = -I./includes/Libft/src -I./includes/get_next_line/src -I./includes -I./MLX42
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror $(INCLUDE)
MLX_FLAGS = -ldl -lglfw -pthread -lm 
LIBFT = includes/Libft/libft.a

SRCS = src/main.c src/parsing/parser.c src/parsing/parser_file.c src/parsing/parser_map.c\
	   includes/get_next_line/src/get_next_line.c includes/get_next_line/src/get_next_line_utils.c\
	   src/parsing/parser_utils.c src/parsing/parser_utils2.c src/parsing/parser_map_utils.c src/parsing/process_textures.c\
		src/execution/calculate_rays.c src/execution/errors.c src/execution/keys.c \
        src/execution/movement.c src/execution/image.c src/parsing/check_params.c \
		 src/parsing/parser_color.c src/execution/calculate_rays_2.c src/execution/image_2.c \
		 src/parsing/process_textures_utils.c src/parsing/process_textures_2.c

OBJS = $(SRCS:.c=.o)

MLX_URL = https://github.com/codam-coding-college/MLX42.git 
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a
MLX = ./MLX42/build/libmlx42.a

all: $(NAME)

$(LIBFT):
	@make -C includes/Libft

init-submodules:
	@if [ ! -d "includes/Libft/.git" ]; then \
		git submodule update --init --recursive; \
	fi

$(NAME): init-submodules $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	@if [ ! -d "MLX42" ]; then \
		git clone $(MLX_URL) && \
		cd MLX42 && cmake -B build && cmake --build build -j4; \
	fi

clean :
	@make -C includes/Libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C includes/Libft fclean
	@rm -rf $(OBJECTS)
	@rm -rf $(NAME)

rmlx42:
	@rm -rf ./MLX42

re: fclean all

.PHONY: all clean fclean re rmlx42 init-submodules