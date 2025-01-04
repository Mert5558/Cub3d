/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:59:52 by merdal            #+#    #+#             */
/*   Updated: 2025/01/04 12:23:13 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_space(t_map *map, char **file, int i)
{
	while (file[i])
	{
		if (file[i][0] == '\0')
		{
			if (i < map->height)
				return (-1);
			while (file[i])
			{
				if (file[i][0] != '\0' && file[i][0]
						!= '\t' && file[i][0] != ' ')
					return (-1);
				i++;
			}
			return (0);
		}
		i++;
	}
	return (0);
}

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
	return (tex_path);
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		error_exit("ERROR\nfailed to free!", 1);
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	error_exit(char *str, int exit_num)
{
	printf("%s\n", str);
	exit(exit_num);
}

void	error_exit_free(char *str, int exit_num, char **array, t_game *game)
{
	printf("%s\n", str);
	free_textures(game);
	if (game->map.grid)
		free_char_array(game->map.grid);
	if (array)
		free_char_array(array);
	exit(exit_num);
}
