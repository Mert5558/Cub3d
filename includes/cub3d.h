/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:03:59 by merdal            #+#    #+#             */
/*   Updated: 2025/01/04 13:32:33 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "GetNextLine/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define WINDOW_WIDTH 800
# define WINDOW_LENGTH 600
# define FOV 60
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_texture
{
	mlx_texture_t	*texture;
	char			*path;

}	t_texture;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	a;

}	t_color;

typedef struct s_map
{
	int		player_num;
	int		width;
	int		height;
	char	**grid;
	float	player_x;
	float	player_y;
	float	player_orientx;
	float	player_orienty;
	int		angle;
}	t_map;

typedef struct s_ray_info
{
	double	ray_dirx;
	double	ray_diry;
	double	dist_between_xlines;
	double	dist_between_ylines;
	double	step_x;
	double	step_y;
	int		step_x_direct;
	int		step_y_direct;
	int		wall_x;
	int		wall_y;
	bool	horizontal_wall;
	double	camera_plane_length;
}	t_ray_info;

typedef struct s_picture
{
	t_texture	n_texture;
	t_texture	w_texture;
	t_texture	e_texture;
	t_texture	s_texture;
	t_color		celing_color;
	t_color		floor_color;
}	t_picture;

typedef struct s_image_info
{
	double	wall_distance;
	int		floor_color;
	int		celing_color;
	double	x_distance;
	double	y_distance;
}	t_image_info;

typedef struct s_draw_column
{
	int				wall_heigth;
	int				wall_bottom;
	int				wall_top;
	int				y_cord;
	double			wall_x_cord;
	double			wall_y_cord;
	double			pixel_step_y;
	mlx_texture_t	*texture;
}	t_draw_column;

typedef struct s_parse
{
	int		i;
	int		found;
	bool	found_2;
}	t_parse;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			map;
	t_picture		pic;
	t_ray_info		ray_info;
	t_image_info	image_info;
}	t_game;

void	parser(t_game *game, char *input_file);
void	file_info(t_game *game, char **file);
char	*get_path(char *str);
void	get_color(t_game *game, char *file_str, char **file);
int		check_map(char *file_str);
void	get_map(char **file, int i, t_game *game);
int		check_map_wall(t_map *map);
char	*get_path(char *str);
void	error_exit(char *str, int exit_num);
void	error_exit_free(char *str, int exit_num, char **array, t_game *game);
void	free_char_array(char **array);
void	free_game(t_game *game);
int		map_space(t_map *map, char **file, int i);
int		process_n_texture(char *line, t_game *data);
int		process_s_texture(char *line, t_game *data);
int		process_w_texture(char *line, t_game *data);
int		process_e_texture(char *line, t_game *data);
int		process_floor_color(char *line, t_game *data);
int		process_celing_color(char *line, t_game *data);
int		check_param(int argc, char **argv);
void	esc_hook(mlx_key_data_t key, void *param);
void	check_movement(void *_data);
void	get_color2(t_game *data);
void	run_game(t_game *data);
void	ft_mlx_error(t_game *data);
void	ft_img_error(t_game *data);
void	convert_textures(t_game *data);
void	set_background(t_game *data);
void	draw_column(t_game *data, int x_cord);
void	free_map2(t_game *data, int i);
void	free_textures(t_game *data);
void	draw_image(t_game *data);
void	player_orientation(char player, t_map *map, int x, int j);
int		process_texture(char *line, t_texture *texture);
void	y_step_size(t_game *data);
void	dda(t_game *data);
void	wall_distance(t_game *data);
int		texture_pixel_color(double x, double y, mlx_texture_t *texture);
void	draw_horizontal(t_game *data, t_draw_column	*d);
void	draw_vertical(t_game *data, t_draw_column *d);
int		skip_empty_spaces(int *i, char *line);
int		str_end_pos(char *str);
int		check_png_ending(char *path, int i);
void	close_window_hook(void *param);
bool	fps_control(void);
void	initialize_vaiables(t_game *game);
void	bad_char(t_map *map, int j, t_game *game);
#endif