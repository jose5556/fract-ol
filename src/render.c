/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:47:35 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/27 17:16:03 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int  smooth_color_interpolation(int color1, int color2, int i, int max_iterations)
{
    double  t;
    
    t = (double)i / max_iterations;
    t = t * t * (3.0 - 2.0 * t);
    int r = ((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF - (color1 >> 16) & 0xFF) * t;
    int g = ((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF - (color1 >> 8) & 0xFF) * t;
    int b = (color1 & 0xFF) + (color2 & 0xFF - color1 & 0xFF) * t;
    return ((r << 16) | (g << 8) | b);
}

void handel_pixel(int x, int y, t_data *data)
{
    t_complex a;
    t_complex b;
    int i;
    int color;

    i = -1;
    a.x = 0;
    a.y = 0;
    b.x = (linear_interpolation(-2, 2, x, WIDTH) * data->fractal.zoom) + data->fractal.shift_x;
    b.y = (linear_interpolation(2, -2, y, HEIGHT) * data->fractal.zoom) + data->fractal.shift_y;

    while (++i < data->fractal.fractal_iterations)
    {
        a = sum_complex(square_complex(a), b);
        if ((a.x * a.x) + (a.y * a.y) > data->fractal.hypotenuse)
        {
            color = smooth_color_interpolation(DARK_BLUE, WHITE, i, data->fractal.fractal_iterations);
            my_mlx_pixel_put(&data->img, x, y, color);
            return ;
        }
    }
    my_mlx_pixel_put(&data->img, x, y, WHITE);
}

void	render_fractal(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handel_pixel(x, y, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
