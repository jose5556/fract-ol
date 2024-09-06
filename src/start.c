/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:39:18 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/06 22:16:01 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	t_data		data;

	data.vars.mlx = mlx_init(); //return a void * which holds the location of our current MLX instance
	if (data.vars.mlx == NULL)
		exit (0);
	data.vars.win = mlx_new_window(data.vars.mlx, 1920, 1080, "fractol");
	//data.imgs.img = mlx_new_image(data.vars.mlx, 1920, 1080); //return a pointer to the window just created
	//data.imgs.addr = mlx_get_data_addr(data.imgs.img, &data.imgs.bits_per_pixel,
	//	&data.imgs.line_length, &data.imgs.endian);
	//my_mlx_pixel_put(&data, 5, 5, RED);
	//mlx_put_image_to_window(data.vars.mlx, data.vars.win, data.imgs.img, 0, 0);
	//mlx_hook(data.vars.win, ON_KEYDOWN, 1L<<0, &close_program, &data.vars);
	mlx_loop(data.vars.mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->imgs.addr + (y * data->imgs.line_length + x * (data->imgs.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_program(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(data->vars.mlx, data->imgs.img);
		mlx_destroy_window(data->vars.mlx, data->vars.win);
		mlx_destroy_display(data->vars.mlx);
		free(data->vars.mlx);
		exit (0);
	}
	return (1);
}
