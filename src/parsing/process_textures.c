/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:44:57 by disilva           #+#    #+#             */
/*   Updated: 2025/01/01 23:45:33 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// int	skip_empty_spaces(int *i, char *line)
// {
// 	while (line[(*i)] == ' ' || line[(*i)] == '	')
// 		(*i)++;
// 	return (*i);
// }

// int	str_end_pos(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// int	check_png_ending(char *path, int i)
// {
// 	int	fd;

// 	if (path[i - 1] != 'g' && path[i - 2] != 'n'
// 		&& path[i - 3] != 'p' && path[i - 4] != '.')
// 	{
// 		printf("ERROR\nthe texture file name doesn't end with .png\n");
// 		return (10);
// 	}
// 	fd = open(path, O_DIRECTORY);
// 	if (fd >= 0)
// 	{
// 		perror("ERROR\nfile is a directory\n");
// 		close(fd);
// 		return (10);
// 	}
// 	fd = open(path, O_RDONLY);
// 	printf ("%s\n", path);
// 	close (fd);
// 	if (fd == -1)
// 	{
// 		perror("ERROR\nerror opening texture file\n");
// 		return (10);
// 	}
// 	return (1);
// }

int	process_n_texture2(char *line, t_game *data, int *i)
{
	int			first_char;
	static int	repetition = 0;

	repetition++;
	if (repetition > 1)
	{
		printf("ERROR\nmultiple north textures\n");
		return (10);
	}
	first_char = skip_empty_spaces(i, line);
	(*i) = first_char;
	while (line[*i] != '\n' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	while (line[*i]
		== ' ' || line[*i] == '	')
		(*i)--;
	line[*i + 1] = '\0';
	data->pic.n_texture.path = ft_strdup(&(line[first_char]));
	(*i) = str_end_pos(data->pic.n_texture.path);
	return (check_png_ending(data->pic.n_texture.path, *i));
}

int	process_n_texture(char *line, t_game *data)
{
	int	i;

	i = 0;
	i = skip_empty_spaces(&i, line);
	if (line[i] == 'N' && line[++i] == 'O' && line[++i] == ' ')
		return (process_n_texture2(line, data, &i));
	return (1);
}

int	process_s_texture2(char *line, t_game *data, int *i)
{
	int			first_char;
	static int	repetition = 0;

	repetition++;
	if (repetition > 1)
	{
		printf("ERROR\nmultiple south textures\n");
		return (10);
	}
	first_char = skip_empty_spaces(i, line);
	(*i) = first_char;
	while (line[*i] != '\n' && line[*i] != '\0')
		(*i)++;
	(*i)--;
	while (line[*i]
		== ' ' || line[*i] == '	')
		(*i)--;
	line[*i + 1] = '\0';
	data->pic.s_texture.path = ft_strdup(&(line[first_char]));
	(*i) = str_end_pos(data->pic.s_texture.path);
	return (check_png_ending(data->pic.s_texture.path, *i));
}

int	process_s_texture(char *line, t_game *data)
{
	int	i;

	i = 0;
	i = skip_empty_spaces(&i, line);
	if (line[i] == 'S' && line[++i] == 'O' && line[++i] == ' ')
		return (process_s_texture2(line, data, &i));
	return (1);
}

// int	process_w_texture2(char *line, t_game *data, int *i)
// {
// 	int			first_char;
// 	static int	repetition = 0;

// 	repetition++;
// 	if (repetition > 1)
// 	{
// 		printf("ERROR\nmultiple south textures\n");
// 		return (10);
// 	}
// 	first_char = skip_empty_spaces(i, line);
// 	(*i) = first_char;
// 	while (line[*i] != '\n' && line[*i] != '\0')
// 		(*i)++;
// 	(*i)--;
// 	while (line[*i]
// 		== ' ' || line[*i] == '	')
// 		(*i)--;
// 	line[*i + 1] = '\0';
// 	data->pic.w_texture.path = ft_strdup(&(line[first_char]));
// 	(*i) = str_end_pos(data->pic.w_texture.path);
// 	return (check_png_ending(data->pic.w_texture.path, *i));
// }

// int	process_w_texture(char *line, t_game *data)
// {
// 	int	i;

// 	i = 0;
// 	i = skip_empty_spaces(&i, line);
// 	if (line[i] == 'W' && line[++i] == 'E' && line[++i] == ' ')
// 		return (process_w_texture2(line, data, &i));
// 	return (1);
// }

// int	process_e_texture2(char *line, t_game *data, int *i)
// {
// 	int			first_char;
// 	static int	repetition = 0;

// 	repetition++;
// 	if (repetition > 1)
// 	{
// 		printf("ERROR\nmultiple south textures\n");
// 		return (10);
// 	}
// 	first_char = skip_empty_spaces(i, line);
// 	(*i) = first_char;
// 	while (line[*i] != '\n' && line[*i] != '\0')
// 		(*i)++;
// 	(*i)--;
// 	while (line[*i]
// 		== ' ' || line[*i] == '	')
// 		(*i)--;
// 	line[*i + 1] = '\0';
// 	data->pic.e_texture.path = ft_strdup(&(line[first_char]));
// 	(*i) = str_end_pos(data->pic.e_texture.path);
// 	return (check_png_ending(data->pic.e_texture.path, *i));
// }

// int	process_e_texture(char *line, t_game *data)
// {
// 	int	i;

// 	i = 0;
// 	i = skip_empty_spaces(&i, line);
// 	if (line[i] == 'E' && line[++i] == 'A' && line[++i] == ' ')
// 		return (process_e_texture2(line, data, &i));
// 	return (1);
// }

// bool	process_each_color(int *i, char *line, int *color)
// {
// 	if (line[*i] >= '0' && line[*i] <= '9')
// 		*color = 0;
// 	else
// 	{
// 		printf("ERROR\ncolor outside of range\n");
// 		return (1);
// 	}
// 	while (line[*i] >= '0' && line[*i] <= '9')
// 	{
// 		*color = *color * 10 + line[*i] - '0';
// 		(*i)++;
// 	}
// 	if ((*color != -1 && line[*i] == ',' && *color <= 255)
// 		|| (*color != -2 && (line[*i] == '\n' || line[*i] == ' '
// 				|| line[*i] == '\0')
// 			&& *color <= 255))
// 		return (0);
// 	printf("ERROR\ncolor outside of range\n");
// 	return (1);
// }

// int	process_floor_color(char *line, t_game *data)
// {
// 	int			i;
// 	static int	repetition = 0;

// 	i = 0;
// 	i = skip_empty_spaces(&i, line);
// 	if (line[i] == 'F' && line[++i] == ' ')
// 	{
// 		repetition++;
// 		if (repetition > 1)
// 			return (printf("ERROR\nmultiple floor colors\n"), 10);
// 		while (line[i] == ' ' || line[i] == '	')
// 			i++;
// 		if (process_each_color(&i, line, &data->pic.floor_color.red) == 1)
// 			return (10);
// 		i++;
// 		if (process_each_color(&i, line, &data->pic.floor_color.green) == 1)
// 			return (10);
// 		i++;
// 		if (process_each_color(&i, line, &data->pic.floor_color.blue) == 1)
// 			return (10);
// 		return (1);
// 	}
// 	return (20);
// }

// int	process_celing_color(char *line, t_game *data)
// {
// 	int			i;
// 	static int	repetition = 0;

// 	i = 0;
// 	i = skip_empty_spaces(&i, line);
// 	if (line[i] == 'C' && line[++i] == ' ')
// 	{
// 		repetition++;
// 		if (repetition > 1)
// 			return (printf("ERROR\nmultiple celling colors\n"), 10);
// 		while (line[i] == ' ' || line[i] == '	')
// 			i++;
// 		if (process_each_color(&i, line, &data->pic.celing_color.red) == 1)
// 			return (10);
// 		i++;
// 		if (process_each_color(&i, line,
// 				&data->pic.celing_color.green) == 1)
// 			return (10);
// 		i++;
// 		if (process_each_color(&i, line, &data->pic.celing_color.blue) == 1)
// 			return (10);
// 		return (1);
// 	}
// 	return (20);
// }
