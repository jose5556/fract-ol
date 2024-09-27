/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:18 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/27 17:17:26 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	hooks_listener(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, 
		handle_keys, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, 
		close_program, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask,
		handle_mouse, data);
	return (0);
}
 
int	handle_keys(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_program(data);
	if (keycode == XK_Left)
		data->fractal.shift_x -= (0.2 * data->fractal.zoom);
	if (keycode == XK_Right)
		data->fractal.shift_x += (0.2 * data->fractal.zoom);
	if (keycode == XK_Up)
		data->fractal.shift_y += (0.2 * data->fractal.zoom);
	if (keycode == XK_Down)
		data->fractal.shift_y -= (0.2 * data->fractal.zoom);
 	if (keycode == XK_plus)
		data->fractal.fractal_iterations += 5;
	if (keycode == XK_minus)
		data->fractal.fractal_iterations += 5;
	render_fractal(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		data->fractal.zoom *= 0.95;
		data->fractal.fractal_iterations += 2;
	}
	else if (button == 5)
		data->fractal.zoom *= 1.05;
	render_fractal(data);
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
