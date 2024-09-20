/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 04:47:04 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/20 06:29:23 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(void)
{
    t_complex   a;
    t_complex   b;
    double      temp;
    int         j;

    j = 0;
    a.x = 0;
    a.y = 0;
    b.x = 0.25;
    b.y = 0.4;
    
    while (j++ != 10)
    {
        temp = (a.x * a.x) - (a.y * a.y);
        a.y = 2 * a.x * a.y;
        a.x = temp;
        
        a.x += b.x;
        a.y += b.y;
        printf("%f %f\n", a.x, a.y);
    }
}