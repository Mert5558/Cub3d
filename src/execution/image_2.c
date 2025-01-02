/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:30:13 by disilva           #+#    #+#             */
/*   Updated: 2025/01/02 16:34:58 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	wall_size(t_draw_column *d)
{
	d->wall_top = -d->wall_heigth / 2 + WINDOW_LENGTH / 2;
	d->wall_bottom = d->wall_heigth / 2 + WINDOW_LENGTH / 2;
	if (d->wall_bottom < WINDOW_LENGTH)
	{
		d->y_cord = d->wall_bottom - 1;
		d->wall_y_cord = d->texture->height - 1;
	}
	else
	{
		d->y_cord = WINDOW_LENGTH - 1;
		d->wall_y_cord = d->texture->height
			- ((d->wall_bottom - WINDOW_LENGTH) * d->pixel_step_y) - 1;
		d->wall_top = 0;
	}
}

void	draw_column(t_game *data, int x_cord)
{
	t_draw_column	d;

	d.wall_heigth = (int)(WINDOW_LENGTH / data->image_info.wall_distance);
	if (data->ray_info.horizontal_wall == 1)
		draw_horizontal(data, &d);
	else
		draw_vertical(data, &d);
	wall_size(&d);
	while (d.y_cord >= d.wall_top)
	{
		((int *)data->img->pixels)[(d.y_cord * WINDOW_WIDTH) + x_cord]
			= texture_pixel_color(d.wall_x_cord, d.wall_y_cord, d.texture);
		d.wall_y_cord -= d.pixel_step_y;
		d.y_cord--;
	}
}

int	texture_pixel_color(double x, double y, mlx_texture_t *texture)
{
	int	color;
	int	red;
	int	green;
	int	blue;
	int	a;

	x = (int)(x) % texture->width;
	y = (int)(y) % texture->height;
	red = texture->pixels[((int)y * texture->width + (int)x) * 4 + 3];
	green = texture->pixels[((int)y * texture->width + (int)x) * 4 + 2];
	blue = texture->pixels[((int)y * texture->width + (int)x) * 4 + 1];
	a = texture->pixels[((int)y * texture->width + (int)x) * 4];
	color = red << 24 | green << 16 | blue << 8 | a;
	return (color);
}
