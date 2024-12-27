/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:59:52 by merdal            #+#    #+#             */
/*   Updated: 2024/12/25 16:09:08 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	error_exit(char *str, int exit_num)
{
	printf("%s\n", str);
	exit(exit_num);
}
