/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:41:55 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/21 08:29:17 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char *argv[])
{
	t_data		data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		data.vars.name = argv[1];
		fractal_init(&data);
        //fractal_render(&data);
        mlx_loop(data.vars.mlx);		
	}
	else
	{
		ft_printf("%s", ERROR_MESSAGE);
		exit (EXIT_FAILURE);
	}
}