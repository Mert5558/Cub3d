/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:42:58 by disilva           #+#    #+#             */
/*   Updated: 2025/01/02 02:34:20 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	skip_empty_spaces(int *i, char *line)
{
	while (line[(*i)] == ' ' || line[(*i)] == '	')
		(*i)++;
	return (*i);
}

int	str_end_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_png_ending(char *path, int i)
{
	int	fd;

	if (path[i - 1] != 'g' && path[i - 2] != 'n'
		&& path[i - 3] != 'p' && path[i - 4] != '.')
	{
		printf("ERROR\nthe texture file name doesn't end with .png\n");
		return (10);
	}
	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		perror("ERROR\nfile is a directory\n");
		close(fd);
		return (10);
	}
	fd = open(path, O_RDONLY);
	close (fd);
	if (fd == -1)
	{
		perror("ERROR\nerror opening texture file\n");
		return (10);
	}
	return (1);
}
