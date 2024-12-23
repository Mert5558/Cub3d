/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:14:45 by merdal            #+#    #+#             */
/*   Updated: 2024/12/23 14:39:41 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_map_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' && map->grid[0][x] != '2')
			return (1);
		if (map->grid[map->height - 1][x] != '1' && map->grid[map->height - 1][x] != '2')
			return (1);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' && map->grid[y][0] != '2')
			return (1);
		if (map->grid[y][map->width - 1] != '1' &&  map->grid[y][map->width - 1] != '2')
			return (1);
		y++;
	}
	y = 1;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->grid[y][x] == '0')
			{
				if (map->grid[y - 1][x] == '2' || map->grid[y + 1][x] == '2' ||
					map->grid[y][x - 1] == '2' || map->grid[y][x + 1] == '2')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
