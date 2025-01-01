/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:46:26 by amecani           #+#    #+#             */
/*   Updated: 2025/01/01 16:32:28 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	leaks(void)
// {
// 	return (system("leaks cub3D"));
// }
// 	atexit((void *)leaks);


int main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		printf("Wrong number of arguments!\nUsage: ./cub3d + map.cub");
		exit(1);
	}
	parser(&game, argv[1]);

	free_game(&game);
	return (0);
}