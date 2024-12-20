/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beninging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:35 by amecani           #+#    #+#             */
/*   Updated: 2024/12/20 12:31:23 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	gathering_addition_data(t_exec *exec_data)
{
	putting_wasll_manuanylly(exec_data);
	exec_data->floor_colour = get_rgba(127,127,127, 255);
	exec_data->celeing_colour = get_rgba(0,127,127, 255);
	// watchu_lookin_at_mane()//  * Add 
}

void	excecution(void)
{
	t_exec	exec_data;

	ft_bzero(&exec_data, sizeof(t_exec)); //* If Failed, Stop Return Error Msg
	exec_data.window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!exec_data.window)
	{
		printf("mlx_init initiliasation error\n");
		free (&exec_data);
		return;
	}

	// Single Ran / Non-Loops
	gathering_addition_data(&exec_data);

	// Loops
	loops_in_here(&exec_data);
}
