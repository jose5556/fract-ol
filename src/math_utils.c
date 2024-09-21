/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:13:15 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/21 10:38:38 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	linear_interpolation(int minAllowed, int maxAllowed, int unscaledNum, int max) 
{
  return (maxAllowed - minAllowed) 
  		* (unscaledNum - 0) / (max - 0) 
		+ minAllowed;
}

int	main(void)
{
	int	i = -1;

	while (++i <= 800)
	{
		printf("%d -> %f\n", linear_interpolation(-2, 2, i, HEIGHT));
	}
}