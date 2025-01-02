/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:37:28 by disilva           #+#    #+#             */
/*   Updated: 2025/01/02 12:46:07 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_image(t_game *data);
void	ray_vector(int window_column, t_game *data);
void	x_step_size(t_game *data);

void	calculate_camera_plane_length(t_game *data)
{
	data->ray_info.camera_plane_length = 2 * sin(FOV / 2 * (M_PI / 180));
}

void	run_game(t_game *data)
{
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_LENGTH, "cub3D", true);
	ft_mlx_error(*data);
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_LENGTH);
	ft_img_error(*data);
	mlx_key_hook(data->mlx, esc_hook, data);
	mlx_close_hook(data->mlx, close_window_hook, data);
	mlx_loop_hook(data->mlx, check_movement, data);
	calculate_camera_plane_length(data);
	convert_textures(data);
	get_color2(data);
	draw_image(data);
	mlx_loop(data->mlx);
}

void	draw_image(t_game *data)
{
	int	window_column;

	set_background(data);
	window_column = 0;
	while (window_column < WINDOW_WIDTH)
	{
		ray_vector(window_column, data);
		x_step_size(data);
		y_step_size(data);
		dda(data);
		wall_distance(data);
		draw_column(data, window_column);
		window_column++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void	ray_vector(int window_column, t_game *data)
{
	double	camera_posx;
	double	camera_planex;
	double	camera_planey;

	camera_posx = 2 * window_column / (double)WINDOW_WIDTH - 1;
	camera_planex = -data->map.player_orienty
		* data->ray_info.camera_plane_length / 2;
	camera_planey = data->map.player_orientx
		* data->ray_info.camera_plane_length / 2;
	data->ray_info.ray_dirx
		= data->map.player_orientx + camera_planex * camera_posx;
	data->ray_info.ray_diry
		= data->map.player_orienty + camera_planey * camera_posx;
}

void	x_step_size(t_game *data)
{
	data->ray_info.wall_x = (int)data->map.player_x;
	data->ray_info.dist_between_xlines = fabs(1 / data->ray_info.ray_dirx);
	if (data->ray_info.ray_dirx < 0)
	{
		data->ray_info.step_x_direct = -1;
		data->ray_info.step_x = (data->map.player_x
				- data->ray_info.wall_x)
			* data->ray_info.dist_between_xlines;
	}
	else
	{
		data->ray_info.step_x_direct = 1;
		data->ray_info.step_x = (data->ray_info.wall_x + 1.0
				- data->map.player_x)
			* data->ray_info.dist_between_xlines;
	}
}
