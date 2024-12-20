/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:57:31 by merdal            #+#    #+#             */
/*   Updated: 2024/12/20 11:57:24 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int count_lines(char *input_file)
{
	int fd;
	int count;
	char *file_line;

	count = 0;
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening map file\n");
		return (-1);
	}
	while ((file_line = get_next_line(fd)) != NULL)
	{
		count++;
		free(file_line);
	}
	close(fd);
	return (count);
}

char **readfile(char *input_file)
{
	int lines;
	int fd;
	int i;
	char *newline_pos;
	char **file = NULL;

	lines = count_lines(input_file);
	printf("%d\n", lines);
	if (lines == -1)
		return (NULL);
	fd = open(input_file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening map file");
		return (NULL);
	}
	file = malloc(sizeof(char *) * (lines + 1));
	if (!file)
	{
		close(fd);
		return (NULL);
	}
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
			return NULL;
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

void print_char_array(char **array)
{
    int i = 0;

    while (array[i] != NULL)
    {
        printf("%s\n", array[i]);
        i++;
    }
}



void parser(t_game *game, char *input_file)
{
	char **file;

	file = readfile(input_file);
	print_char_array(file);
	file_info(game, file);
}
