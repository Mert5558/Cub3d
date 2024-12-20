/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:49:47 by merdal            #+#    #+#             */
/*   Updated: 2024/12/20 11:27:36 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_path(char *str)
{
	char	*tex_path;
	char	*space_pos;

	space_pos = ft_strchr(str, ' ');
	if (*(space_pos + 1) == '\0')
	{
		printf("Error: No path found!\n");
		return (NULL);
	}
	tex_path = ft_strdup(space_pos + 1);
	if (!tex_path)
	{
		printf("Error: failed memory allocantion\n");
		return (NULL);
	}
	printf("%s\n", tex_path);
	return (tex_path);
}

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

int	fill_grid(t_texture *texture, char *tex_path)
{
	mlx_texture_t	*png;
	int				i;

	png = mlx_load_png(tex_path);
	if (!png)
	{
		printf("Error: texture invalid!");
		return (-1);
	}
	texture->height = png->height;
	texture->width = png->width;
	texture->grid = malloc(sizeof(t_rgba *) * texture->height);
	if (!texture->grid)
	{
		printf("Error: allocation failed!");
		mlx_delete_texture(png);
		return (-1);
	}
	i = 0;
	while (i < texture->height)
	{
		if (fill_grid_color(texture->grid, i, png->width, png) == -1)
		{
			free(texture->grid);
			return (-1);
		}
		i++;
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
		printf("Error: failed to load texture!");
		return (texture);
	}
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
