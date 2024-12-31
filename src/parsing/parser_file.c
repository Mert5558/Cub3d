/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:49:47 by merdal            #+#    #+#             */
/*   Updated: 2024/12/27 13:50:46 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_grid_color(t_rgba **grid, int i, int width, mlx_texture_t *png)
{
	int	j;
	int	pixel_index;

	grid[i] = malloc(sizeof(t_rgba) * width);
	if (!grid[i])
	{
		printf("Error: allocation failed!");
		mlx_delete_texture(png);
		return (-1);
	}
	j = 0;
	while (j < width)
	{
		pixel_index = (i * width + j) * 4;
		grid[i][j].r = png->pixels[pixel_index];
		grid[i][j].g = png->pixels[pixel_index + 1];
		grid[i][j].b = png->pixels[pixel_index + 2];
		grid[i][j].a = png->pixels[pixel_index + 3];
		j++;
	}
	return (0);
}

int	alloc_fill_grid(t_texture *texture, mlx_texture_t *png)
{
	int	i;

	texture->grid = malloc(sizeof(t_rgba *) * texture->height);
	if (!texture->grid)
		return (-1);
	i = 0;
	while (i < texture->height)
	{
		if (fill_grid_color(texture->grid, i, png->width, png) == -1)
		{
			while (i > 0)
			{
				i--;
				free(texture->grid[i]);
			}
			free(texture->grid);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	fill_grid(t_texture *texture, char *tex_path)
{
	mlx_texture_t	*png;

	png = mlx_load_png(tex_path);
	if (!png)
	{
		printf("Error: texture invalid!");
		return (-1);
	}
	texture->height = png->height;
	texture->width = png->width;
	if (alloc_fill_grid(texture, png) == -1)
	{
		printf("Error: allocation failed!\n");
		return (-1);
	}
	mlx_delete_texture(png);
	return (0);
}

t_texture	load_texture(t_texture texture, char *file_str)
{
	char			*tex_path;

	tex_path = get_path(file_str);
	if (fill_grid(&texture, tex_path) == -1)
	{
		error_exit("Error loading texture!", 1);
		free(tex_path);
	}
	free(tex_path);
	return (texture);
}

void	file_info(t_game *game, char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_strncmp(file[i], "NO", 2) == 0)
			game->textures[NO] = load_texture(game->textures[NO], file[i]);
		else if (ft_strncmp(file[i], "SO", 2) == 0)
			game->textures[SO] = load_texture(game->textures[SO], file[i]);
		else if (ft_strncmp(file[i], "WE", 2) == 0)
			game->textures[WE] = load_texture(game->textures[WE], file[i]);
		else if (ft_strncmp(file[i], "EA", 2) == 0)
			game->textures[EA] = load_texture(game->textures[EA], file[i]);
		else if (ft_strncmp(file[i], "F", 1) == 0
			|| ft_strncmp(file[i], "C", 1) == 0)
			get_color(game, file[i]);
		else if (check_map(file[i]))
		{
			game->map = get_map(file, i);
			break ;
		}
		i++;
	}
}
