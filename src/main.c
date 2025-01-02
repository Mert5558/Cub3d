/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:46:26 by merdal            #+#    #+#             */
/*   Updated: 2025/01/02 16:26:42 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	leaks(void)
{
	return (system("leaks cub3D"));
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit((void *)leaks);
	if (check_param(argc, argv))
		return (1);
	parser(&game, argv[1]);
	run_game(&game);
	return (0);
}
