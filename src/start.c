/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:39:18 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/06 19:54:18 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	mlx_vars	mlx_vars;
	t_data		img;

	mlx_vars.mlx = mlx_init();//return a void * which holds the location of our current MLX instance
	mlx_vars.win = mlx_new_window(mlx_vars.mlx, 1920, 1080, "fractol");
	img.img = mlx_new_image(mlx_vars.mlx, 1920, 1080); //return a pointer to the window just created
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, RED);
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.win, img.img, 0, 0);
	mlx_hook(mlx_vars.win, ON_KEYDOWN, 1L<<0, close_program, &mlx_vars);
	mlx_loop(mlx_vars.mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_program(int keycode, mlx_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (1);
	}
	return (1);
}