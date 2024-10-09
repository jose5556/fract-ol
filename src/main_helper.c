/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:53:13 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 05:45:01 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_julia_handler(t_data *data, char *name)
{
	data->name = name;
	fractal_init(data);
	render_fractal(data);
	hooks_listener(data);
	mlx_loop_hook(data->mlx, render_fractal, data);
	mlx_loop(data->mlx);
}

void	fern_handler(t_data *data, char *name)
{
	data->name = name;
	data->fractal.fern.swap_color = 1;
	fractal_init(data);
	render_fern(data);
	hooks_listener_bonus(data);
	mlx_loop_hook(data->mlx, render_fern, data);
	mlx_loop(data->mlx);
}
