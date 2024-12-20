/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:46:26 by amecani           #+#    #+#             */
/*   Updated: 2024/12/20 16:04:57 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"



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
	int		half_heigh = HEIGHT / 2;

	img = mlx_new_image(window, WIDTH, HEIGHT);
	y = 0;
	while ((int)y < half_heigh)
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
	int i = 0;
	if (			(exec_data->wall[0] = mlx_load_png("texutres/pentagon_wall.png")))
		i++;
	if (i == 1	&&	(exec_data->wall[1] = mlx_load_png("texutres/pentagon_wall.png")))
		i++;
	if (i == 2	&&	(exec_data->wall[2] = mlx_load_png("texutres/pentagon_wall.png")))
		i++;
	if (i == 3	&&	(exec_data->wall[3] = mlx_load_png("texutres/pentagon_wall.png")))
		i++;

	if (i++ != 4)
	{
		if (i == 1)
			return;
		while (--i != -1)
			mlx_delete_texture(exec_data->wall[i]);
	}
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

	// //Execution 
	// excecution();
	(void)argc;
	(void)argv;
	// Execution 

	return (0);
}