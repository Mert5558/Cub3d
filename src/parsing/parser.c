/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:57:31 by merdal            #+#    #+#             */
/*   Updated: 2025/01/02 02:32:40 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_lines(char *input_file)
{
	int		fd;
	int		count;
	char	*file_line;

	count = 0;
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	file_line = get_next_line(fd);
	while (file_line != NULL)
	{
		count++;
		free(file_line);
		file_line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_file_line(char **file, int lines, int fd)
{
	int		i;
	char	*newline_pos;

	i = 0;
	while (i < lines)
	{
		file[i] = get_next_line(fd);
		if (file[i] == NULL)
		{
			while (i > 0)
				free(file[--i]);
			free(file);
			close(fd);
			error_exit("Error GNl!", 1);
		}
		newline_pos = ft_strchr(file[i], '\n');
		if (newline_pos)
			*newline_pos = '\0';
		i++;
	}
	file[i] = NULL;
	close(fd);
	return (file);
}

char	**readfile(char *input_file)
{
	int		lines;
	int		fd;
	char	**file;

	lines = count_lines(input_file);
	if (lines == -1)
		error_exit("Error opening map file!", 1);
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		error_exit("Error opening map file!", 1);
	}
	file = malloc(sizeof(char *) * (lines + 1));
	if (!file)
		error_exit("Error alloc for file!", 1);
	file = read_file_line(file, lines, fd);
	return (file);
}

void	parser(t_game *game, char *input_file)
{
	char	**file;

	file = readfile(input_file);
	file_info(game, file);
	free_char_array(file);
}
