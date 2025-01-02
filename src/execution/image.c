/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:44:56 by diogofms          #+#    #+#             */
/*   Updated: 2025/01/02 00:23:46 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_color2(t_game *data)
{
	data->image_info.celing_color = (int)((data->pic.celing_color.red << 24)
			| (data->pic.celing_color.green << 16)
			| (data->pic.celing_color.blue << 8)
			| 0xFF);
	data->image_info.floor_color = (int)((data->pic.floor_color.red << 24)
			| (data->pic.floor_color.green << 16)
			| (data->pic.floor_color.blue << 8)
			| 0xFF);
}

void	convert_textures(t_game *data)
{
	data->pic.n_texture.texture = mlx_load_png(data->pic.n_texture.path);
	data->pic.s_texture.texture = mlx_load_png(data->pic.s_texture.path);
	data->pic.e_texture.texture = mlx_load_png(data->pic.e_texture.path);
	data->pic.w_texture.texture = mlx_load_png(data->pic.w_texture.path);
	if (!data->pic.n_texture.texture || !data->pic.s_texture.texture
		|| !data->pic.e_texture.texture || !data->pic.w_texture.texture)
	{
		perror ("ERROR\nfailure to load textures\n");
		free_textures(data);
		free_map2(data, data->map.height);
		mlx_delete_image(data->mlx, data->img);
		mlx_close_window(data->mlx);
		exit (0);
	}
}

void	set_background(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_LENGTH / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_put_pixel(data->img, x, y, data->image_info.celing_color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_LENGTH)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_put_pixel(data->img, x, y, data->image_info.floor_color);
			x++;
		}
		y++;
	}
}

void	draw_horizontal(t_game *data, t_draw_column	*d)
{
	if (data->ray_info.step_y_direct == 1)
	{
		d->wall_x_cord = data->map.player_x + data->image_info.x_distance
			* data->ray_info.step_x_direct;
		d->wall_x_cord = (1 - fmod(d->wall_x_cord, 1.0))
			* data->pic.s_texture.texture->width;
		d->pixel_step_y = data->pic.s_texture.texture->height
			/ (double)d->wall_heigth;
		d->texture = data->pic.s_texture.texture;
	}
	else
	{
		d->wall_x_cord = data->map.player_x + data->image_info.x_distance
			* data->ray_info.step_x_direct;
		d->wall_x_cord = (fmod(d->wall_x_cord, 1.0))
			* data->pic.n_texture.texture->width;
		d->pixel_step_y = data->pic.n_texture.texture->height
			/ (double)d->wall_heigth;
		d->texture = data->pic.n_texture.texture;
	}
}

void	draw_vertical(t_game *data, t_draw_column *d)
{
	if (data->ray_info.step_x_direct == 1)
	{
		d->wall_x_cord = data->map.player_y + data->image_info.y_distance
			* data->ray_info.step_y_direct;
		d->wall_x_cord = (fmod(d->wall_x_cord, 1.0))
			* data->pic.e_texture.texture->width;
		d->pixel_step_y = data->pic.e_texture.texture->height
			/ (double)d->wall_heigth;
		d->texture = data->pic.e_texture.texture;
	}
	else
	{
		d->wall_x_cord = data->map.player_y + data->image_info.y_distance
			* data->ray_info.step_y_direct;
		d->wall_x_cord = (1 - fmod(d->wall_x_cord, 1.0))
			* data->pic.w_texture.texture->width;
		d->pixel_step_y = data->pic.w_texture.texture->height
			/ (double)d->wall_heigth;
		d->texture = data->pic.w_texture.texture;
	}
}
