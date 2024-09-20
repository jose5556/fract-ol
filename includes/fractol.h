/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:03 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/20 08:17:22 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define HEIGHT	800
# define WIDTH	800
# define ERROR_MESSAGE "Wrong name or wrong format, please enter the name of your desired fractal first. If it is the julia set you want, don't forget to include their respective x and y.\n"
enum {
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF,
};
typedef struct	s_vars_mlx {
	void	*mlx;
	void	*win;
	char	*name;
}	t_vars_mlx;
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
typedef struct	s_data {
	t_vars_mlx	vars;
	t_img		imgs;
}  t_data;
typedef struct s_complex {
	double	x;
	double	y;
}	t_complex;

void    fractal_init(t_data *data);

#endif