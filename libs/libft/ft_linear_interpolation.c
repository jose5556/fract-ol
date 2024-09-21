/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_interpolation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:50:56 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/21 08:01:07 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*linear_interpolation(t_interpolation_vars *vars)
{
	return ((vars->maxallowed - vars->minallowed)
		* (vars->unscalednum - vars->min) / (vars->max - vars->min)
		+ vars->minallowed);
}
