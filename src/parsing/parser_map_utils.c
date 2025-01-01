/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:14:45 by merdal            #+#    #+#             */
/*   Updated: 2025/01/01 15:06:47 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_map(char *file_str)
{
	int	i;

	i = 0;
	while (file_str[i])
	{
		if (file_str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_inside(t_map *map, int x, int y, int map_len)
{
	y = 1;
	while (y < map_len - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->grid[y][x] == '0')
			{
				if (map->grid[y - 1][x] == '2' || map->grid[y + 1][x] == '2' ||
					map->grid[y][x - 1] == '2' || map->grid[y][x + 1] == '2')
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_left_right(t_map *map, int y, int map_len)
{
	while (y < map_len)
	{
		if (map->grid[y][0] != '1' && map->grid[y][0] != '2')
			return (-1);
		if (map->grid[y][map->width - 1] != '1'
			&& map->grid[y][map->width - 1] != '2')
			return (-1);
		y++;
	}
	return (0);
}

int	check_top_bottom(t_map *map, int x, int map_len)
{
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' && map->grid[0][x] != '2')
			return (-1);
		if (map->grid[map_len - 1][x] != '1'
			&& map->grid[map_len - 1][x] != '2')
			return (-1);
		x++;
	}
	return (0);
}

int	check_map_wall(t_map *map , int map_len)
{
	int	x;
	int	y;

	x = 0;
	if (check_top_bottom(map, x, map_len) == -1)
		return (-1);
	y = 0;
	if (check_left_right(map, y, map_len) == -1)
		return (-1);
	if (check_inside(map, x, y, map_len) == -1)
		return (-1);
	return (0);
}
