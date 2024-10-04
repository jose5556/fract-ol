/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:47:35 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/04 14:30:50 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_mandelbrot(t_complex *a, t_complex *b, t_data *data)
{
	if (!ft_strncmp(data->name, "julia", 5))
	{
		b->x = data->fractal.julia_x;
		b->y = data->fractal.julia_y;
	}
	else
	{
		b->x = a->x;
		b->y = a->y;
	}
}

int	handle_color(t_fractal *fractal, int color, int i)
{
	if (fractal->color3)
		color = smooth_color_interpolation(fractal->color1,
				fractal->color2, i,
				fractal->fractal_iterations);
	else
		color = linear_interpolation(fractal->color1,
				fractal->color2, i,
				fractal->fractal_iterations);
	return (color);
}

void	handel_pixel(int x, int y, t_data *data)
{
	t_complex	a;
	t_complex	b;
	int			i;
	int			color;

	i = 0;
	color = 0;
	a.x = (linear_interpolation(-2, 2, x, WIDTH) * data->fractal.zoom)
		+ data->fractal.shift_x;
	a.y = (linear_interpolation(2, -2, y, HEIGHT) * data->fractal.zoom)
		+ data->fractal.shift_y;
	julia_mandelbrot(&a, &b, data);
	while (i++ < data->fractal.fractal_iterations)
	{
		a = sum_complex(square_complex(a), b);
		if ((a.x * a.x) + (a.y * a.y) > data->fractal.hypotenuse)
		{
			color = handle_color(&data->fractal, color, i);
			my_mlx_pixel_put(&data->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&data->img, x, y, data->fractal.lst.content);
}

int	render_fractal(void *param)
{
	int		x;
	int		y;
	t_data	*data;

	data = (t_data *) param;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handel_pixel(x, y, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (1);
}

void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
