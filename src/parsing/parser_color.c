/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:58:03 by merdal            #+#    #+#             */
/*   Updated: 2025/01/04 08:27:59 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	validate_color(int *color_values)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color_values[i] < 0 || color_values[i] > 255)
			return (-1);
		i++;
	}
	return (0);
}

int	extract_component(char *str, int *i, int *idx, int *vals)
{
	int		j;
	char	*temp;

	j = *i;
	while (ft_isdigit(str[j]))
		j++;
	temp = ft_substr(str, *i, j - *i);
	if (!temp)
		return (-1);
	if (*idx < 3)
		vals[*idx] = ft_atoi(temp);
	else
	{
		free(temp);
		return (-1);
	}
	free(temp);
	*idx = *idx + 1;
	*i = j;
	return (0);
}

int	parse_color(char *str, t_color *color)
{
	int	i;
	int	idx;
	int	vals[3];

	i = 0;
	idx = 0;
	while (str[i] && idx < 4)
	{
		if (ft_isdigit(str[i]))
		{
			if (extract_component(str, &i, &idx, vals) == -1)
				return (-1);
		}
		else if (str[i] != ',' && str[i] != ' ')
			return (-1);
		else
			i++;
	}
	if (idx != 3 || validate_color(vals) == -1)
		return (-1);
	color->red = (u_int16_t)vals[0];
	color->green = (u_int16_t)vals[1];
	color->blue = (u_int16_t)vals[2];
	color->a = 255;
	return (0);
}

void	get_color(t_game *game, char *file_str, char **file)
{
	char	*color_str;

	color_str = get_path(file_str);
	if (!color_str)
		error_exit_free("Error\nfail to allocate memory", 1, file, game);
	if (ft_strncmp(file_str, "F", 1) == 0)
	{
		if (parse_color(color_str, &game->pic.floor_color) == -1)
		{
			free(color_str);
			error_exit_free("Error\nfailed to parse floor color",
				1, file, game);
		}
	}
	else if (ft_strncmp(file_str, "C", 1) == 0)
	{
		if (parse_color(color_str, &game->pic.celing_color) == -1)
		{
			free(color_str);
			error_exit_free("Error\nfailed to parse celling color",
				1, file, game);
		}
	}
	free(color_str);
}
