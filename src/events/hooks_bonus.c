/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:52:12 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/08 04:11:08 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	hooks_listener_bonus(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask,
		handle_keys_bonus, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask,
		close_program, data);
	return (0);
}

int	handle_keys_bonus(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_program(data);
	if (keycode == XK_1)
		data->fractal.fern.swap_color = 1;
	if (keycode == XK_2)
		data->fractal.fern.swap_color = 2;
	if (keycode == XK_3)
		data->fractal.fern.swap_color = 3;
	return (0);
}
