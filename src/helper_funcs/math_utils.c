/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:13:15 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/04 14:35:17 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	linear_interpolation(double minAllowed, double maxAllowed,
	double unscaledNum, double max)
{
	return ((maxAllowed - minAllowed)
		* (unscaledNum - 0) / (max - 0)
		+ minAllowed);
}

int smooth_color_interpolation(int color1, int color2, int i, int max_iterations)
{
    double t;
    int r, g, b;

    t = (double)i / max_iterations;
    t = t * t * (3.0 - 2.0 * t);

    r = ((color1 >> 16) & 0xFF) + (((color2 >> 16) & 0xFF)
		- ((color1 >> 16) & 0xFF)) * t;
    g = ((color1 >> 8) & 0xFF) + (((color2 >> 8) & 0xFF)
		- ((color1 >> 8) & 0xFF)) * t;
    b = (color1 & 0xFF) + (((color2 & 0xFF)
		- (color1 & 0xFF)) * t);

    return ((r << 16) | (g << 8) | b);
}


t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	ft_atoi_double(const char *nptr)
{
	long	result;
	double	sign;
	double	pow;
	double	fractional_part;

	fractional_part = 0;
	result = 0;
	sign = 1;
	pow = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		result = (result * 10) + (*nptr++ - '0');
	if (*nptr == '.')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		pow /= 10;
		fractional_part = fractional_part + (*nptr++ - '0') * pow;
	}
	return ((result + fractional_part) * sign);
}
