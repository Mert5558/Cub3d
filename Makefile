# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: disilva <disilva@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 11:49:16 by amecani           #+#    #+#              #
#    Updated: 2025/01/02 00:44:02 by disilva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.silent:

NAME = cub3D

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm 
LIBFT = includes/libft/libft.a
GNL = includes/GetNextLine/GNL.a

SRCS = src/main.c src/parsing/parser.c src/parsing/parser_file.c src/parsing/parser_map.c\
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

rmlx42:
	@rm -rf ./MLX42

re: fclean all

.PHONY: all clean fclean re rmlx42