/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:03 by joseoliv          #+#    #+#             */
/*   Updated: 2024/09/25 13:36:06 by joseoliv         ###   ########.fr       */
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
# define ERROR_MESSAGE "Wrong name or wrong format, please enter the name of your desired fractal first. If it is the julia set you want, don't forget to include their respective x and y coordinates.\n"
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct	s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
typedef struct	s_fractal
{
	double	hypotenuse;
	int		fractal_iterations;
}	t_fractal;
typedef struct	s_data
{
	void		*mlx;
	void		*win;
	char		*name;
	t_img		img;
	t_fractal	fractal;
}	t_data;
typedef struct s_complex 
{
	double	x;
	double	y;
}	t_complex;
double		linear_interpolation(double minAllowed, double maxAllowed, double unscaledNum, double max);
void    	fractal_init(t_data *data);
void		handel_pixel(int x, int y, t_data *data);
void		render_fractal(t_data *data);
void		my_mlx_pixel_put(t_img *vars, int x, int y, int color);
void		data_init(t_fractal *fractal);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);
void		handle_hooks(t_data *data);
int			close_program(int keycode, t_data *data);
int			handle_close(t_data *data);

#endif