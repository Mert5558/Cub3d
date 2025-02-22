/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:03:01 by diogofms          #+#    #+#             */
/*   Updated: 2025/01/04 10:03:56 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	esc_hook(mlx_key_data_t key, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (key.action != MLX_PRESS && key.action != MLX_REPEAT)
		return ;
	if (key.key == MLX_KEY_ESCAPE)
	{
		free_textures(data);
		free_map2(data, data->map.height);
		mlx_delete_image(data->mlx, data->img);
		mlx_close_window(data->mlx);
		exit(0);
	}
}

void	close_window_hook(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	free_textures(data);
	free_map2(data, data->map.height);
	mlx_delete_image(data->mlx, data->img);
	mlx_close_window(data->mlx);
	exit(0);
}

bool	fps_control(void)
{
	static double	prev_time = 0;
	double			current_time;

	current_time = mlx_get_time();
	if (current_time - prev_time < (1.0 / 70.0))
		return (0);
	prev_time = current_time;
	return (1);
}
