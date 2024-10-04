/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley_fern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:52:48 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/04 18:50:34 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdint.h> // Include this for uint32_t type

/* unsigned long seed = 56; // Initial seed

double lcg_random(long seed) {
	// Parameters for the LCG
	const long long a = 1664525;    // Multiplier
	const long long c = 1013904223; // Increment
	const long long m = 4294967296;  // 2^32

	seed = (a * seed + c) % m;
	return (double)seed / (double)m;
} */


void render_fern(t_data *data) {
	t_complex	a;
	t_complex	b;
	int 		i;
	double		random;
	int			color;

	i = -1;
	a.x = 0;
	a.y = 0;
	data->fractal.fern.seed = 3;
	while (i++ < FERN_ITERATIONS) 
	{
		random = lcg_random(&data->fractal.fern);
		if (random < 0.01) {
			b.x = 0;
			b.y = 0.16 * a.y;
			color = (int)(0x00FF00 * (a.y / 1.0));
		} else if (random < 0.86) {
			b.x = 0.85 * a.x + 0.04 * a.y;
			b.y = -0.04 * a.x + 0.85 * a.y + 1.6;
			color = (int)(0xFFFF00 * ((a.y - 1.0) / 1.0));
		} else if (random < 0.93) {
			b.x = 0.2 * a.x - 0.26 * a.y;
			b.y = 0.23 * a.x + 0.22 * a.y + 1.6;
			color = (int)(0xFFAA00 * ((a.y - 2.0) / 1.0));
		} else {
			b.x = -0.15 * a.x + 0.28 * a.y;
			b.y = 0.26 * a.x + 0.24 * a.y + 0.44;
			color = 0xFF0000;
		}
		a.x = b.x;
		a.y = b.y;

		int px = (int)((a.x + 2.5) * (WIDTH / 5));
		int py = (int)((HEIGHT - (a.y * 75)));
		if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
			my_mlx_pixel_put(&data->img, px, py, color);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}


