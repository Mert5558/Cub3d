/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:46:24 by merdal            #+#    #+#             */
/*   Updated: 2025/01/02 02:33:57 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_max_width(char **file, int i)
{
	size_t	len;

	len = 0;
	while (file[i])
	{
		if (ft_strlen(file[i]) > len)
			len = ft_strlen(file[i]);
		i++;
	}
	return (len);
}

int	map_max_height(char **file, int i)
{
	int	len;
	int	found_map;

	len = 0;
	found_map = 0;
	while (file[i])
	{
		if (file[i][0] != '\0')
		{
			found_map = 1;
			len++;
		}
		else if (found_map)
			break ;
		i++;
	}
	return (len);
}

void	fill_grid_line(t_map *map, char *row, int j)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (x < (int)ft_strlen(row))
		{
			if (row[x] == ' ')
				map->grid[j][x] = '2';
			else if (row[x] == 'N' || row[x] == 'S'
				|| row[x] == 'W' || row[x] == 'E')
			{
				map->player_num++;
				map->grid[j][x] = row[x];
				player_orientation(row[x], map, x, j);
			}
			else if ((row[x] == '0' || row[x] == '1' || row[x] == '2'))
				map->grid[j][x] = row[x];
			else
				error_exit_free("Error: unexpected char in map!", 1, map->grid);
		}
		else
			map->grid[j][x] = '2';
		x++;
	}
}

int	assign_map(t_map *map, char **file, int i)
{
	int	j;

	j = 0;
	while (file[i] && file[i][0] != '\0')
	{
		map->grid[j] = ft_calloc(map->width + 1, sizeof(char));
		if (!map->grid[j])
			return (-1);
		fill_grid_line(map, file[i], j);
		j++;
		i++;
	}
	return (0);
}

t_map	get_map(char **file, int i)
{
	t_map	map;

	map.player_num = 0;
	map.width = map_max_width(file, i);
	map.height = map_max_height(file, i);
	map.grid = ft_calloc(map.height + 1, sizeof(char *));
	if (!map.grid)
		error_exit_free("Error: failed allocation!", 1, map.grid);
	if (map_space(&map, file, i))
		error_exit_free("Error: empty line in map!", 1, map.grid);
	if (assign_map(&map, file, i) == -1)
		error_exit_free("Error: failed to extract map!", 1, map.grid);
	if (map.player_num > 1)
		error_exit_free("Error: map has more than one player", 1, map.grid);
	if (map.player_num < 1)
		error_exit_free("Error: map has no player", 1, map.grid);
	if (check_map_wall(&map) == -1)
		error_exit_free("Error: map is not closed by walls", 1, map.grid);
	return (map);
}
