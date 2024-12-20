/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:30:12 by amecani           #+#    #+#             */
/*   Updated: 2024/12/20 12:34:19 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void loopin(void *param)
{
	t_exec	*exe;

	exe = (t_exec *)param;
	paint_floor_and_celing(exe->window,exe->celeing_colour, exe->floor_colour);
	if (mlx_is_key_down(exe->window, MLX_KEY_ESCAPE))
	{
		//* Free all other stuff (later)
		mlx_terminate(exe->window);
		exit(0);
	}

}

void loops_in_here(t_exec *execut)
{
	mlx_loop_hook(execut->window, loopin, execut);
	mlx_loop(execut->window);
}
