/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:26:37 by merdal            #+#    #+#             */
/*   Updated: 2025/01/04 11:22:53 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}

void	free_textures(t_game *data)
{
	if (data->pic.n_texture.path != NULL)
	{
		free (data->pic.n_texture.path);
		data->pic.n_texture.path = NULL;
	}
	if (data->pic.s_texture.path != NULL)
	{
		free (data->pic.s_texture.path);
		data->pic.s_texture.path = NULL;
	}
	if (data->pic.w_texture.path != NULL)
	{
		free (data->pic.w_texture.path);
		data->pic.w_texture.path = NULL;
	}
	if (data->pic.e_texture.path != NULL)
	{
		free (data->pic.e_texture.path);
		data->pic.e_texture.path = NULL;
	}
}

void	free_map2(t_game *data, int i)
{
	if (data->map.grid)
	{
		while (i > 0)
		{
			i--;
			free (data->map.grid[i]);
		}
		free (data->map.grid);
	}
}

void	player_position(t_map *map, int x, int j)
{
	map->player_x = x + 0.5;
	map->player_y = j + 0.5;
}

void	player_orientation(char player, t_map *map, int x, int j)
{
	player_position(map, x, j);
	if (player == 'N')
	{
		map->angle = 270;
		map->player_orientx = 0;
		map->player_orienty = -1;
	}
	else if (player == 'S')
	{
		map->angle = 90;
		map->player_orientx = 0;
		map->player_orienty = 1;
	}
	else if (player == 'W')
	{
		map->angle = 180;
		map->player_orientx = -1;
		map->player_orienty = 0;
	}
	else if (player == 'E')
	{
		map->angle = 0;
		map->player_orientx = 1;
		map->player_orienty = 0;
	}
}
