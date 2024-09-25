/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:41:55 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/25 13:56:04 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char *argv[])
{
	t_data	data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		data.name = argv[1];
		fractal_init(&data);
        render_fractal(&data);
		handle_hooks(&data);
        mlx_loop(data.mlx);
		mlx_loop_hook(data.mlx, render_fractal, &data);
	}
	else
	{
		ft_printf("%s", ERROR_MESSAGE);
		exit (EXIT_FAILURE);
	}
}
