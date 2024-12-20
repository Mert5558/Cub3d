/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:46:24 by merdal            #+#    #+#             */
/*   Updated: 2024/12/20 14:33:34 by merdal           ###   ########.fr       */
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
//             int color = (texture.grid[i][j].r << 24) | (texture.grid[i][j].g << 16) | (texture.grid[i][j].b << 8) | texture.grid[i][j].a;
//             mlx_put_pixel(img, j, i, color);
//         }
//     }

//     mlx_image_to_window(mlx, img, 0, 0);
//     mlx_loop(mlx);
//     mlx_delete_image(mlx, img);
//     mlx_terminate(mlx);
// }


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

int	assign_map(t_map *map, char **file, int i)
{
	int	j;
	int	x;

	j = 0;
	while (file[i] && file[i][0] != '\0')
	{
		map->grid[j] = ft_calloc(map->width + 1, sizeof(char));
		if (!map->grid[j])
			printf("Error: failed allocation!");
		x = 0;
		while (x < map->width)
		{
			if (x < (int)ft_strlen(file[i]))
			{
				if (file[i][x] == ' ')
					map->grid[j][x] = '2';
				else if (file[i][x] == 'N' || file[i][x] == 'S' || file[i][x] == 'W' || file[i][x] == 'E')
				{
					map->player_num++;
					map->grid[j][x] = file[i][x];
				}
				else
					map->grid[j][x] = file[i][x];
			}
			else
				map->grid[j][x] = '2';
			x++;
		}
		j++;
		i++;
	}
	return (0);
}

// int	check_map_wall(t_map *map)
// {
	
// }



t_map	get_map(char **file, int i)
{
	t_map	map;

	map.player_num = 0;
	map.width = map_max_width(file, i);
	map.height = map_max_height(file, i);
	map.grid = ft_calloc(map.height + 1, sizeof(char *));
	if (!map.grid)
		printf("Error: failed allocation!");
	assign_map(&map, file, i);
	if (map.player_num > 1)
		printf("Error: map has more than one player\n");
	if (map.player_num < 1)
		printf("Error: map has no player\n");
	// if (check_map_wall(&map) == 1)
	// 	printf("Error: map is not closed by walls\n");
	return (map);
}
