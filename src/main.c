/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:46:26 by amecani           #+#    #+#             */
/*   Updated: 2024/12/20 14:37:24 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

#define WIDTH 800
#define HEIGHT 600

int	get_rgba(int r, int g, int b, int a)
{
	int	rgba;

	r = r << 24;
	g = g << 16;
	b = b << 8;
	rgba = r | g | b | a;
	return (rgba);
}

void	paint_floor_and_celing(mlx_t *window, int f_c, int c_c)
{
	uint32_t x;
	uint32_t y;
	mlx_image_t	*img;

	img = mlx_new_image(window, WIDTH, HEIGHT);
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(img, x++, y, c_c);
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(img, x++, y, f_c);
		y++;
	}
	mlx_image_to_window(window, img, 0, 0);
}
void	putting_wasll_manuanylly(t_exec *exec_data)
{
	exec_data->wall[0] = mlx_load_png("texutres/pentagon_wall.png");
	exec_data->wall[1] = mlx_load_png("texutres/pentagon_wall.png");
	exec_data->wall[2] = mlx_load_png("texutres/pentagon_wall.png");
	exec_data->wall[3] = mlx_load_png("texutres/pentagon_wall.png");
}

void loops_in_here(mlx_t *window)
{
	mlx_loop(window);
}

int main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		printf("Wrong number of arguments!\nUsage: ./cub3d + map.cub");
		exit(1);
	}
	parser(&game, argv[1]);
	print_map_grid(&game.map);

	// Execution 
	// excecution();
	(void)argc;
	(void)argv;
	// Execution 

	return (0);
}