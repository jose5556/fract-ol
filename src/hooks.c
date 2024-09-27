/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:18 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/27 13:04:59 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	hooks_listener(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, 
		handle_hooks, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, 
		close_program, data);
}
 
int	handle_hooks(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_program(data);
	if (keycode == XK_Left)
		data->fractal.shift_x += 0.5;
	if (keycode == XK_Right)
		data->fractal.shift_x -= 0.5;
	if (keycode == XK_Up)
		data->fractal.shift_y -= 0.5;
	if (keycode == XK_Down)
		data->fractal.shift_y += 0.5;
 	if (keycode == XK_plus)
		data->fractal.fractal_iterations += 10;
	if (keycode == XK_minus)
		data->fractal.fractal_iterations -= 10;
	render_fractal(data);
	return (0);
}

int	close_program(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (EXIT_SUCCESS);
	return (1);
}
