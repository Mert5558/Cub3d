/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:44:57 by disilva           #+#    #+#             */
/*   Updated: 2025/01/04 11:11:25 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		== ' ' || line[*i] == '\t')
		(*i)--;
	line[*i + 1] = '\0';
	data->pic.n_texture.path = ft_strdup(&(line[first_char]));
	if (data->pic.n_texture.path == NULL)
		printf("ERROR\nfailed to copy line");
	if (data->pic.n_texture.path == NULL)
		return (20);
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
		== ' ' || line[*i] == '\t')
		(*i)--;
	line[*i + 1] = '\0';
	data->pic.s_texture.path = ft_strdup(&(line[first_char]));
	if (data->pic.s_texture.path == NULL)
		printf("ERROR\nfailed to copy line");
	if (data->pic.s_texture.path == NULL)
		return (20);
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
