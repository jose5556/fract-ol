/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:47:35 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/21 11:25:34 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handel_pixel(int x, int y)
{
	t_complex   a;
    t_complex   b;
    double      temp;

	a.x = 0;
    a.y = 0;
	b.x = linear_interpolation(-2, 2, x, WIDTH);
	b.y = linear_interpolation(2, -2, y, HEIGHT);

	while(1)
	{
		temp = (a.x * a.x) - (a.y * a.y);
        a.y = 2 * a.x * a.y;
        a.x = temp;
        
        a.x += b.x;
        a.y += b.y;
	}
}

void	render_window(t_complex complex)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= HEIGHT)
	{
		while (y <= WIDTH)
		{
			handel_pixel(x, y);
			y++;
		}
		x++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->imgs.addr + (y * data->imgs.line_length + x
			* (data->imgs.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
