/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beninging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:35 by amecani           #+#    #+#             */
/*   Updated: 2024/12/15 15:24:15 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


t_exec	*gathering_addition_data(t_exec *info)
{
	putting_wasll_manuanylly(exec_data);
	int floor_color = get_rgba(127,127,127, 255); //Store these two in a struct
	int celing_color = get_rgba(0,127,127, 255);
	paint_floor_and_celing(window, floor_color, celing_color);
	watchu_lookin_at_mane()//  * Add 
	
}
void execution(void)
{
	t_exec	*exec_data	= ft_bzero(exec_data, sizeof(exec_data));
	mlx_t	*window		= mlx_init(WIDTH, HEIGHT, "Cub3D", true); //! Add later, potential error

	// Single Ran / Non-Loops
	exec_data = gathering_addition_data();

	// Loops
	loops_in_here(window);
}