/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:47:35 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/25 11:36:49 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handel_pixel(int x, int y, t_data *data)
{
	t_complex   a;
    t_complex   b;
	int			i;
	int			color;

	i = -1;
	a.x = 0;
    a.y = 0;
	b.x = linear_interpolation(-2, 2, x, WIDTH);
	b.y = linear_interpolation(2, -2, y, HEIGHT);
	while(++i < data->fractal.fractal_iterations)
	{
		a = sum_complex(square_complex(a), b);
		if ((a.x * a.x) + (a.y * a.y) > data->fractal.hypotenuse)
		{
			color = linear_interpolation(BLACK, WHITE, i, data->fractal.fractal_iterations);
			my_mlx_pixel_put(&data->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&data->img, x, y, PSYCHEDELIC_PURPLE);
}

void	render_fractal(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= HEIGHT)
	{
		x = -1;
		while (++x <= WIDTH)
			handel_pixel(x, y, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	my_mlx_pixel_put(t_img *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x
			* (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
