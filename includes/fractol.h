/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:03 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/06 19:53:50 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <X11/keysym.h>
# include <unistd.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum {
	RED = 0x00FF0000,
};
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}  t_data;
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	mlx_vars;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_program(int keycode, mlx_vars *vars);

#endif