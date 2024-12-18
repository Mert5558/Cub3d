/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:46:26 by amecani           #+#    #+#             */
/*   Updated: 2024/12/18 15:11:09 by merdal           ###   ########.fr       */
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

void	display_texture(t_game *game, int texture_index)
{
    mlx_t	*mlx;
    mlx_image_t *img;
    int		width;
    int		height;
    int		i, j;
    t_texture texture;

    width = game->textures[texture_index].width;
    height = game->textures[texture_index].height;

    mlx = mlx_init(width, height, "Texture Display", false);
    if (!mlx)
    {
        printf("Error initializing MLX\n");
        return;
    }

    img = mlx_new_image(mlx, width, height);
    if (!img)
    {
        printf("Error creating image\n");
        mlx_terminate(mlx);
        return;
    }

    texture = game->textures[texture_index];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int color = (texture.grid[i][j].r << 24) | (texture.grid[i][j].g << 16) | (texture.grid[i][j].b << 8) | texture.grid[i][j].a;
            mlx_put_pixel(img, j, i, color);
        }
    }

    mlx_image_to_window(mlx, img, 0, 0);
    mlx_loop(mlx);
    mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
}

void show_colors(t_game *game)
{
    printf("Floor Color: R=%d, G=%d, B=%d, A=%d\n",
           game->floor_color.r, game->floor_color.g, game->floor_color.b, game->floor_color.a);
    printf("Ceiling Color: R=%d, G=%d, B=%d, A=%d\n",
           game->ceil_color.r, game->ceil_color.g, game->ceil_color.b, game->ceil_color.a);
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
	//display_texture(&game, NO);
	//show_colors(&game);

	// Execution 
	// excecution();
	(void)argc;
	(void)argv;
	// Execution 

	return (0);
}