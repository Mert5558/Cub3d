/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:49:47 by merdal            #+#    #+#             */
/*   Updated: 2025/01/02 12:25:09 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isspace(int c)
{
	int	is_space;

	is_space = (c == ' ' || c == '\t' || c == '\n'
			|| c == '\n' || c == '\f' || c == '\r');
	return (is_space);
}

char	*trim_spaces(char *str)
{
	while (ft_isspace((unsigned char)*str))
		str++;
	return (str);
}

void	file_info_3(t_game *game, char **file, t_parse *p)
{
	char	*trimmed;

	trimmed = trim_spaces(file[p->i]);
	if (ft_strncmp(trimmed, "F", 1) == 0)
	{
		get_color(game, trimmed);
		p->found_2 = 1;
		(p->found)++;
	}
	else if (ft_strncmp(trimmed, "C", 1) == 0)
	{
		get_color(game, trimmed);
		p->found_2 = 1;
		(p->found)++;
	}
}

void	file_info_2(t_game *game, char **file, t_parse *p)
{
	char	*trimmed;

	trimmed = trim_spaces(file[p->i]);
	if (ft_strncmp(trimmed, "NO", 2) == 0)
	{
		(p->found) += process_n_texture(trimmed, game);
		p->found_2 = 1;
	}
	else if (ft_strncmp(trimmed, "SO", 2) == 0)
	{
		(p->found) += process_s_texture(trimmed, game);
		p->found_2 = 1;
	}
	else if (ft_strncmp(trimmed, "WE", 2) == 0)
	{
		(p->found) += process_w_texture(trimmed, game);
		p->found_2 = 1;
	}
	else if (ft_strncmp(trimmed, "EA", 2) == 0)
	{
		(p->found) += process_e_texture(trimmed, game);
		p->found_2 = 1;
	}
}

void	file_info(t_game *game, char **file)
{
	t_parse	p;

	p.i = 0;
	p.found = 0;
	while (file[p.i])
	{
		p.found_2 = 0;
		file_info_2(game, file, &p);
		file_info_3(game, file, &p);
		if (p.found_2 == 0 && check_map(file[p.i]))
		{
			game->map = get_map(file, p.i);
			p.found++;
			break ;
		}
		else if (p.found_2 == 0 && file[p.i][0] != '\0'
			&& file[p.i][0] != '\t' && file[p.i][0] != ' ')
			error_exit("Error: Unknown identifier!", 1);
		p.i++;
	}
	if (p.found != 7)
		error_exit("Error: not all identifiers", 1);
}
