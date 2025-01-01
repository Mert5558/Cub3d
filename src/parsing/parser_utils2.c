/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:26:37 by merdal            #+#    #+#             */
/*   Updated: 2025/01/01 14:48:16 by merdal           ###   ########.fr       */
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

int	map_leeeeeen(char **file, int i)
{
	int	len;
	int	found_map;

	len = 0;
	found_map = 0;

	while (file[i])
	{
		if (file[i][0] != '\0') // Non-empty line
		{
			found_map = 1;
			len++;
		}
		else if (found_map) // Empty line after map starts
		{
			break;
		}
		i++;
	}
	return (len);
}
