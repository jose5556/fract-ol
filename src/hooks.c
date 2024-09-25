/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:18 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/25 13:37:08 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, 
		close_program, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, 
		handle_close, data);
}

int	close_program(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		handle_close(data);
	return (1);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (EXIT_SUCCESS);
	return (1);
}
