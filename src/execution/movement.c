/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:30:19 by diogofms          #+#    #+#             */
/*   Updated: 2025/01/04 10:03:16 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_new_orientation(t_game *data)
{
	data->map.player_orientx = cos(data->map.angle * M_PI / 180);
	data->map.player_orienty = sin(data->map.angle * M_PI / 180);
}

void	check_wall(t_game *data, double next_x_pos, double next_y_pos)
{
	if (data->map.grid[(int)next_y_pos][(int)data->map.player_x] != '1'
		&& data->map.grid[(int)data->map.player_y][(int)next_x_pos] != '1')
	{
		data->map.player_x = next_x_pos;
		data->map.player_y = next_y_pos;
		return ;
	}
	if (data->map.grid[(int)data->map.player_y][(int)next_x_pos] != '1')
		data->map.player_x = next_x_pos;
	else if (data->map.grid[(int)next_y_pos][(int)data->map.player_x] != '1')
		data->map.player_y = next_y_pos;
}

void	check_movement_part3(t_game *data, double next_x_pos, double next_y_pos)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		next_x_pos = next_x_pos - data->map.player_orientx * 0.1;
		next_y_pos = next_y_pos - data->map.player_orienty * 0.1;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		next_x_pos = next_x_pos + data->map.player_orientx * 0.1;
		next_y_pos = next_y_pos + data->map.player_orienty * 0.1;
	}
	check_wall(data, next_x_pos, next_y_pos);
	draw_image(data);
}

void	check_movement_part2(t_game *data)
{
	double	next_x_pos;
	double	next_y_pos;

	next_x_pos = data->map.player_x;
	next_y_pos = data->map.player_y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		next_x_pos = next_x_pos - data->map.player_orienty * 0.1;
		next_y_pos = next_y_pos + data->map.player_orientx * 0.1;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		next_x_pos = next_x_pos + data->map.player_orienty * 0.1;
		next_y_pos = next_y_pos - data->map.player_orientx * 0.1;
	}
	check_movement_part3(data, next_x_pos, next_y_pos);
}

void	check_movement(void *_data)
{
	t_game	*data;

	data = (t_game *)_data;
	if (fps_control() == 0)
		return ;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->map.angle += 2.5;
		if (data->map.angle > 360)
			data->map.angle -= 360;
		calculate_new_orientation(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->map.angle -= 1.5;
		if (data->map.angle < 0)
			data->map.angle += 360;
		calculate_new_orientation(data);
	}
	check_movement_part2(data);
}
