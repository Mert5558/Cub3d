/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:46:24 by merdal            #+#    #+#             */
/*   Updated: 2025/01/01 15:09:17 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	display_texture(t_game *game, int texture_index)
// {
//     mlx_t	*mlx;
//     mlx_image_t *img;
//     int		width;
//     int		height;
//     int		i, j;
//     t_texture texture;

//     width = game->textures[texture_index].width;
//     height = game->textures[texture_index].height;

//     mlx = mlx_init(width, height, "Texture Display", false);
//     if (!mlx)
//     {
//         printf("Error initializing MLX\n");
//         return;
//     }

//     img = mlx_new_image(mlx, width, height);
//     if (!img)
//     {
//         printf("Error creating image\n");
//         mlx_terminate(mlx);
//         return;
//     }

//     texture = game->textures[texture_index];
//     for (i = 0; i < height; i++)
//     {
//         for (j = 0; j < width; j++)
//         {
//             int color = (texture.grid[i][j].r << 24)
// 				| (texture.grid[i][j].g << 16) | (texture.grid[i][j].b << 8)
// 				| texture.grid[i][j].a;
//             mlx_put_pixel(img, j, i, color);
//         }
//     }

//     mlx_image_to_window(mlx, img, 0, 0);
//     mlx_loop(mlx);
//     mlx_delete_image(mlx, img);
//     mlx_terminate(mlx);
// }

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

	len = i;
	while (file[len])
		len++;
	len = len - i;
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
	int		map_len;

	map.player_num = 0;
	map.width = map_max_width(file, i);
	map.height = map_max_height(file, i);
	map_len = map_leeeeeen(file, i);
	printf("map_height: %d\n", map.height);
	printf("map_len: %d\n", map_len);
	map.grid = ft_calloc(map.height + 1, sizeof(char *));
	if (!map.grid)
		error_exit_free("Error: failed allocation!", 1, map.grid);
	if (map_space(file, i, map_len))
		error_exit_free("Error: empty line in map!", 1, map.grid);
	if (assign_map(&map, file, i) == -1)
		error_exit_free("Error: failed to extract map!", 1, map.grid);
	if (map.player_num > 1)
		error_exit_free("Error: map has more than one player", 1, map.grid);
	if (map.player_num < 1)
		error_exit_free("Error: map has no player", 1, map.grid);
	if (check_map_wall(&map, map_len) == -1)
		error_exit_free("Error: map is not closed by walls", 1, map.grid);
	return (map);
}
