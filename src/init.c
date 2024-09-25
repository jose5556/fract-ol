/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:10:11 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/25 11:34:35 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	malloc_error()
{
	ft_printf("%s", "error in some memory allocation, freeing all vars and aborting program");
	exit (EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->hypotenuse = 4;
	fractal->fractal_iterations = 100;
}

void    fractal_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		malloc_error();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img.img == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data_init(&data->fractal);
}
