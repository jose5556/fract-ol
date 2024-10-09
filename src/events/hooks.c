/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:18 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 06:32:02 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	hooks_listener(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask,
		handle_keys, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask,
		handle_colors, data);
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
	if (keycode == XK_KP_Add)
		data->fractal.fractal_iterations += 5;
	if (keycode == XK_KP_Subtract)
		data->fractal.fractal_iterations -= 5;
	if (keycode == XK_space)
		data->fractal.lst = data->fractal.lst->next;
	return (0);
}

int	handle_colors(int keycode, t_data *data)
{
	if (keycode == XK_1)
		data->fractal.color1 = DARK_BLUE;
	if (keycode == XK_2)
		data->fractal.color1 = PURPLE;
	if (keycode == XK_3)
		data->fractal.color1 = BLACK;
	if (keycode == XK_4)
		data->fractal.color1 = DARK_GREEN;
	if (keycode == XK_5)
		data->fractal.color1 = RED;
	if (keycode == XK_6)
		data->fractal.color2 = RED;
	if (keycode == XK_7)
		data->fractal.color2 = WHITE;
	if (keycode == XK_8)
		data->fractal.color2 = DARK_GREEN;
	if (keycode == XK_9)
		data->fractal.color2 = PURPLE;
	if (keycode == XK_0)
		data->fractal.color2 = DARK_BLUE;
	if (keycode == XK_minus)
		data->fractal.color3 = 0;
	if (keycode == XK_equal)
		data->fractal.color3 = 1;
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == 4)
	{
		data->fractal.zoom *= 0.95;
		data->fractal.fractal_iterations += 1;
	}
	else if (button == 5)
		data->fractal.zoom *= 1.05;
	return (0);
}
