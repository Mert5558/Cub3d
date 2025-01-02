/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disilva <disilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:53:35 by diogofms          #+#    #+#             */
/*   Updated: 2024/12/31 21:09:47 by disilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mlx_error(t_game data)
{
	if (data.mlx == 0)
	{
		perror("ERROR\nfailure to set up graphical environment\n");
		exit (1);
	}
}

void	ft_img_error(t_game data)
{
	if (data.img == 0)
	{
		mlx_close_window(data.mlx);
		perror("ERROR\nfailure to create image\n");
		exit (1);
	}
}
