/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:15:47 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 03:41:59 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	lcg_random(t_fern *fern)
{
	long long	a;
	long long	c;
	long long	m;

	a = 16625;
	c = 1013223;
	m = 4297296;
	fern->seed = (a * fern->seed + c) % m;
	return ((double)fern->seed / (double)m);
}
