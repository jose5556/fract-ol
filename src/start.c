/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:39:18 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/02 17:53:36 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	ft_printf("%s", "ola");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world");
	if (mlx_win == NULL)
		return (1);
	mlx_loop(mlx);
}
