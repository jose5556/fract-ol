/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:41:55 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/08 04:27:31 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot_julia_handler(&data, argv[1]);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		data.fractal.julia_x = ft_atoi_double(argv[2]);
		data.fractal.julia_y = ft_atoi_double(argv[3]);
		mandelbrot_julia_handler(&data, argv[1]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "fern", 4))
	{
		
		fern_handler(&data, argv[1]);
	}
	else
	{
		ft_printf("%s", ERROR_MESSAGE);
		exit (EXIT_FAILURE);
	}
}
