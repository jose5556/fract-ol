/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:10:11 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/03 17:34:01 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	populate_color_lst(fractal);
}

void	populate_color_lst(t_fractal *fractal)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*n4;

	n1 = (t_list *)calloc(1, sizeof(t_list));
	n2 = (t_list *)calloc(1, sizeof(t_list));
	n3 = (t_list *)calloc(1, sizeof(t_list));
	n4 = (t_list *)calloc(1, sizeof(t_list));
	fractal->lst.content = BLACK;
	fractal->lst.next = n1;
	n1->content = WHITE;
	n1->next = n2;
	n2->content = RED;
	n2->next = n3;
	n3->content = PURPLE;
	n3->next = n4;
	n4->content = DARK_BLUE;
	n4->next = NULL;
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
