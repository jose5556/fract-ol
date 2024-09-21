/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:10:11 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/21 07:47:20 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	malloc_error()
{
	ft_printf("%s", "error in some memory allocation, freeing all vars and aborting program");
	exit (EXIT_FAILURE);
}

void    fractal_init(t_data *data)
{
	data->vars.mlx = mlx_init();
	if (data->vars.mlx == NULL)
		malloc_error();
	data->vars.win = mlx_new_window(data->vars.mlx, HEIGHT, WIDTH, data->vars.name);
	if (data->vars.win == NULL)
	{
		mlx_destroy_display(data->vars.mlx);
		free(data->vars.mlx);
		malloc_error();
	}
	data->imgs.img = mlx_new_image(data->vars.mlx, HEIGHT, WIDTH);
	if (data->imgs.img == NULL)
	{
		mlx_destroy_window(data->vars.mlx, data->vars.win);
		mlx_destroy_display(data->vars.mlx);
		free(data->vars.mlx);
		malloc_error();
	}
	data->imgs.addr = mlx_get_data_addr(data->imgs.img, &data->imgs.bits_per_pixel,
			&data->imgs.line_length, &data->imgs.endian);
}
