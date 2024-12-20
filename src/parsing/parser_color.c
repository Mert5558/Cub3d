/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:58:03 by merdal            #+#    #+#             */
/*   Updated: 2024/12/19 12:22:08 by merdal           ###   ########.fr       */
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

int	parse_color(char *str, t_rgba *color)
{
	int		i;
	int		j;
	int		color_index;
	char	*temp;
	int		color_values[3];
	
	i = 0;
	color_index = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]))
		{
			j = i;
			while (ft_isdigit(str[j]))
				j++;
			temp = ft_substr(str, i, j - i);
			if (color_index < 3)
				color_values[color_index++] = ft_atoi(temp);
			else
			{
				free(temp);
				return (-1);
			}
			free(temp);
			i = j;
		}
		else if (str[i] != ',' && str[i] != ' ')
			return (-1);
		else
			i++;
	}
	if (color_index != 3 || validate_color(color_values) == -1)
		return (-1);
	color->r = (u_int16_t)color_values[0];
	color->g = (u_int16_t)color_values[1];
	color->b = (u_int16_t)color_values[2];
	color->a = 255;
	return (0);
}

void	get_color(t_game *game, char *file_str)
{
	char	*color_str;

	color_str = get_path(file_str);
	if (ft_strncmp(file_str, "F", 1) == 0)
	{
		if (parse_color(color_str, &game->floor_color) == -1)
		{
			printf("Error: failed to parse floor color\n");
			free(color_str);
			return;
		}
	}
	else if (ft_strncmp(file_str, "C", 1) == 0)
	{
		if (parse_color(color_str, &game->ceil_color) == -1)
		{
			printf("Error: failed to parse ceiling color\n");
			free(color_str);
			return;
		}
	}
}
