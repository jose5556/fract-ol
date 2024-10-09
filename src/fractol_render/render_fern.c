/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:52:48 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 02:09:48 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	render_fern(t_data *data) 
{
	t_complex	a;
	t_complex	b;
	int 		i;
	double		random;
	int			px;
	int			py;

	i = -1;
	a.x = 0;
	a.y = 0;
	data->fractal.fern.seed = 3;
	while (i++ < FERN_ITERATIONS)
	{
		random = lcg_random(&data->fractal.fern);
		b = handle_random(random, a, b, data);
		a.x = b.x;
		a.y = b.y;
		px = (int)((a.x + 2.5) * (WIDTH / 5));
		py = (int)((HEIGHT - (a.y * 75)));
		if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
			my_mlx_pixel_put(&data->img, px, py, data->fractal.fern.color);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

t_complex	handle_random(double random, t_complex a, t_complex b, t_data *data)
{
	int	i;
	if (random < 0.01)
	{
		i = 1;
		b.x = 0;
		b.y = 0.16 * a.y;
	}
	else if (random < 0.86)
	{
		i = 2;
		b.x = 0.85 * a.x + 0.04 * a.y;
		b.y = -0.04 * a.x + 0.85 * a.y + 1.6;
	}
	else if (random < 0.93)
	{
		i = 3;
		b.x = 0.2 * a.x - 0.26 * a.y;
		b.y = 0.23 * a.x + 0.22 * a.y + 1.6;
	}
	else
	{
		i = 4;
		b.x = -0.15 * a.x + 0.28 * a.y;
		b.y = 0.26 * a.x + 0.24 * a.y + 0.44;
	}
	chose_color(i, &data->fractal.fern);
	return (b);
}

void	chose_color(int i, t_fern *fern)
{
	if (fern->swap_color == 2)
	{
		if (i == 1)
			fern->color = GREEN;
		else if (i == 2)
			fern->color = GREEN_PLUS;
		else if (i == 3)
			fern->color = MEDIUM_GREEN;
		else if (i == 4)
			fern->color = DARK_GREEN;
	}
	else if (fern->swap_color == 3)
	{
		if (i == 1)
			fern->color = NEON_PINK;
		else if (i == 2)
			fern->color = CYAN_BLUE;
		else if (i == 3)
			fern->color = ELECTRIC_VIOLET;
		else if (i == 4)
			fern->color = LIME_GREEN;
	}
	else
		fern->color = GREEN;
}
