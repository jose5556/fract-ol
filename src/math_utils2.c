/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:15:47 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/04 15:29:02 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double lcg_random() {
	unsigned long long seed = 6;
	const unsigned long long a = 1664525;  // Multiplier
	const unsigned long long c = 1013904223;  // Increment
	const unsigned long long m = (1ULL << 32);  // 2^32 modulus
    seed = (a * seed + c) % m;  // Update the seed
    return (double)seed / (double)m;  // Normalize to [0, 1)
}
