/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:10:11 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 04:11:19 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->hypotenuse = 4;
	fractal->fractal_iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color1 = DARK_BLUE;
	fractal->color2 = RED;
	fractal->color3 = 1;
	fractal->fern.seed = 3;
	populate_color_lst(fractal);
}

void	populate_color_lst(t_fractal *fractal)
{
	t_list	*colorlst;

	colorlst = ft_newlst(BLACK);
	ft_lstadd_back(&colorlst, WHITE);
	ft_lstadd_back(&colorlst, DARK_GREEN);
	ft_lstadd_back(&colorlst, PURPLE);
	ft_lstadd_back(&colorlst, DARK_BLUE);
	fractal->lst = colorlst;
}

void	fractal_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit (EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit (EXIT_FAILURE);
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img.img == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit (EXIT_FAILURE);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data_init(&data->fractal);
}
