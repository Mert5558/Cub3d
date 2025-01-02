/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:27:18 by disilva           #+#    #+#             */
/*   Updated: 2025/01/01 23:27:55 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	y_step_size(t_game *data)
{
	data->ray_info.wall_y = (int)data->map.player_y;
	data->ray_info.dist_between_ylines = fabs(1 / data->ray_info.ray_diry);
	if (data->ray_info.ray_diry < 0)
	{
		data->ray_info.step_y_direct = -1;
		data->ray_info.step_y = (data->map.player_y
				- data->ray_info.wall_y)
			* data->ray_info.dist_between_ylines;
	}
	else
	{
		data->ray_info.step_y_direct = 1;
		data->ray_info.step_y = (data->ray_info.wall_y + 1.0
				- data->map.player_y)
			* data->ray_info.dist_between_ylines;
	}
}

void	dda_x(t_game *data, bool *found_wall)
{
	if (data->map.grid[data->ray_info.wall_y]
		[data->ray_info.wall_x + data->ray_info.step_x_direct] == '1')
	{
		*found_wall = 1;
		data->ray_info.horizontal_wall = 0;
		data->ray_info.wall_x += data->ray_info.step_x_direct;
	}
	else
	{
		data->ray_info.step_x += data->ray_info.dist_between_xlines;
		data->ray_info.wall_x += data->ray_info.step_x_direct;
	}
}

void	dda_y(t_game *data, bool *found_wall)
{
	if (data->map.grid[data->ray_info.wall_y
			+ data->ray_info.step_y_direct]
		[data->ray_info.wall_x] == '1')
	{
		*found_wall = 1;
		data->ray_info.horizontal_wall = 1;
		data->ray_info.wall_y += data->ray_info.step_y_direct;
	}
	else
	{
		data->ray_info.step_y += data->ray_info.dist_between_ylines;
		data->ray_info.wall_y += data->ray_info.step_y_direct;
	}
}

void	dda(t_game *data)
{
	bool	found_wall;

	found_wall = 0;
	while (found_wall == 0)
	{
		if (data->ray_info.step_x < data->ray_info.step_y)
		{
			dda_x(data, &found_wall);
		}
		else
		{
			dda_y(data, &found_wall);
		}
	}
	if (data->ray_info.horizontal_wall == 1)
	{
		if (data->ray_info.step_y_direct == -1)
			data->ray_info.wall_y++;
	}
	else
	{
		if (data->ray_info.step_x_direct == -1)
			data->ray_info.wall_x++;
	}
}

void	wall_distance(t_game *data)
{
	if (data->ray_info.horizontal_wall == 1)
	{
		data->image_info.wall_distance = fabs((data->ray_info.wall_y
					- data->map.player_y) / data->ray_info.ray_diry);
		data->image_info.x_distance = data->ray_info.step_y
			* fabs(data->ray_info.ray_dirx);
		data->image_info.y_distance = 0;
	}
	else
	{
		data->image_info.wall_distance = fabs((data->ray_info.wall_x
					- data->map.player_x) / data->ray_info.ray_dirx);
		data->image_info.y_distance = data->ray_info.step_x
			* fabs(data->ray_info.ray_diry);
		data->image_info.x_distance = 0;
	}
}
