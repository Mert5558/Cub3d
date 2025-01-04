/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:46:24 by merdal            #+#    #+#             */
/*   Updated: 2025/01/04 14:04:41 by merdal           ###   ########.fr       */
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

void	fill_grid_line(t_map *map, char *row, int j, t_game *game)
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
			{
				printf("----------------%c-----\n", row[x]);
				bad_char(map, j, game);
			}
		}
		else
			map->grid[j][x] = '2';
		x++;
	}
}

int	assign_map(t_map *map, char **file, int i, t_game *game)
{
	int	j;

	j = 0;
	while (file[i] && file[i][0] != '\0')
	{
		map->grid[j] = NULL;
		map->grid[j] = malloc((map->width + 1) * sizeof(char));
		if (!map->grid[j])
			return (-1);
		fill_grid_line(map, file[i], j, game);
		j++;
		i++;
	}
	map->grid[j] = NULL;
	return (0);
}

void	get_map(char **file, int i, t_game *game)
{
	game->map.player_num = 0;
	game->map.width = map_max_width(file, i);
	game->map.height = map_max_height(file, i);
	if (map_space(&game->map, file, i))
		error_exit_free("Error\nempty line in map!", 1, file, game);
	game->map.grid = malloc((game->map.height + 1) * sizeof(char *));
	if (!game->map.grid)
		error_exit_free("Error\nfailed allocation!", 1, file, game);
	if (assign_map(&game->map, file, i, game) == -1)
		error_exit_free("Error\nfailed to extract map!", 1, file, game);
	if (game->map.player_num > 1)
		error_exit_free("Error\nmap has more than one player", 1, file, game);
	if (game->map.player_num < 1)
		error_exit_free("Error\nmap has no player", 1, file, game);
	if (check_map_wall(&game->map) == -1)
		error_exit_free("Error\nmap is not closed by walls", 1, file, game);
}
