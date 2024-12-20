/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:03:59 by merdal            #+#    #+#             */
/*   Updated: 2024/12/20 13:28:01 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "GetNextLine/get_next_line.h"
// # include "MLX42.h" // *Fix later (to make it more estheticallty looin)
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_exec
{
	mlx_texture_t	*wall[4];

}	t_exec;

typedef struct s_rgba
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}t_rgba;

typedef struct s_texture
{
	int		width;
	int		height;
	t_rgba	**grid;
}t_texture;

typedef struct s_map
{
	int		player_num;
	int		width;
	int		height;
	char	**grid;
}t_map;

typedef struct s_game
{
	t_texture	textures[4];
	t_rgba		floor_color;
	t_rgba		ceil_color;
	t_map		map;
}t_game;

//-----------------Parsing-----------------
void	parser(t_game *game, char *input_file);
void	file_info(t_game *game, char **file);
char	*get_path(char *str);
void	get_color(t_game *game, char *file_str);
int		check_map(char *file_str);
t_map	get_map(char **file, int i);

#endif