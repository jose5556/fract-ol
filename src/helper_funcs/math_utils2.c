/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:15:47 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 02:10:11 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	lcg_random(t_fern *fern) 
{
	const unsigned long long a = 16625;  // Multiplier
	const unsigned long long c = 1013223;  // Increment
	const unsigned long long m = 4297296;  // 2^32 modulus
    fern->seed = (a * fern->seed + c) % m;
    return (double)fern->seed / (double)m;
}
