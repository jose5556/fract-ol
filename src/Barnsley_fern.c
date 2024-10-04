/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Barnsley_fern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:52:48 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/04 15:57:16 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#define NUM_POINTS 1000000

void	render_fern()
{
	t_complex	a;
	t_complex	b;
    int			i;

	i = 0;
	a.x = 0;
	a.y = 0;
	while (i < NUM_POINTS)
    {
        double rand_num = rand() / (double)RAND_MAX;

        if (rand_num < 0.01) { // F0
            double x_new = 0;
            double y_new = 0.16 * a.y;
            a.x = x_new;
            a.y = y_new;
        } else if (rand_num < 0.86) { // F1
            double x_new = 0.85 * a.x + 0.04 * a.y;
            double y_new = -0.04 * a.x + 0.85 * a.y + 1.6;
            a.x = x_new;
            a.y = y_new;
        } else if (rand_num < 0.93) { // F2
            double x_new = 0.2 * a.x - 0.26 * a.y;
            double y_new = 0.23 * x + 0.22 * y + 1.6;
            x = x_new;
            y = y_new;
        } else { // F3
            double x_new = -0.15 * x + 0.28 * y;
            double y_new = 0.26 * x + 0.24 * y + 0.44;
            x = x_new;
            y = y_new;
        }

        // Scale the points to fit the image dimensions
        int px = (int)((x + 2.5) * (WIDTH / 5));
        int py = (int)((HEIGHT - (y * 50 + 5)) * (HEIGHT / 12)); // Adjust scaling

        // Plot the point in the image
        if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
            image[(py * WIDTH + px) * 3 + 0] = 0; // Red
            image[(py * WIDTH + px) * 3 + 1] = 255; // Green
            image[(py * WIDTH + px) * 3 + 2] = 0; // Blue
        }
    }
}
