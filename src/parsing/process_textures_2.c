/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_textures_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:44:35 by disilva           #+#    #+#             */
/*   Updated: 2025/01/04 01:53:53 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	process_w_texture2(char *line, t_game *data, int *i)
{
	int			first_char;
	static int	repetition = 0;

	repetition++;
	if (repetition > 1)
	{
		printf("ERROR\nmultiple west textures\n");
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
	data->pic.w_texture.path = ft_strdup(&(line[first_char]));
	if (data->pic.w_texture.path == NULL)
		printf("ERROR\nfailed to copy line");
	if (data->pic.w_texture.path == NULL)
		return (20);
	(*i) = str_end_pos(data->pic.w_texture.path);
	return (check_png_ending(data->pic.w_texture.path, *i));
}

int	process_w_texture(char *line, t_game *data)
{
	int	i;

	i = 0;
	i = skip_empty_spaces(&i, line);
	if (line[i] == 'W' && line[++i] == 'E' && line[++i] == ' ')
		return (process_w_texture2(line, data, &i));
	return (1);
}

int	process_e_texture2(char *line, t_game *data, int *i)
{
	int			first_char;
	static int	repetition = 0;

	repetition++;
	if (repetition > 1)
	{
		printf("ERROR\nmultiple east textures\n");
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
	data->pic.e_texture.path = ft_strdup(&(line[first_char]));
	if (data->pic.e_texture.path == NULL)
		printf("ERROR\nfailed to copy line");
	if (data->pic.e_texture.path == NULL)
		return (20);
	(*i) = str_end_pos(data->pic.e_texture.path);
	return (check_png_ending(data->pic.e_texture.path, *i));
}

int	process_e_texture(char *line, t_game *data)
{
	int	i;

	i = 0;
	i = skip_empty_spaces(&i, line);
	if (line[i] == 'E' && line[++i] == 'A' && line[++i] == ' ')
		return (process_e_texture2(line, data, &i));
	return (1);
}
