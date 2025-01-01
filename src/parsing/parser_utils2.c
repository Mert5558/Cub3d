/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:26:37 by merdal            #+#    #+#             */
/*   Updated: 2025/01/01 15:23:48 by merdal           ###   ########.fr       */
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

void	free_texture(t_texture *texture)
{
	int	i;

	if (texture->grid)
	{
		i = 0;
		while (i < texture->height)
		{
			free(texture->grid[i]);
			i++;
		}
		free(texture->grid);
	}
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free_texture(&game->textures[i]);
		i++;
	}
	free_map(&game->map);
}
